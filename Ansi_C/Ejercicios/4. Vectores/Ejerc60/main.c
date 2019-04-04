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

        while(vector[i]<0)
        {
            printf("ERROR. Ingrese el valor nuevamente: ");
            scanf("%d",&vector[i]);
        }
    }

    printf("VECTOR COMO FUE INGRESADO: \n");
    for(i=0;i<RANGO;i++)
    {
        printf("%d\n",vector[i]);
    }

    printf("VECTOR EN FORMA DECRECIENTE: \n");
    for(i=4;i>=0;i--)
    {
        printf("%d\n",vector[i]);
    }

    return 0;
}

/*Leer 20 números enteros positivos. Mostrar el vector tal como fue ingresado y luego mostrar el vector
ordenado en forma decreciente*/
