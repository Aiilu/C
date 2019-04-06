#include <stdio.h>
#include <stdlib.h>
#define RANGO 5

int main()
{
    int vector[RANGO];
    int i;

    for(i=0;i<RANGO;i++)
    {
        printf("Ingrese el valor del indice: ");
        scanf("%d",&vector[i]);
    }

    printf("CONTENIDO: \n");
    for(i=0;i<RANGO;i++)
    {
        printf("%d\n",vector[i]);
    }
    return 0;
}

/*Leer 5 elementos de un vector de enteros y mostrar su contenido*/
