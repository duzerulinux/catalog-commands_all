#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

extern char etext, edata, end;

int main(int argc, char * const argv[], char * const envp[])
{
  printf("(1) etext     = %10p\n", &etext);
  printf("(1) edata     = %10p\n", &edata);
  printf("(1) end       = %10p\n", &end);
  printf("(1) Pr. break = %10p\n", sbrk(0));
  printf("(1) main      = %10p\n", &main);
  printf("(1) printf    = %10p\n", &printf);
  if (sbrk(500) != (void *) -1)
     printf("(2) Pr. break = %10p\n", sbrk(0));
  else
     printf("Erro sbrk %d - %s\n", errno, strerror(errno));

  char *memo = (char *) sbrk(0) + 678;
  if (brk(memo) == 0)
     printf("(3) Pr. break = %10p\n", sbrk(0));
  else
     printf("Erro brk %d - %s\n", errno, strerror(errno));
}
