#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int v[TAM];
    int mult;
    int i;

    printf("Ingrese los %d numeros a multiplicar",TAM);

    for(i=0;i<TAM;i++)
    {
        scanf("%d",&v[i]);
    }

    mult=v[0];

    for(i=1;i<TAM;i++)
    {
        mult*=v[i];
    }

    printf("La multiplicacion da %d",mult);

    return 0;
}
