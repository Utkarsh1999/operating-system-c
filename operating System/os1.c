#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int able;
int main()
{
	able = 1;
void fork_example()
{
	printf("fork number = %d \n",++able);
	pid_t pid;
	pid  = fork();

	int a = 5;
	if(pid<0)
	{
		printf("error occured\n");
	}
	else if(pid==0)
	{
		printf("%d\n", getpid());
		printf("child is executed x = %d \n", a +5);
	}
	else
	{
		printf("%d\n",getpid());
		printf("parent has x = %d \n",a-5);
	}
	
}


	fork_example();
	fork_example();
	fork_example();

	return 0;
}


