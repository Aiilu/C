#include <stdio.h>
#include <stdlib.h>
#define TAM 2

int main()
{
    float v[TAM];
    int i;
    float div;

    printf("Ingrese los %d numeros a dividir",TAM);

    for(i=0;i<TAM;i++)
    {
        scanf("%f",&v[i]);
    }

    div=v[0];

    for(i=1;i<TAM;i++)
    {
        div=div/v[i];
    }

    printf("El resultado de la division es %.2f",div);

    return 0;
}
