#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    /*int numero[]={1,2,3,4,5};
    int i;
    int suma=0;

    for (i=0;i<5;i++)
    {
        suma+=numero[i];
    }

    printf("La suma de los numeros es: %d",suma);*/

   //SI INGRESO YO LOS NUMEROS
    int v[TAM];
    int i;
    int suma;

    printf("Ingrese los %d numeros a sumar",TAM);

    for(i=0;i<TAM;i++)
    {
        scanf("%d",&v[i]);
    }

    suma=v[0];

    for(i=1;i<TAM;i++)
    {
        suma+=v[i];
    }

    printf("La suma es de %d",suma);

    return 0;
}
