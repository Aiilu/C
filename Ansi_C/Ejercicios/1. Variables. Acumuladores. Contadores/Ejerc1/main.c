#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    float prom;
    int i=0;
    int acum=0;

    for(i=0;i<5;i++)
    {

        printf("Ingrese un numero: ");
        scanf("%d",&num);

        acum+=num;
    }

    prom = acum/i;

    printf("El promedio es de : %f",prom);

    return 0;
}

/*Ingresar 5 números y calcular su media*/
