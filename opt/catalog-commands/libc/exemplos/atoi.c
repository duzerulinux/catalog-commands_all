#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num;
    if (argc != 2)
       {
          printf("Forneca um numero\n");
          return 1;
       }
    else
       num = atoi(argv[1]);

    printf("Numero recebido = %d\n", num);
}
