#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
int main()
{
   int   arq;
   int   valor_st;
   char  linha1[50]="Escrita feita pelo processo-filho\n";
   char  linha2[50]="Escrita feita pelo processo-pai\n";
   pid_t filho, ret;
   filho = fork();
   if (filho == -1)
     {
       printf("Erro fork() %d: %s\n", errno, strerror(errno));
       exit(1);
     }
   if (filho == 0)
       {
         arq = open("/tmp/arquivo1", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
         if (arq == -1)
           {
             printf("Open arq: %s\n", strerror(errno));
             exit(2);
           }
         if (write(arq, linha1, strlen(linha1)) == -1) 
           {
             printf("Write: %s\n", strerror(errno));
             exit(3);
           }
         close(arq);
       }
   else
       {
	 ret = waitpid(filho, NULL, NULL);
         if (ret != filho)
           {
             printf("Waitpid: %s\n", strerror(errno));
             exit(5);
           }
         if (link("/tmp/arquivo1", "arquivo2") != 0)
           {
             printf("Link: %s\n", strerror(errno));
             exit(6);
           }
         arq = open("arquivo2", O_WRONLY | O_APPEND, NULL);
         if (arq == -1)
           {
             printf("Open arq2: %s\n", strerror(errno));
             exit(7);
           }
         if (write(arq, linha2, strlen(linha2)) == -1) 
           {
             printf("Write: %s\n", strerror(errno));
             exit(8);
           }
         close(arq);
       }
}
