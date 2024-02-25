#include <stdio.h>
#include <getopt.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[]){

DIR *directorio;
int c;
struct dirent *dir;
char *nomDirectorio;
char directorioActual[PATH_MAX];


if(argc<2) printf("%s","Por favor siga la sintaxis de ejecución propuesta.\n");

else{

while((c=getopt(argc,argv,"dr")) != -1){


if(argc==2){directorio=opendir(getcwd(directorioActual,sizeof(directorioActual)));nomDirectorio=directorioActual;} 

else{

directorio=opendir(argv[optind]);nomDirectorio=argv[optind];

if(directorio==NULL) 
{

directorio=opendir(argv[optind+1]);nomDirectorio=argv[optind+1];

};

};

switch(c){

case 'd':

printf("\nDirectorios de %s \n",nomDirectorio);

while((dir=readdir(directorio))!=NULL){
if((dir-> d_type== DT_DIR) && strcmp(dir-> d_name,".")!=0 && strcmp(dir-> d_name,"..")!=0) printf("%s - Directorio \n", dir-> d_name);
};


break;


case 'r':

printf("\nArchivos regulares de %s \n",nomDirectorio);

while((dir=readdir(directorio))!=NULL){
if(dir-> d_type!= DT_DIR) printf("%s - Regular \n", dir-> d_name);
};


break;


default:{printf("Las opciones disponibles en la sintaxis de ejecución son d y r, después de un guión."); return 0;};

};

};

};

closedir(directorio);

return 0;
}
