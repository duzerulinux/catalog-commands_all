#include<unistd.h> 
#include<stdio.h>
#include<string.h>
#include<errno.h> 
int main()
{
   pid_t processo, processo_pai;
   processo     = getpid();
   processo_pai = getppid();
   if (processo == -1)
       printf("Erro getpid() %d: %s\n", errno, strerror(errno));
   else
     {
       printf("Processo ID  = %ld\n", (long)processo);
       printf("Processo-pai = %ld\n", (long)processo_pai);
     }
}
