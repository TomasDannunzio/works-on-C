SEMAFOROS

// Semáforo representa la cantidad de recursos en la que existe condición de competencia y en la que
// establecere un orden.

key_t miclave = ftok("/tmp",1234); //retorna una clave de token para establecer los semaforos

int semId = semget(miclave,1,0777| IPC_CREAT); //retorna el id del conjunto de semaforos creado,
// vinculado a ese token

int semop(int semid, struct sembuf *sops, unsigned nsops);

// semid es mi conjunto de semaforos creado, que tiene asignado una key. 
// struct sembuf es un puntero a estructura que contiene qué semáforo del conjunto selecciono,
// que operación hago sobre él, y un espacio para flags, que pueden modificar esta operación.

struct sembuf sb = {0,-1,0};//resto 1 al semaforo seleccionado en la primera posicion. En este caso el
// 0 del conjunto semid.

// sembuf es un tipo de dato, por eso le ponemos sb despues.

DOWN() refiere a reservar recursos, UP() refiere a liberar recusos.

int down(int semId, int sem){

    struct sembuf sb={sem,-1,0}; ---> EL -1 INDICA QUE ES UN DOWN.

    semop(semId, &sb, 1); <--- //NOTAR LA IMPORTANCIA DEL & EN SB, PORQUE ES UN PUNTERO A ESTRUCTURA,
    //NO LA ESTRUCTURA COMO TAL. ADEMAS, VER QUE 1 ES LA CANTIDAD DE OP A REALIZAR.


};

Se puede hacer una especie de up cambiando el valor de operacion en la estructura sb
haciendo sb.sem_op = 1;

si intento leer un mensaje de una cola de mensajes vacia, se bloquea el proceso recibidor,
pq queda esperando un msj.

