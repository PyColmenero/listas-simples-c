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

    while(auxiliar!=NULL){
        printf("C: %d \t N: %s\n", auxiliar->codigo, auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }
}


int main()
{

    char continuar[] = "Si";
    char nombre[10];
    int codigo = 0;
    int indice = 0;
    int indiceAgregar = 0;

    nodo* nodoPrimero = nuevo();

    nodo* nodoIndiceAgregar = nuevo();

    while( strcmp(&continuar,"Si") == 0 ||  strcmp(&continuar,"si") == 0  ||  strcmp(&continuar,"s") == 0 ){



        // PEDIR DATOS
        printf("Dime codigo: ");
        scanf("%i", &codigo);
        fseek(stdin,0,SEEK_END);
        printf("Dime nombre: ");
        scanf("%s", &nombre);
        fseek(stdin,0,SEEK_END);

        if(indice == 0){ // CREAR PRIMERO


            nodoPrimero->codigo = codigo;
            strcpy(nodoPrimero->nombre, &nombre);
            nodoPrimero->siguiente = NULL;

            mostrar_lista(nodoPrimero);

        } else if(indice == 1) { // CREAR OTRO, PRIMERO->SIGUIENTE = ESTE OTRO

            nodo* nodoActual = nuevo();
            nodoActual->codigo = codigo;
            strcpy(nodoActual->nombre, nombre);
            nodoPrimero->siguiente = nodoActual;

            mostrar_lista(nodoPrimero);

        } else {

            nodo* nodoActual = nuevo();
            nodoActual->codigo = codigo;
            strcpy(nodoActual->nombre, nombre);

             printf("Dime indice: ");
            for(int x = 0; x < indice; x++){
                printf("[%i]",x);
            }
            printf("\n");
            scanf("%i", &indiceAgregar);
            if(indiceAgregar<0) {
                indiceAgregar = 0;
            }
            if(indiceAgregar>=indice) {
                indiceAgregar = indice;
                //printf("a");
            }
            printf("Insertado en indice %i.\n",indiceAgregar);

            // indico a cual AGREGAR
            nodoIndiceAgregar = nodoPrimero;
            for(int x = 0; x < indiceAgregar; x++){
                nodoIndiceAgregar = nodoIndiceAgregar->siguiente;
            }

            // HAGO EL SWITCH
            // el creado ahora, tendrá de siguiente el siguiente del
            nodoActual->siguiente = nodoIndiceAgregar->siguiente;
            nodoIndiceAgregar->siguiente = nodoActual;

            mostrar_lista(nodoPrimero);
        }




        // CONTINUAR
        printf("Sigo?.\n");
        scanf("%s", &continuar);
        printf("\n");
        indice++;
    }


    mostrar_lista(nodoPrimero);


    return 0;
}




