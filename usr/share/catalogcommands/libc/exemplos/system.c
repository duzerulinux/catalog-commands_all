#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
#include<errno.h> 

int main()
{
  int ret;
  ret = system("pwd"); 
  if (ret == -1)
     printf("Erro system() %d: %s\n", errno, strerror(errno));
  else
     printf("Exemplo executado com sucesso\n");
}
