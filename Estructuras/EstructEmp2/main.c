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

int main()
{
    Eempleado emp[]={{1,"Pepe",'m',25000},{2,"Maria",'f',12000},{3,"Luisa",'f',30000}};

    mostrarEmpleados(emp,3);

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
