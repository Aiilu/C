#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int v[TAM];
    int i;
    float prom=0;
    int acum=0;

    printf("Ingrese los %d numeros",TAM);

    for(i=0;i<TAM;i++)
    {
        scanf("%d",&v[i]);
    }

    acum=v[0];

    for(i=1;i<TAM;i++)
    {
        acum+=v[i];
    }

    //printf("La suma es de %d",acum);

    prom = 1.0*acum/i;

    printf("El promedio es de %f",prom);


    return 0;
}
