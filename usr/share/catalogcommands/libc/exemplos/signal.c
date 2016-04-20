#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void trata_sinal(int signo)
{
  if (signo == SIGINT)
     printf("\nRecebido SIGINT\n");
  exit(0);
}

int main(void)
{
  if (signal(SIGINT, trata_sinal) == SIG_ERR)
     printf("\nNao captura SIGINT\n");
  while(1) 
    pause();
}
