#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int main()
  {
    if (mkdir("./testes", S_IRUSR | S_IWUSR | S_IXUSR) != 0)
       printf("mkdir: %s\n", strerror(errno));
    system("ls -l");
  }
