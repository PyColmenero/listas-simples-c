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

    nodo* nodoAnterior = nuevo();
    nodo* auxiliar = nuevo();

    while( strcmp(&continuar,"Si") == 0 ||  strcmp(&continuar,"si") == 0 ){

        // PEDIR DATOS
        printf("Dime codigo: ");
        scanf("%i", &codigo);
        printf("Dime nombre: ");
        scanf("%s", &nombre);
        fseek(stdin,0,SEEK_END);


        // ASIGNAR AL AUXILIAR
        auxiliar = nuevo();
        auxiliar->codigo = codigo;
        strcpy(auxiliar->nombre, nombre);

        auxiliar->siguiente = nodoAnterior;
        // NODO ANTERIOR SERÁ EL CREADO AHORA
        nodoAnterior = auxiliar;


        // CONTINUAR
        printf("Sigo?.\n");
        scanf("%s", &continuar);
    }


    while(auxiliar->siguiente!=NULL){
        printf("C: %d \t N: %s\n", auxiliar->codigo, auxiliar->nombre);
        auxiliar = auxiliar->siguiente;
    }


    return 0;
}
