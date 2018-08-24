#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define READ_END 0
#define WRITE_END 1

#define BUFFER_SIZE 128

#define FILE_LOCATION "/home/nidhi/Mayank/FILE.txt" 

int main()
{
	char write_str[]=FILE_LOCATION;
	char read_str[]="";
	int fd[2];
	pid_t pid;	
	
	if(pipe(fd)==-1)
	{
		printf("PIPE CAN'T BE CREATED\n");
		return;
	}

	pid=fork();

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
		printf("**FILE LOCATION = %s **\n",read_str);
		close(fd[READ_END]);	
		
				//FILE READING
		FILE *fp;
		fp=fopen(read_str,"r");
		char ch=fgetc(fp);
		while(ch!='\n')
		{
			printf("%c",ch);
			ch=fgetc(fp);
		}
		printf("\n");
		fclose(fp);
	}
	return 0;
}
