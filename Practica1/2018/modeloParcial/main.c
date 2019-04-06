#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include TAM 10
#include "parcial.h"

int main()
{
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);

    char seguir = 's';

    do
    {
        switch(menu())
        {
        case 1:
            break;
        default:
            printf("Esta opcion no existe");
        }
    }while(seguir == 's');

    return 0;
}
