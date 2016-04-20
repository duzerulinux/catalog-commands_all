#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
   if (acct(argv[1]) == 0) 
     {
       if (argv[1] == NULL)
          printf("Monitoramento desabilitado\n");
       else
          printf("Monitoramento habilitado\n");
     }
   else
       printf("Erro %d - %s\n", errno, strerror(errno));
}
