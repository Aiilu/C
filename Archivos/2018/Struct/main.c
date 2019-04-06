#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
char nombre[10];
int edad;
}ePersona;

int main()
{
    ePersona aux;
    int cantEscrita;
    FILE* f;

    strcpy(aux.nombre,"JUAN");
    aux.edad=20;

    f = fopen("struct.txt","rb"); //wb
    if(f==NULL)
    {
        printf("Error");
        exit(1);
    }

    while(!feof(f))
    {
    cantEscrita=fread(&aux,sizeof(ePersona),1,f);

    if(cantEscrita==1)
    {
        printf("Nombre: %s - Edad: %d",aux.nombre,aux.edad);
    }
    }

    fclose(f);

    return 0;
}
