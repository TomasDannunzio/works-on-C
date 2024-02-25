#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[], char *envp[]){
	
	printf("Soy el proceso Suma: %i\n",getpid());
	
	execve("/mnt/sumaProxy", argv,envp);
	printf("No se pudo sumar porque: ./sumaProxy fallo.\n");
	
	return 0;
}
