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

    nodo* nodoAnterior;
    nodo* nodoPrimero;
    nodo* nodoActual = nuevo();

    while( strcmp(&continuar,"Si") == 0 ||  strcmp(&continuar,"si") == 0  ||  strcmp(&continuar,"s") == 0 ){

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



        // si es el primer nodo.
        if(indice == 1){
            // INDICO EL PRIMER NODO
            nodoPrimero = nodoActual;
        } else {
            // ASIGNO EL SIGUIENTE ES EL ANTERIOR
            nodoAnterior->siguiente = nodoActual;
        }

        // GUARDO EL NODO ANTERIOR
        // ASI LE ASIGNO SU "SIGUIENTE" ÉL
        nodoAnterior = nodoActual;


        // CONTINUAR
        printf("Sigo?.\n");
        scanf("%s", &continuar);
        printf("\n");
    }

    // creo un nuevo NODO apuntando el PRIMER NODO CREADO
    nodo* auxiliar = nuevo();
    auxiliar = nodoPrimero;

    while(auxiliar!=NULL){
        printf("C: %d \t N: %s\n", auxiliar->codigo, auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }
    nodoPrimero = NULL;


    return 0;
}
