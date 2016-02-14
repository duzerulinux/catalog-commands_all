#include <stdio.h>
#include <time.h>
int main()
  {
    time_t tp;
    struct tm lt;
    time(&tp); 
    lt = *localtime(&tp);
    printf("Dia  = %i\n", lt.tm_mday);
    printf("Mes  = %i\n", lt.tm_mon+1);
    printf("Ano  = %i\n", lt.tm_year+1900);
    printf("Hora = %i\n", lt.tm_hour);
    printf("Min  = %i\n", lt.tm_min);
  }
