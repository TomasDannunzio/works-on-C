#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc,char *argv[]){

if(argc!=2) {printf("Error. La funcion debe ejecutarse con solo un argumento, que es el PID del proceso tostadora.\n");return 0;}

else{

int pidTostadora;

pidTostadora=atoi(argv[1]);

int nrohuesped=1;

while(nrohuesped<31){


if(nrohuesped%5!=0){

printf("Pedido de tostada de Pan Blanco. Huesped %i\n",nrohuesped);

kill(pidTostadora,SIGUSR1);

sleep(2);

} 

else{

printf("Pedido de tostada de Pan Negro. Huesped %i\n",nrohuesped);

kill(pidTostadora,SIGUSR2);

sleep(1);

};

nrohuesped++;

};

};

return 0;
}
