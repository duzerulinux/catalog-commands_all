#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
 char* path = argv[1];
 int val;

 /* Verifica se arquivo existe */
 val = access (path, F_OK);
 if (val == 0) 
    printf ("%s existe\n", path);
 else 
   {
     printf ("%s nao existe\n", path);
     return 0;
   }

 /* Verifica permissao de leitura */
 val = access (path, R_OK);
 if (val == 0)
    printf ("%s pode ser lido\n", path);
 else
    printf ("%s nao pode ser lido\n", path);

 /* Verifica permissao de escrita */
 val = access (path, W_OK);
 if (val == 0)
    printf ("%s pode ser alterado\n", path);
 else 
    printf ("%s nao pode ser alterado\n", path);

 /* Verifica permissao de execucao */
 val = access (path, X_OK);
 if (val == 0)
    printf ("%s pode ser executado\n", path);
 else 
    printf ("%s nao pode ser executado\n", path);
}
