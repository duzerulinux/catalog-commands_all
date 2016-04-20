#include "nova_bib.h"

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

  printf("\n*** fatorial\n");
  int fat = fatorial(num);
  printf("Fatorial de %d = %d\n", num, fat);

  printf("\n'*** fibonacci\n");
  int fib = fibonacci(num);
  printf("Soma dos %d primeiros numeros de Fibonacci = %d\n\n", num, fib);
}
