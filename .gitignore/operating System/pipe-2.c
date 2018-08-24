include<sys/types.h>
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

    if(pipe(fd)==-1)
    {
        printf("pipe failed");
        return 1;
    }

    pid=fork();

        if(pid<0)
        {
            printf("child is writing \n\n");
            close(fd[READ_END]);

            write(fd[WRITE_END] , write_msg , strlen(write_msg)+1);

            close(fd[WRITE_END]);

            wait();

            printf("child is reading \n\n");

            close(fd[WRITE_END]);

            read(fd[READ_END], read_msg ,BUFFER_SIZE);

            close(fd[READ_END]);


        }
        else if
        {
            printf("parent is reading\n\n");

            close(fd[WRITE_END]);

            read(fd[READ_END] , read_msg , BUFFER_SIZE);

            close(fd[READ_END]);

            wait();

            printf("parent is writing \n\n");

            close(fd[READ_END]);

            write(fd[WRITE_END], write_msg ,strlen(write_msg)+1);

            close(fd[WRITE_END]);
        }

        else{
            printf("something went wrong \n\n");
        }

        return 0;

}
