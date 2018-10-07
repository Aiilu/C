#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"

int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Empleados\n");
    printf(" 5-  Ordenar Empleados\n");
    printf(" 6-  Mostrar Empleados x Sector\n");
    printf(" 7-  Ordenar Empleados x Sector y Nombre\n");
    printf(" 8-  Listar empleados ganadores\n");
    printf(" 9-  Listar Comidas\n");
    printf(" 10- Alta Almuerzo\n");
    printf(" 11- Mostrar Almuerzos\n");
    printf(" 20- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarEmpleados(eEmpleado lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].isEmpty = 1; // verdadero que hay espacio
    }
}

int buscarLibre(eEmpleado lista[],int tam)
{
    int indice = -1;

    int i;

    for(i=0;i<tam;i++)
    {

    }
}
