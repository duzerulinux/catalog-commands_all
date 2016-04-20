#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main ()
{
   int  fd, n;
   char linha[100];
   char nome[]  = "/etc/passwd";


   fd = open(nome, O_RDONLY);
   if (fd == -1)
     {
        printf("Open: %s\n", strerror(errno));
        exit(1);
     }

   while (n = read(fd, linha, strlen(linha)))
     printf("%s", linha);

   close(fd);
}
