#include<sys/timex.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
   struct timex tempo;
   tempo.modes = ADJ_STATUS;
   tempo.status   = 1;
   tempo.maxerror = 0;
   tempo.tick     = 0;
   int retorno = adjtimex(&tempo);
   printf("status = %d, maxerror = %ld, tick = %ld\n", tempo.status, tempo.maxerror, tempo.tick);
   switch (retorno)
     {
       case -1 : printf("Erro %d - %s\n", errno, strerror(errno));
                 break;
       case  0 : printf("Relogio sincronizado\n");
                 break;
       case  1 : printf("Insere segundo intercalado\n");
                 break;
       case  2 : printf("Remove segundo intercalado\n");
                 break;
       case  3 : printf("Segundo intercalado em progresso\n");
                 break;
       case  4 : printf("Segundo intercalado ocorreu\n");
                 break;
       case  5 : printf("Relogio nao sincronizado\n");
     }
}
