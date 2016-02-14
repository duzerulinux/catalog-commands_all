#include<time.h> 
#include<stdio.h>
#include<unistd.h>
int main()
{
   time_t tp;
   struct tm lt;
   time(&tp);
   lt = *localtime(&tp); 
   int dia = lt.tm_mday;
   printf("Dia = %d\n", dia);
   _exit(dia);
}

