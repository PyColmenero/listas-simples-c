#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estructura{
    int codigo;
    char nombre[10];
    struct estructura *siguiente;
} nodo;

nodo* nuevo();

nodo* nuevo(){
    nodo *p;
    p = (nodo*) malloc(sizeof(nodo));
    p->siguiente = NULL;
    return(p);
}

mostrar_lista(nodo *nodoPrimero);
mostrar_lista(nodo *nodoPrimero){
    // creo un nuevo NODO apuntando el PRIMER NODO CREADO
    nodo* auxiliar = nuevo();
    auxiliar = nodoPrimero;

    int x = 0;
    while(auxiliar!=NULL){
        printf("%d) Codigo: %d \t Nombre: %s\n", ++x, auxiliar->codigo, auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }
}


int main()
{

    char *texto;
    int nbytes;
    texto = "abcdefghij";

    nodo* nodoPrimero = nuevo();
    int indiceBorrar = -1;
    int num = rand() % 10 + 1;

    char letra = texto[0];

    for(int x = 0; x < 5; x++){

        num = rand() % 10 + 1;

        if(x == 0){
            // primero
            nodo* nodoActual = nuevo();
            //nodoActual->nombre = texto[0];
            nodoActual->nombre[0] = texto[num-1];
            nodoActual->codigo = num;
            nodoActual->siguiente = NULL;

            nodoPrimero = nodoActual;
        } else {
            // Segundo
            nodo* nodoActual = nuevo();
            nodoActual->nombre[0] = texto[num-1];
            nodoActual->codigo = num;

            nodo* auxiliar = nodoPrimero;
            while( auxiliar->siguiente != NULL){
                auxiliar = auxiliar->siguiente;
            }
            auxiliar->siguiente = nodoActual;


        }
    }

    mostrar_lista(nodoPrimero);
    printf("\n");




    int repetir = 0;
    while(repetir == 0){
        printf("Dime INDICE a borrar: ");
        scanf("%i", &indiceBorrar);
        fseek(stdin,0,SEEK_END);
        if(indiceBorrar>=0 && indiceBorrar <= 4) {
            repetir = 1;
        }
    }

    nodo* auxiliar = nodoPrimero;
    for(int x = 0; x < indiceBorrar-1; x++){
        auxiliar = nodoPrimero->siguiente;
    }
    auxiliar->siguiente = auxiliar->siguiente->siguiente;
    printf("Borrado en indice %i.\n", indiceBorrar);
    printf("\n");

    mostrar_lista(nodoPrimero);



    return 0;
}




