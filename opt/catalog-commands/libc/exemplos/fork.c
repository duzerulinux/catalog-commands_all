#include<unistd.h> 
#include<stdio.h>
#include<string.h>
#include<errno.h> 
int main()
{
   pid_t filho;
   filho = fork();
   if (filho == -1)
       printf("Erro fork() %d: %s\n", errno, strerror(errno));
   else
     {
       if (filho == 0)
         printf("Processo-filho: PID = %ld, PPID = %ld\n", (long)getpid(), (long)getppid());
       else
         printf("Processo-pai: PID = %ld, PPID = %ld, PID do filho = %ld\n", (long)getpid(), (long)getppid(), (long)filho);
     }
}
