#include <stdio.h>
#include <string.h>
int main ()
{
   char str[50];
   int len;
   strcpy(str, "Teste da funcao strlen()");
   len = strlen(str);
   printf("Tamanho = %d\n", len);
}
