#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
#include<errno.h> 

int main()
{
  char *dir;
  dir = getenv("HOME"); 
  if (dir == NULL)
     printf("Erro getenv() %d: %s\n", errno, strerror(errno));
  else
     printf("Diretorio home = %s\n", dir);
}
