#include<stdio.h>
#include<string.h>
#include<errno.h>
int main()
{
   FILE *arq;
   arq = fopen("arquivo_inexistente.txt", "r");
   if (arq == NULL ) 
     {
       printf("Erro %d - %s\n", errno, strerror(errno));
       return(1);
     }
   fclose(arq);
   return(0);
}

