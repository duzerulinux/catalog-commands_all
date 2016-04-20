#include<stdio.h>
int main()
{
   FILE *arq;
   arq = fopen("arquivo_inexistente.txt", "r");
   if (arq == NULL ) 
     {
       perror("Erro ");
       return(1);
     }
   fclose(arq);
   return(0);
}

