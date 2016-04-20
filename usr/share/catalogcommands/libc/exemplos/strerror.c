#include<stdio.h>
#include<string.h>
int main()
{
   int i;
   for (i = 0; i <= 133; i++)
       printf("%3d  %s\n", i, strerror(i));
}
