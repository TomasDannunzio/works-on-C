#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGSZ 12

typedef struct msgbuf {

int mtype;
char mtext[MSGSZ];

} mensaje;

main(){

    int colaMensajeID;
    key_t llave;
    mensaje msj;
    size_t largoMensaje;

    llave = ftok(".",'A'); //hardcodeamos la llave.

    if((colaMensajeID=msgget(llave,IPC_CREAT | 0666))<0){ //ahora nos conectamos a la cola, no la creamos

        //ocurrio un error
        perror("msgget");
        exit(1);

    };

    //comenzamos a recibir los mensajes

    /*como previamente asignamos un tipo de mensaje a cada color, simplemente recibimos rojo y azul,
    que es el tipo 0 y 1 respectivamente. ademas, ya sabemos que vendran 15 mensajes, pero solamente 
    recibiremos 6, asi que para no dejar al proceso esperando mensajes, seteamos como condicion
    que espere solo esos mensajes.*/

    int i=0;

    while(i<3){
    
        msgrcv(colaMensajeID,&msj,MSGSZ,1,0); //recibo rojo
	sleep(1);
        printf("Nuevo color recibido: (rojo) (1)\n");
        msgrcv(colaMensajeID,&msj,MSGSZ,2,0); //recibo azul
        sleep(1);
        printf("Nuevo color recibido: (azul) (2)\n");
        i++; //termino secuencia

    };

return 0;

}
