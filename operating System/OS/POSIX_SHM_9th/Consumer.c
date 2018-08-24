#include<stdio.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<fcntl.h>

#define SIZE 1024

int main()
{
	char *name="firstSHM";

	int shm_fd = shm_open(name,O_CREAT|O_RDWR,0666);
	
	void *shm_ptr = mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,shm_fd,0);

	printf("FILE CONTENT : %s",(char*)shm_ptr);	
	
	shm_unlink(name);

	return 0;
}
