#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <fcntl.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[],char *envp[]){
pid_t pid;
int c=0;
int tuberia1[2], tuberia2[2],tuberia3[2];
bool pidioU=false,pidioC=false,pidioF=false;
char *nombreArchivo;
int fd;

while( (c=getopt(argc,argv,"ucf")) != -1 ){

switch(c){
case 'u':
pidioU=true;

break;
case 'c':
pidioC=true;

break;
case 'f':

pidioF=true;
nombreArchivo=argv[optind];

break;

default: {printf("La opcion indicada no es valida, por favor utilice -u, -c, o -uc -f y un nombre de un archivo.");return 1;};

};
};

if(pidioU && !pidioC && !pidioF){

pid = fork();

if(pid==0){
freopen("/mnt/nombres.txt","r",stdin);
execve("/mnt/usuario",0,0);

};

};

if(!pidioU && pidioC && !pidioF){

pid = fork();

if(pid==0){
freopen("nombres.txt","r",stdin);
execve("/mnt/clave",0,0);

};

};



if(pidioU && pidioC && pidioF){

fd = open(nombreArchivo, O_CREAT + O_RDWR, 0777);

if(fd==-1) {printf("No se ha podido abrir el archivo seleccionado.");return 1;}

dup2(fd,1);

pipe(tuberia1);

pid = fork();

if(pid==0){

close(tuberia1[0]);
freopen("nombres.txt","r",stdin);
close(1);
dup(tuberia1[1]);
execve("/mnt/usuario",argv,envp);

}
else{

pid = fork();

if(pid==0){
close(tuberia1[1]);
close(0);
dup(tuberia1[0]);
close(1);
dup(fd);

execve("/mnt/clave",argv,envp);

};

};

};

return 0;
}
