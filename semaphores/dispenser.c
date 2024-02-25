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
    int msgflag = IPC_CREAT | 0666;
    mensaje msj;
    size_t largoMensaje;

    llave = ftok(".",'A'); 

    if((colaMensajeID=msgget(llave,msgflag))<0){
	printf("%i ",colaMensajeID);
        //ocurrio un error
	printf("Encontre un error.");
        perror("msgget");
        exit(1);
    };
   

    //comenzamos con el envio de mensajes
    /*a cada color le asignamos un tipo de mensaje, y enviamos la secuencia de colores 3 veces, lo
    que nos da un total de 30 envios*/

    int i=0;//controla cantidad de secuencias

    while(i<3){ //3 secuencias de mensajes

	sleep(1);

    //envio mensajes
        
        //definimos msj de color
        
        msj.mtype=1; strcpy(msj.mtext,"rojo (1)"); largoMensaje = strlen(msj.mtext)+1;
	
        //enviamos msj

       if(msgsnd(colaMensajeID,&msj,largoMensaje, IPC_NOWAIT)<0) {perror("msgsnd");exit(1);};

	printf("Color dispensado [%i] : %s\n",i,msj.mtext);	

    	sleep(1);

     
        msj.mtype=2; strcpy(msj.mtext,"azul (2)"); largoMensaje = strlen(msj.mtext)+1;
        

       if(msgsnd(colaMensajeID,&msj,largoMensaje, IPC_NOWAIT)<0) {perror("msgsnd");exit(1);};

	printf("Color dispensado [%i] : %s\n",i,msj.mtext);	

	sleep(1);

        
        msj.mtype=3; strcpy(msj.mtext,"amarillo (3)"); largoMensaje = strlen(msj.mtext)+1;
        

        if(msgsnd(colaMensajeID,&msj,largoMensaje, IPC_NOWAIT)<0) {perror("msgsnd");exit(1);};

	printf("Color dispensado [%i] : %s\n",i,msj.mtext);

	sleep(1);


        msj.mtype=4; strcpy(msj.mtext,"blanco (4)"); largoMensaje = strlen(msj.mtext)+1;

        if(msgsnd(colaMensajeID,&msj,largoMensaje, IPC_NOWAIT)<0) {perror("msgsnd");exit(1);};

	printf("Color dispensado [%i] : %s\n",i,msj.mtext);

	sleep(1);

        
        msj.mtype=5; strcpy(msj.mtext,"negro (5)"); largoMensaje = strlen(msj.mtext)+1;

        if(msgsnd(colaMensajeID,&msj,largoMensaje, IPC_NOWAIT)<0) {perror("msgsnd");exit(1);};

	printf("Color dispensado [%i] : %s\n",i,msj.mtext);


    i++;//inicio otra secuencia

    };

    return 0;
}
