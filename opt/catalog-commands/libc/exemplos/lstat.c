#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
void permissoes(struct stat info)
 {
   printf("Mode         : %u\n", (int)info.st_mode);
   printf("Permissoes   : ");
   if (S_ISREG(info.st_mode))
      printf("-");
   else
     if (S_ISLNK(info.st_mode))
        printf("l");
     else
        if (S_ISDIR(info.st_mode))
           printf("d");
        else
           if (S_ISCHR(info.st_mode))
              printf("c");
           else
              if (S_ISBLK(info.st_mode))
                 printf("b");
              else
                 if (S_ISFIFO(info.st_mode))
                    printf("f");
                 else
                    if (S_ISSOCK(info.st_mode))
                       printf("s");
                    else
                       printf("?");
   printf((info.st_mode & S_IRUSR) ? "r" : "-");
   printf((info.st_mode & S_IWUSR) ? "w" : "-");
   printf((info.st_mode & S_IXUSR) ? "x" : "-");
   printf((info.st_mode & S_IRGRP) ? "r" : "-");
   printf((info.st_mode & S_IWGRP) ? "w" : "-");
   printf((info.st_mode & S_IXGRP) ? "x" : "-");
   printf((info.st_mode & S_IROTH) ? "r" : "-");
   printf((info.st_mode & S_IWOTH) ? "w" : "-");
   printf((info.st_mode & S_IXOTH) ? "x" : "-");
   printf("\n");
 }

int main(int argc, char * const argv[])
 {
   struct stat info;

   if (argc != 2)
     {
       printf("Forneca o nome do arquivO\n");
       exit(1);
     }

   if(lstat(argv[1], &info) < 0)    
     {
       printf("Erro stat %d: %s\n", errno, strerror(errno));
       exit(2);
     }
   printf("Device       : %u\n",       (int)info.st_dev);
   printf("Major number : %u\n",       major(info.st_dev));
   printf("Minor number : %u\n",       minor(info.st_dev));
   printf("Inode        : %u\n",       (int)info.st_ino);
   permissoes(info);
   printf("Links        : %u\n",       (int)info.st_nlink);
   printf("UID          : %u\n",       (int)info.st_uid);
   printf("GID          : %u\n",       (int)info.st_gid);
   printf("Tipo         : %u\n",       (int)info.st_rdev);
   printf("Tamanho      : %u bytes\n", (int)info.st_size);
   printf("Bloco E/S    : %u bytes\n", (int)info.st_blksize);
   printf("Qtde Blocos  : %u\n",       (int)info.st_blocks);
   printf("Ultimo acesso: %s",         ctime(&info.st_atime));
   printf("Ultima modif.: %s",         ctime(&info.st_mtime));
   printf("Ultimo status: %s",         ctime(&info.st_ctime));
 }

