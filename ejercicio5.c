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

    nodo* nodo1 = nuevo();
    nodo* nodo2 = nuevo();
    nodo* nodo3 = nuevo();


    // RELLENAR
    nodo1->codigo = 1;
    strcpy(nodo1->nombre, "a");
    nodo1->siguiente = nodo2;

    nodo2->codigo = 2;
    strcpy(nodo2->nombre, "b");
    nodo2->siguiente = nodo3;

    nodo3->codigo = 3;
    strcpy(nodo3->nombre, "c");


    mostrar_lista(nodo1);
    printf("\n");


    nodo2->siguiente = NULL;
    nodo3 = NULL;

    mostrar_lista(nodo1);


    return 0;
}




