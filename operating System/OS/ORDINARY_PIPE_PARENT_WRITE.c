#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define READ_END 0
#define WRITE_END 1

#define BUFFER_SIZE 128

int main()
{
	int fd[2];
	pid_t pid;

	char write_str[]="Mayank Dua";
	char read_str[]="";

	if(pipe(fd)==-1)
	{
		printf("UNABLE TO CREATE A PIPE\n");
		return;
	}
	
	pid=fork();
	if(pid<0)
	{
		printf("UNABLE TO CREATE A CHILD PROCESS\n");
		return;
	}
	else if(pid==0)
	{		//CHILD CONTEXT
		printf("IN CHILD CONTEXT\n");
		close(fd[WRITE_END]);
		read(fd[READ_END],read_str,BUFFER_SIZE);
		printf("STRING READED : %s\n",read_str);
		close(fd[READ_END]);
		
	}
	else
	{		//PARENT CONTEXT
		printf("IN PARENT CONTEXT\n");
		close(fd[READ_END]);
		write(fd[WRITE_END],write_str,strlen(write_str)+1);
		close(fd[WRITE_END]);
	}
	return 0;
}
