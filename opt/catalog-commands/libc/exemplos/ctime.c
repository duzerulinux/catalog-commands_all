#include <stdio.h>
#include <time.h>
int main()
  {
    time_t tp;
    time(&tp);
    printf("%s", ctime(&tp));
  }
