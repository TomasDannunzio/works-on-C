#include <stdio.h>
#include <string.h>
#include <getopt.h>


int main(int argc, char *argv[]){

int c=0,i=0,j=0,k=0;
char argumento[50];
char argumento2[50];


printf("%i",argc);

if(argc<=1) printf("La sintaxis de ejecucion es de la forma ./nombreEjecutable -v <argumento> -r <argumento2>. Por favor vuelva a ejecutarlo con opciones.\n");
else{

while( (c=getopt(argc,argv,"vr")) != -1 ){
switch(c){
case 'v':
printf("\n");
strcpy(argumento,argv[optind]);
for(i=0;i<strlen(argumento);i++){
if(argumento[i]=='a' || argumento[i]=='e' || argumento[i]=='i' || argumento[i]=='o' || argumento[i]=='u') printf("Vocal [%i] = %c\n",i,argumento[i]);
else printf("Consonante [%i] = %c\n",i,argumento[i]);
};
break;

case 'r':
printf("\n");
strcpy(argumento2,argv[optind]);
printf("Cadena original: %s, Longitud: [%i]\n",argumento2,strlen(argumento2));
for(j=(strlen(argumento2)-1);j>-1;j--){
printf("Char [%i] : %c\n",j,argumento2[j]);
};
break;

default: printf("Error: las opciones admitidas son v y r. Vuelva a ejecutar el programa con alguna o ambas de estas opciones.\n"); return 0;

};

};

};

printf("\n");
printf("Cantidad de argumentos: %d \n", argc);

for(k=(argc-1);k>-1;k--) printf("Argumento[%i] : %s \n",k,argv[k]);

return 0;

};

