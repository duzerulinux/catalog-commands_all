#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void mensagem(int signum)
{
   printf("\nSinal capturado\n");
   exit(0);
}

int main() 
{
  if (signal(SIGINT, mensagem) == SIG_ERR)
    {
       printf("Nao e possivel capturar sinal\n");
       exit(1);
    } 
  
  while (1) 
    pause();
}
