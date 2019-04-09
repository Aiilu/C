#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int legajo;
char nombre[20];
char sexo;
float sueldo;
}Eempleado;

void mostrarEmpleado(Eempleado x);
void mostrarEmpleados(Eempleado y[],int tam);
void ordenamiento(Eempleado y[], int tam);

int main()
{
    Eempleado emp[]={{1,"Ailen",'f',25000},{2,"Vicky",'f',12000},{3,"Carolina",'f',30000}};

    mostrarEmpleados(emp,3);

    printf("\n\n");

    ordenamiento(emp,3);

    return 0;
}

void mostrarEmpleado(Eempleado x)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n",x.legajo,x.nombre,x.sexo,x.sueldo);
}

void mostrarEmpleados(Eempleado y[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        mostrarEmpleado(y[i]);
    }

}

void ordenamiento(Eempleado y[], int tam)
{
   printf("Ordenamiento: \n");
   int i;
   int j;
   Eempleado aux;

   for(i=0;i<tam-1;i++)
   {
       for(j=i+1;j<tam;j++)
       {
           if(y[i].sueldo < y[j].sueldo)
           {
               aux = y[i];
               y[i] = y[j];
               y[j] = aux;
           }
       }
   }

   for(i=0;i<tam;i++)
   {
       mostrarEmpleado(y[i]);
   }
}
