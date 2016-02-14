#include <stdio.h>
#include <stdlib.h>

void teste_onexit(int status, void *arg)
{
   printf("Programa terminou sem erros\n");
   printf("status = %d, arg = %ld\n", status, (long) arg);
}

int main ()
{
   on_exit(teste_onexit, (void *) 50);
   printf("Teste on_exit\n");
}

