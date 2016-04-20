#include <stdio.h>
#include <stdlib.h>

void teste_atexit()
{
   printf("Programa terminou sem erros\n");
}

int main ()
{
   atexit(teste_atexit);
   printf("Inicio do programa\n");
}

