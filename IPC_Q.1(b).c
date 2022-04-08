// IPC Assignment //
// Q.1 //
/* write a program that creates a shared memory region and displays shared memory id and also
print address at which shared area in this process starts from. */
// MAHADEV G I //

// ******Shared memeory write ****** //
// 




#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>

int main()
{
    char *p;
    int id;
    
    id = shmget(48,250,IPC_CREAT|0644);              // Shmget function to get the shmid
    
    if(id<0)
    {
        perror("shmget");
        return 0;
    }
    
    printf("id = %d\n", id);
    p = shmat(id,0,0);                             // Shmat function used to write in the data
    printf("Enter the data:");
    scanf("%s", p);
    
    return 0;
}        
