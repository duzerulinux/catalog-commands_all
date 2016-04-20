#include<unistd.h>
#include<linux/capability.h>
#include<stdio.h>
#include<string.h>  
#include<errno.h> 
#include<sys/socket.h> 
#include<netinet/in.h>

int main()
{
  int soquete;
  struct __user_cap_header_struct hdr   = { 0 };
  struct __user_cap_data_struct   data  = { 0 };   

  hdr.pid = getpid();
  hdr.version = _LINUX_CAPABILITY_VERSION;
  if (capget(&hdr, &data))   
    {
      printf("Erro capget() %d: %s\n", errno, strerror(errno));
      return 1;
    }
  else
    {
      printf("PID = %d, versao = %x\n", hdr.pid, hdr.version);
      printf("Efetivas = %x,  permitidas = %x, herdadas = %x\n", data.effective, data.permitted, data.inheritable);
    }

  soquete = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (soquete == -1)
      printf("Erro socket() %d: %s\n", errno, strerror(errno));
  else
    {
       printf("Soquete foi criado com sucesso\n");
       close(soquete);
    }

  data.effective = CAP_TO_MASK(CAP_NET_RAW);   

  if (capset(&hdr, &data))   
    {
      printf("Erro capset() %d: %s\n", errno, strerror(errno));
      return 1;
    }
  else
      printf("Capacidade CAP_NET_RAW incluida\n");

  if (capget(&hdr, &data))   
    {
      printf("Erro capget() %d: %s\n", errno, strerror(errno));
      return 1;
    }
  else
      printf("Efetivas = %x,  permitidas = %x, herdadas = %x\n", data.effective, data.permitted, data.inheritable);

  soquete = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (soquete == -1)
      printf("Erro socket() %d: %s\n", errno, strerror(errno));
  else
    {
       printf("Soquete foi criado com sucesso\n");
       close(soquete);
    }
}
