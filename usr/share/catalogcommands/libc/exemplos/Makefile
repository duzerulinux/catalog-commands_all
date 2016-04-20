###
### $(obj-m) especifica os arquivos-objeto que serao usados para gerar os modulos carregaveis do kernel.
### $(obj-y) especifica os arquivos-objeto para o vmlinux (vao fazer parte do kernel, nao sao carregaveis)
###
### Caso o modulo fosse criado a partir da compilacao dos arquivos alo1.c e alo2.c:
###     obj-m := alomundo.o
###     module-objs := alo1.o alo2.o
###
### make = utilitario que determina que partes de um grande programa devem ser recompilados.
###   -C <dir> = muda para o diretorio <dir> antes de ler o Makefile (vai usar o ambiente especificado na geracao dos modulos).
###    M <dir> modules =  vai para o diretorio <dir> antes de gerar os modulos (os arquivos serao armazenados no diretorio especificado). 
###

obj-m := alomundo.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
