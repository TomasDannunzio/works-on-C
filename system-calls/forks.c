#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[]){
  
pid_t pid;
int valor = atoi(argv[1]);


pid = fork ();

if (pid == 0) {
	pid_t pidn;
	pidn = fork();
	
	if(pidn == 0){
		printf("Soy NIETO. Soy el hijo de: %i - Mi PID : %i y VALOR es: %i \n",getppid(),getpid(),(valor*valor*valor));
		
	}
	else {
		printf("Soy HIJO. Soy el hijo de: %i - Mi PID : %i y VALOR es: %i \n",getppid(),getpid(),((valor*2) + 5000));
	}
	
}
else {
	printf("VALOR INICIAL: %i\n",valor);
		printf("Soy PADRE. Mi hijo es: %i - Mi PID : %i y VALOR es: %i \n",pid,getpid(),(valor+2000));
}



return 0;

}
