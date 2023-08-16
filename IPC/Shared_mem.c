#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
    void* shared_memory;
    char buff[100];
    int shmid,id;
    pid_t p;

    shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
    shared_memory = shmat(shmid,NULL,0);
    printf("Enter some data\n");
    read(0,buff,100);
    strcpy(shared_memory,buff);
    printf("you wrote: %s",(char*)shared_memory);

    p=fork();
    if (p==0){
        id = shmget((key_t)2345, 1024, 0666);
        void* shared = shmat(id,NULL,0);
        printf("Data read: %s",(char*)shared);
    }

}