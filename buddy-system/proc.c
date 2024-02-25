//                       BUDDY SYSTEM CODE
#include<stdio.h>
// #include<conio.h>
int arbolMemoria[2000],i,j,k;

int MID[20]=0;

void alojarSegmento(int,int),marcarDivision(int), liberarEspacio(int), imprimirMapa(int,int), imprimirMapaConParticion(int,int);
int alojar(int),potencia(int,int);

main()
{
	int tamanioTotal,opcion,solicitado, IDaBorrar;
	printf("Proc_mm\n");
	tamanioTotal = 1024;
	while(1)
	{
		printf(" Sistema compañero \n");
		printf("*  -n   : <size>\n");
		printf("*  -f   : <MID>\n");
		printf("*  -m   \n");
		printf("*  -M   \n");
        printf("*  Opcion:  \n");
		scanf("%d",&opcion);
		switch(opcion)
		{
			case 1:
				printf("Alojar memoria\n");
				printf("Ingrese tamaño del proceso : ");
				scanf("%d",&solicitado);
				alojarSegmento(tamanioTotal,solicitado);
				break;
			case 2:
				printf("Desalojar memoria\n");
				printf("Ingrese el ID del proceso a borrar  :  \n");
				scanf("%d",&IDaBorrar);
				liberarEspacio(IDaBorrar);
				break;
			case 3:
				printf("Mapa de la memoria ordenado por dirección base de la partición: \n");
				imprimirMapa(tamanioTotal,0);
				break;
            case 4:
				printf("Mapa de la memoria ordenado por dirección base de la partición con fragmentacion interna: \n");
				imprimirMapaConParticion(tamanioTotal,0);
			default:
				return;
		}
	}
}

alojarSegmento(int tamanioTotal, int solicitado){
    int particiones = 0;
    while(1){ // realizo las divisiones en caso de ser mas pequenio
        if(solicitado<=tamanioTotal && solicitado>tamanioTotal/2) break;
        else {
            tamanioTotal/=2;
            particiones++;
        };
    for(i=potencia(2,particiones)-1;i<=(potencia(2,particiones+1)-2);i++){ // Itero sobre el arbol de memoria para ver si puedo almacenarlo
            if(arbolMemoria[i]==0 && alojar(i)){ // Veo si el nodo de esa cantidad de memoria esta vacia, y pregunto si puedo alojarla con alojar
                
                arbolMemoria[i] = solicitado; //Alojo memoria
                marcarDivision(i); // Marco la particion como hecha
                
                int h=0;
                while(h<20 && MID[h]!=0) h++;
                MID[h]=i; //registro su ID con h y el nodo en esa posicion

                printf("Se ha alojado la memoria particionada. ID Asignado: %i", h); 
            }

        };

    };
}


potencia(int base, int exponente){
    int resultado=1, it=0;
    if(exponente==0) return 1;
    else {
        while(it<exponente)
        resultado*=base;
        it++;
    }
    return resultado;
}

alojar(int nodo){

    while(nodo != 0 ){
        nodo=nodo%2;
        if(nodo==0) nodo=(nodo-1)/2;
        else nodo=nodo/2;

        if(arbolMemoria[nodo]>1) return 0; // pregunto si el nodo que marca las particiones puede particionarse o tiene un proceso guardado.
    }
    return 1;
}

marcarDivision(int nodo){

    while(nodo != 0 ){
        nodo=nodo%2;
        if(nodo==0) nodo=(nodo-1)/2;
        else nodo=nodo/2;
        arbolMemoria[nodo]=1; //marco que esta hecha y ocupada la particion de 2^nodo
    }
}

liberarEspacio(int id){
    int nodo=0;
    nodo=MID[id];
    arbolMemoria[nodo]=0; // Marco el nodo como vacio
    MID[id]=0; // Libero el MID para otro proceso sin modificar el del resto
    //Ahora debemos liberar particiones en caso de que sea necesario
    while(nodo!=0)
	{
        int nodoAdyacente;
        int nodoParticion;

        if(nodo%2==0) nodoAdyacente = node-1 else nodoAdyacente = node+1; // Si es par entonces debo ir al numero impar anterior, que
        // al dividir por dos me indica la particion ocupada, si es impar al siguiente par, que es posible que este ocupando otra particion
        // y por lo tanto no pueda deshacerla.

		if(arbolMemoria[nodoAdyacente]==0 && arbolMemoria[nodo]==0)
		{
            if(nodo%2==0) nodoParticion = (node-1)/2 else nodoParticion = node/2;
			arbolMemoria[nodoParticion]=0; // Marco que la particion que contenia al nodo que quise borrar y un nodo vacio al lado puede desaparecer 
            // y lo marco en 0.
			
            nodo=nodo%2;
            if(nodo==0) nodo=(nodo-1)/2;
            else nodo=nodo/2;

		}
		else break; // Cuando termino de borrar las particiones que pueda borrar al liberar el proceso, termina la iteracion.

	}
}

imprimirMapa(tamanioTotal,0){



}