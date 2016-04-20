#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
int main(int argc, char * const argv[], char * const envp[])
  {
    int    arq1;
    int    arq2;
    size_t num;
    char   linha[100];
    struct stat buf;
    if (argc < 3)
      {
         printf("Voce deve fornecer os nomes dos arquivos de origem e de destino\n");
         exit(1);
      }
    arq1 = open(argv[1], O_RDONLY);
    if (arq1 == -1)
      {
         printf("Open arq1: %s\n", strerror(errno));
         exit(2);
      }
    if (fstat(arq1, &buf) == -1)
      {
         printf("Fstat: %s\n", strerror(errno));
         exit(3);
      }
    arq2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, buf.st_mode);
    if (arq2 == -1)
      {
         printf("Open arq2: %s\n", strerror(errno));
         exit(4);
      }
    num = read(arq1, linha, 100);
    while(num != 0)
     {
       if (write(arq2, linha, num) == -1) 
         {
           printf("Write: %s\n", strerror(errno));
           exit(5);
         }
       num = read(arq1, linha, 100);
     }  
    close(arq1);
    close(arq2);
  }
