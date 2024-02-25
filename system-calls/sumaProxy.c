#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[], char *envp[]){
	
	int x=0,y=0,r=0;
	x=atoi(argv[1]);
	y=atoi(argv[2]);
	
	r=x+y;
	
	printf("Resultado de la suma: %i + %i = %i\n",x,y,r);
	printf("Yo %i calcule la operacion \n", getpid());
	
	return 0;
	
}
