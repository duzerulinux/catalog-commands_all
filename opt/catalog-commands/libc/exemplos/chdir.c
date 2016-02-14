#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
#include<errno.h> 

int main()
{
  if (chdir("/boot") == -1)
    {
      printf("Erro chdir(/etc) %d: %s\n", errno, strerror(errno));
      return 1;
    }
  system("pwd");
  
  if (chdir("grub") == -1)
    {
      printf("Erro chdir(grub) %d: %s\n", errno, strerror(errno));
      return 1;
    }
  system("pwd");
  
  if (chdir(getenv("HOME")) == -1)
    {
      printf("Erro chdir(HOME) %d: %s\n", errno, strerror(errno));
      return 1;
    }
  system("pwd");
}
