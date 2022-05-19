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

int main()
{

    char continuar[] = "Si";
    char nombre[10];
    int codigo = 0;
    int indice = 0;

    nodo* nodoAnterior = nuevo();
    nodo* nodoActual = nuevo();

    while( strcmp(&continuar,"Si") == 0 ||  strcmp(&continuar,"si") == 0 ){

        indice++;

        // PEDIR DATOS
        printf("Dime codigo: ");
        scanf("%i", &codigo);
        printf("Dime nombre: ");
        scanf("%s", &nombre);
        fseek(stdin,0,SEEK_END);


        // ASIGNAR AL AUXILIAR
        nodoActual = nuevo();
        nodoActual->codigo = codigo;
        strcpy(nodoActual->nombre, nombre);

        if(indice == 1){
            // INDICO EL PRIMER NODO
        } else {
            // ASIGNO EL SIGUIENTE ES EL ANTERIOR
            nodoActual->siguiente = nodoAnterior;
        }



        nodoActual->siguiente = nodoAnterior;
        // NODO ANTERIOR SERÁ EL CREADO AHORA
        nodoAnterior = nodoActual;


        // CONTINUAR
        printf("Sigo?\n");
        scanf("%s", &continuar);
        printf("\n");
    }

    // IMPRIMIR
    nodo* primerNodo = nodoActual;
    while(nodoActual->siguiente!=NULL){
        printf("C: %d \t N: %s\n", nodoActual->codigo, nodoActual->nombre);
        nodoActual = nodoActual->siguiente;
    }
    primerNodo = NULL;



    return 0;
}
