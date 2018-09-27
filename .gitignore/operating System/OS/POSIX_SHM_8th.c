#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>

#define SIZE 512

int main()
{
	
	char *str="utkarsh";

	int shm_id=shmget(IPC_PRIVATE,SIZE,S_IRUSR|S_IWUSR);	// CREATE A SHM

	char *shm_ptr=(char*)shmat(shm_id,NULL,0);		// ATTACH IT TO THE PROCESS

	sprintf(shm_ptr,"%s",str);

	printf("STRING READED : %s\n",shm_ptr);

	shmdt(shm_ptr);						// DETACH IT FROM THE PROCESS

	shmctl(shm_id,IPC_RMID,NULL);				// DELETES SHM
	
	return 0;
}
