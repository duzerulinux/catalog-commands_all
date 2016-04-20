#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
   int fd, flags;

   /* Abre descritor de arquivo */
   fd = open("./teste", O_RDWR);
   if (fd == -1)
     {
       printf("Erro open %d: %s\n", errno, strerror(errno));
       exit(1);
     }

   /* Verifica flag para escrever no final do arquivo */
   if ((flags = fcntl(fd, F_GETFL)) < 0)
     {
       printf("Erro fcntl %d: %s\n", errno, strerror(errno));
       exit(2);
     }
   else
     {
       if ((flags & O_ACCMODE) == O_RDWR) 
          printf("Arquivo permite leitura e escrita\n");
       if ((flags & O_APPEND) == 0) 
          printf("(1) Escrita sobrescreve arquivo existente\n");
       else
          printf("(1) Escrita no final do arquivo\n");
     }

   /* Altera flag para escrever no final do arquivo */
   if (fcntl(fd, F_SETFL, flags | O_APPEND) < 0)
     {
       printf("Erro fcntl %d: %s\n", errno, strerror(errno));
       exit(3);
     }
   flags = fcntl(fd, F_GETFL);
   if ((flags & O_APPEND) == 0) 
      printf("(2) Escrita sobrescreve arquivo existente\n");
   else
      printf("(2) Escrita no final do arquivo\n");

   /* Escreve no final do arquivo */
   char buffer[] = "Adeus, mundo cruel\n";
   if (write(fd, buffer, strlen(buffer)) == -1)
     {
       printf("Erro write %d: %s\n", errno, strerror(errno));
       exit(4);
     }

   /* Fecha arquivo */
   if (close(fd) == -1)
     {
       printf("Erro close %d: %s\n", errno, strerror(errno));
       exit(5);
     }
}
