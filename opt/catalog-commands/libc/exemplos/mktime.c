#include <stdio.h>
#include <time.h>
int main()
  {
    time_t data_atual;
    time_t data_final;
    struct tm data;
    time(&data_atual); 
    data.tm_sec   = 0;
    data.tm_min   = 0;
    data.tm_hour  = 0;
    data.tm_mday  = 1;
    data.tm_mon   = 0;
    data.tm_year  = 116;
    data.tm_isdst = 0;
    data_final = mktime(&data);
    if (data_final > data_atual)
	printf("Faltam %d dias para a chegada de 2016\n", (int)(data_final-data_atual)/(24*60*60));
    else
	printf("O ano de 2015 ja terminou\n");
  }
