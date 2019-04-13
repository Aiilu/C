#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
   int legajo;
   char nombre[20];
   float sueldo;
   int ocupado;
}eEmpleado;

void inicX(eEmpleado x[],int tam);
int buscarLibre(eEmpleado x[],int tam); //recorrer secuencialmente y buscar la primera libre

int main()
{
    eEmpleado lista[TAM];
    inicX(lista,TAM);

    return 0;
}

void inicX(eEmpleado x[],int tam)
{
    for(int i = 0;i < tam;i++)
    {
        x[i].ocupado = 0;
    }
}

int buscarLibre(eEmpleado x[],int tam)
{
    int index = -1;

    for(int i = 0;i< tam;i++)
    {
       if(x[i].ocupado == 0)
       {
         index = i;
         break;
       }
    }

    return index;
}

void mostrarEmpleado(Eempleado x)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n",x.legajo,x.nombre,x.sexo,x.sueldo);
}

void mostrarEmpleados(Eempleado x[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == OCUPADO)
        {
            mostrarEmpleado(x[i]);
        }
    }
}
