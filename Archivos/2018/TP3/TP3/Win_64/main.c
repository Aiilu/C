/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


typedef struct
{

    char nombre[20];
    int edad;

} ePersona;

ePersona* newPersona();
ePersona* newPersonaParam(char* nombre, int edad);
void mostrarPersona ( ePersona* unaPersona);
void mostrarPersonas ( LinkedList* lista);

int main()
{
    LinkedList* lista;
      LinkedList* lista2;

    ePersona* p1, *p2, *p3, *p4, *p5, *p6, *auxPersona;

    p1 = newPersonaParam("Juan", 25);
    p2 = newPersonaParam("Martin", 18);
    p3 = newPersonaParam("Ana", 23);
    p4 = newPersonaParam("Julia", 37);
    p5 = newPersonaParam("Maria", 28);
    p6 = newPersonaParam("Marcos", 31);




    lista = ll_newLinkedList();

    if(lista == NULL)
    {
        exit(1);
    }

    printf("Cantidad: %d\n", ll_len(lista));

    ll_add(lista, p1);
    ll_add(lista, p2);
    ll_add(lista, p3);
    ll_add(lista, p4);


    printf("Cantidad: %d\n", ll_len(lista));

  //  auxPersona = (ePersona*) ll_get(lista, 2);

  //  mostrarPersona(auxPersona);

  mostrarPersonas(lista);
    printf("\n\n");

  ll_push(lista, 2, p5);


   mostrarPersonas(lista);

   printf("\n\n");

    ll_set(lista, 3, p6);
     mostrarPersonas(lista);

   printf("\n\n");

  // ll_remove(lista, 1);

  //   mostrarPersonas(lista);

 //  printf("\n\n");

   //ll_clear(lista);

    //printf("Cantidad: %d\n", ll_len(lista));


    //int posicion;

   // posicion = ll_indexOf(lista, p6);

   //  printf("pos: %d\n", posicion);

   lista2 = ll_subList(lista, 1, 4);


   mostrarPersonas(lista2);

    printf("\n\n");


    lista2 = ll_clone(lista);


     mostrarPersonas(lista2);

    printf("\n\n");


    ll_sort()












    return 0;
}


ePersona* newPersona()
{

    ePersona* persona;

    persona = (ePersona*) malloc(sizeof(ePersona));

    if(persona != NULL)
    {
        strcpy(persona->nombre, "");
        persona->edad = 0;
    }

    return persona;
}


ePersona* newPersonaParam(char* nombre, int edad)
{

    ePersona* persona;

    persona = newPersona();

    if(persona != NULL)
    {
        strcpy(persona->nombre, nombre);
        persona->edad = edad;
    }

    return persona;
}

void mostrarPersona ( ePersona* unaPersona)
{

    if(unaPersona != NULL)
    {
        printf("%10s  %2d\n", unaPersona->nombre, unaPersona->edad);
    }
}

void mostrarPersonas ( LinkedList* lista){

    ePersona* p;

    for(int i=0; i < ll_len(lista); i++){
            p = (ePersona*)ll_get(lista, i);
        mostrarPersona(p);
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


typedef struct
{

    char nombre[20];
    int edad;

} ePersona;

ePersona* newPersona();
ePersona* newPersonaParam(char* nombre, int edad);

void mostrarPersona ( ePersona* unaPersona);
void mostrarPersonas ( LinkedList* lista);

int main()
{
    LinkedList* lista;
    ePersona* p1, *p2, *p3, *p4, *p5;
    FILE* f;

/*
    p1 = newPersonaParam("Juan", 25);
    p2 = newPersonaParam("Martin", 18);
    p3 = newPersonaParam("Ana", 23);
    p4 = newPersonaParam("Julia", 37);
    p5 = newPersonaParam("Maria", 28);
*/


    lista = ll_newLinkedList();

    if(lista == NULL)
    {
        exit(1);
    }

    printf("Cantidad: %d\n", ll_len(lista));

   /* ll_add(lista, p1);
    ll_add(lista, p2);
    ll_add(lista, p3);
    ll_add(lista, p4);
    ll_add(lista, p5);

    f = fopen("personas.bin", "wb");

    ePersona* p;

    for(int i=0; i< ll_len(lista); i++){

    p = (ePersona*)ll_get(lista, i);

    fwrite(p, sizeof(ePersona), 1, f);

    }

    fclose(f);


*/

    ePersona* auxPersona;


    int cant;
    f = fopen("personas.bin", "rb");

    while(!feof(f)){

        auxPersona = newPersona();

        cant = fread(auxPersona, sizeof(ePersona), 1, f);

        if(cant < 1){
            break;
        }

        ll_add(lista, auxPersona);

    }

    fclose(f);

    mostrarPersonas(lista);







    return 0;
}


ePersona* newPersona()
{

    ePersona* persona;

    persona = (ePersona*) malloc(sizeof(ePersona));

    if(persona != NULL)
    {
        strcpy(persona->nombre, "");
        persona->edad = 0;
    }

    return persona;
}


ePersona* newPersonaParam(char* nombre, int edad)
{

    ePersona* persona;

    persona = newPersona();

    if(persona != NULL)
    {
        strcpy(persona->nombre, nombre);
        persona->edad = edad;
    }

    return persona;
}

void mostrarPersona ( ePersona* unaPersona)
{

    if(unaPersona != NULL)
    {
        printf("%10s  %2d\n", unaPersona->nombre, unaPersona->edad);
    }
}



void mostrarPersonas ( LinkedList* lista){

    ePersona* p;

    for(int i=0; i < ll_len(lista); i++){
            p = (ePersona*)ll_get(lista, i);
        mostrarPersona(p);
    }

}
