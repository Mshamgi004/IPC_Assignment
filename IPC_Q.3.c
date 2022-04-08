// IPC Assignment //
// Q.3 //
// Write a program parent process writing to pipe and child reading toggled data from pipe,
and also analyse the data flow order from write end to read end. //
// MAHADEV G I //


#include<unistd.h>
#include<stdio.h>


int fds[2];
void  parent_code()
{
    char *buf1="aaaaaaaaaaaaaa";                    // Creating the char buffer 1
    char *buf2="bbbbbbbbbbbbbb";                    // Creating the char buffer 2
    
    close(fds[0]);
    
    write(fds[1],buf1,20);                          // Write into the char buffer 1
    write(fds[1],buf2,20);                          // Write into the char buffer 2
    
    printf(" end of parent\n");
}

void child_code()
{
    char buf[100];
    int n,i;
    close(fds[1]);
    n = read(fds[0],buf,100);                                // Child reading the toggled data from pipe 
   
    printf(" no of chars read = %d\n",n);
    
    for(i = 0;i<n;i++)
    {
       printf("%c",buf[i]);
    }
    
    printf(" end of child \n");
}

int main()
{
    int res,i;
    pid_t p;
    res = pipe(fds);                                // Result to be stored in pipe using fd's
    
    p = fork();                                     // Calling of fork to check the order of data flow betwwen parent and child
    if(p == 0)
    {
        child_code();
    }
    else
    {
        parent_code();
    }
    return 0;
}       