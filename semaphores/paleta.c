#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <string.h>
#define SIZE 100
#define N 3
int sup(int idsema, int num){
struct sembuf X = {num,1,0};
semop(idsema,&X,1);
return 0;
}
int sdown(int idsema, int num){
struct sembuf X = {num,-1,0};
semop(idsema,&X,1);
return 0;
}
void writeshm(int shmid,char *segptr, char *text);
void readshm(int shmid, char *segptr);
int main(void){
key_t key;
int idsema,shmid;
pid_t hijo;


key = ftok(".",'A');
idsema = semget(key,2,0666 | IPC_CREAT);


semctl(idsema,0,SETVAL,1);


semctl(idsema,1,SETVAL,0);
char saboresMar[3][4]={"cer","ban","dur"};


shmid=shmget(key,SIZE,IPC_CREAT | 0666);



hijo = fork();

if(hijo){
char *ptrmar;
int i=0;
while(i<N){
sdown(idsema,0);
ptrmar = shmat(shmid,0,0);
writeshm(shmid,ptrmar+(6*i),saboresMar[i]);
printf("Mariana coloca sabor: %s \n", saboresMar[i]);

shmdt(ptrmar);
sup(idsema,1);

i++;
}
}
else{
char *ptrjuan;
char saboresJuan[3][4]={"CHO","VAI","AME"};
int j=0;
while(j<N){
sdown(idsema,1);
ptrjuan = shmat(shmid,0,0);
writeshm(shmid,ptrjuan+(6*j)+3,saboresJuan[j]);
printf("Juan coloca sabor: %s \n", saboresJuan[j]);

if(j==2){
readshm(shmid,ptrjuan);
shmdt(ptrjuan);
}

shmdt(ptrjuan);
sup(idsema,0);

j++;

}

}
return 0;
}




void writeshm(int shmid,char *segptr, char *text){
strcpy(segptr,text);

}
void readshm(int shmid, char *segptr){
printf("Paleta_estrella es: %s \n",segptr);
}

























