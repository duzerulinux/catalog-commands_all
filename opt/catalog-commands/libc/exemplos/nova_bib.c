#include "nova_bib.h"

int fatorial(int num)
{
  int i;
  int fat = 1;
  for (i = 2; i <= num; i++)
    fat = fat * i;
  return fat;
}

int fibonacci(int num)
{
  int i;
  int fib   = 0;
  int fib_a = 0;
  int fib_b = 1;
  for (i = 2; i <= num;i++)
    {
      fib   = fib_a + fib_b;
      fib_a = fib_b;
      fib_b = fib;
    }
  return fib;
}
