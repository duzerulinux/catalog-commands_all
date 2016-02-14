#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main ()
{
   int  fd;
   char nome[]  = "teste";
   char frase[30] = "Alo, mundo";

   fd = open(nome, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
   if (fd == -1)
     {
        printf("Open: %s\n", strerror(errno));
        exit(1);
     }

   write(fd, frase, strlen(frase)); 

   close(fd);
   if (fd == -1)
     {
        printf("Close: %s\n", strerror(errno));
        exit(1);
     }
}
