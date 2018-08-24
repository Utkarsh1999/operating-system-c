#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define READ_END 0
#define WRITE_END 1

#define BUFFER_SIZE 128

int main()
{
	char write_str[]="Mayank Dua";
	char read_str[]="";

	int fd[2];

	if(pipe(fd)==-1)
	{
		printf("PIPE CAN'T BE CREATED\n");
		return;
	}

	pid_t pid=fork();

	if(pid<0)
	{
		printf("CHILD PROCESS CAN'T BE CREATED\n");
		return;
	}
	else if(pid==0)		//CHILD CONTEXT
	{
		close(fd[READ_END]);
		write(fd[WRITE_END],write_str,strlen(write_str)+1);
		close(fd[WRITE_END]);
	}
	else			//PARENT CONTEXT
	{
		wait(NULL);
		close(fd[WRITE_END]);
		read(fd[READ_END],read_str,BUFFER_SIZE);
		printf("STRING READED : %s\n",read_str);
		close(fd[READ_END]);
	}
	return 0;
}
