#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

void mensagem(int signum)
{
   time_t tp;
   time(&tp);
   printf("%s", ctime(&tp));
}

int main() 
{
  struct itimerval it_val;

  if (signal(SIGALRM, mensagem) == SIG_ERR) 
    {
      printf("Erro signal() %d: %s\n", errno, strerror(errno));
      exit(1);
    }

  it_val.it_value.tv_sec  = 5;
  it_val.it_value.tv_usec = 0;	
  it_val.it_interval      = it_val.it_value;

  mensagem(0);

  if (setitimer(ITIMER_REAL, &it_val, NULL) == -1) 
    {
      printf("Erro setitimer() %d: %s\n", errno, strerror(errno));
      exit(1);
    }

  while (1) 
    pause();
}
