#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>

int main(int argc, char *argv[]){

//El SO se encarga de modificar la entrada estándar al agregar el < nombres.txt cambiandola por este archivo. Por lo tanto
//Podemos usar scanf para leer como si estuviesemos leyendo por teclado y luego printf para mostarlo por pantalla.


char linea[50];

while(0 < scanf("%s",&linea)){

printf("u%s\n",linea);

};



return 0;

}
