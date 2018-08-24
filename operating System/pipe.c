#include<sys/types.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main()
{
    char write_msg[BUFFER_SIZE]="hello frnss chai peelo";
    char read_msg[BUFFER_SIZE];
	
    int fd[2];
    pid_t pid;
    int i;

    if(pipe(fd) == -1)
    {
        printf("pipe failed");
        return 1;
    }

    pid=fork();

        if(pid==0)
        {
           //child area
		wait();
		printf("\nchild is reading\n"); 
		close(fd[WRITE_END]);
		read(fd[READ_END],read_msg,strlen(write_msg)+1);
		printf("%s",read_msg);		
		close(fd[READ_END]);        
	}
        else if(pid>0)
	{//32

            //parent area 
		printf("\nparent is writting\n");       
		close(fd[READ_END]);
		write(fd[WRITE_END],write_msg,(strlen(write_msg)+1));
		close(fd[WRITE_END]);
	}
        else{
            printf("\n\nsomething went wrong ");
        }

        return 0;

}
