#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
#include<errno.h> 

int main()
{
  int ret;
  char dir[15] = "/etc/passwd";
  char comando[100];
  ret = sprintf(comando, "ls -l %s", dir);
  printf("ret = %d\n", ret);
  ret = system(comando); 
  if (ret == -1)
     printf("Erro system() %d: %s\n", errno, strerror(errno));
  else
     printf("Exemplo executado com sucesso\n");
}
