#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
 {
   int  fd;
   char nome[]   = "/tmp/arqXXXXXX";
   char buffer[] = "teste de escrita";
   size_t tam    = 100;

   if (!(fd = mkstemp(nome)))
     {
       printf("Erro mkstemp %d: %s\n", errno, strerror(errno));
       exit(1);
     }
   printf("Nome do arquivo temporario: %s\n", nome);

   if (write(fd, buffer, tam) == -1)
     {
       printf("Erro write %d: %s\n", errno, strerror(errno));
       exit(2);
     }

   if (close(fd) == -1)
     {
       printf("Erro close %d: %s\n", errno, strerror(errno));
       exit(3);
     }

   if (unlink(nome) != 0)
     {
       printf("Erro unlink %d: %s\n", errno, strerror(errno));
       exit(4);
     }
 }
