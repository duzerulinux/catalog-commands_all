#include<stdio.h>
#include<errno.h>
#include<string.h>
int main(int argc, char * const argv[], char * const envp[])
  {
    execve("./teste", argv, envp);
    printf("Erro execve %d: %s\n", errno, strerror(errno));
  }
