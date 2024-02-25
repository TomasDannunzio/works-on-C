#include <stdio.h>
#include <sys/types.h>
#include <sys/signal.h>

void panblanco();
void pannegro();;

int tostadas=1;


int main(int argc, char *argv[]){

signal(SIGUSR1,&panblanco);
signal(SIGUSR2,&pannegro);

while(tostadas<31) pause();

return 0;
}

void panblanco(){
printf("Deseo tostadas de pan blanco.\n");
printf("Tostar pan blanco.\n");
sleep(2);
printf("Tostadas listas. (%i)\nTostadora lista, esperando pan.\n", (tostadas));
tostadas++;
}

void pannegro(){
printf("Deseo tostadas de pan negro.\n");
printf("Tostar pan negro.\n");
sleep(1);
printf("Tostadas listas. (%i)\nTostadora libre, esperando pan.\n", (tostadas));
tostadas++;
}






