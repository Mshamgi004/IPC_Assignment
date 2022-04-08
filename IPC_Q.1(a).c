// IPC Assignment //
// Q.1 //
/* Write a program that creates a shared memory region and displays shared memory id and also
print address at which shared area in this process starts from. */
// MAHADEV G I //

//****** Shared memeory read *******//


#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>

int main()
{
    char *r;
    int id;
   
    shmat(int id, void *addr, int flags);             // Shmat function declaring
    
    id = shmget(48,250,IPC_CREAT|0644);               // Creating the shared memeory id
    
    if(id < 0)
    {
        perror("shmget\n");
        return 0;
    }
    
    printf("id = %d\n", id);
    
    printf("Address is = %p\n",r);
    r = shmat(id,0,0);                      // Returning an shmat value 'r' to get the id and address
    
    printf("%s\n",r);
    
    
    return 0;
}    
