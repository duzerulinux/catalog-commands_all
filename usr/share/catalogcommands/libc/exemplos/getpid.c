#include<unistd.h> 
#include<stdio.h>
#include<string.h>
#include<errno.h> 
int main()
{
   pid_t processo;
   processo = getpid();
   if (processo == -1)
       printf("Erro getpid() %d: %s\n", errno, strerror(errno));
   else
       printf("Processo ID = %ld\n", (long)processo);
}
