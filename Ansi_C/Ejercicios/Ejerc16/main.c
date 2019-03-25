#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num;

    printf("Ingrese un numero: ");
    scanf("%f",&num);

    if(num>0)
    {
        printf("NUMERO POSITIVO");
    }
    else if(num<0)
    {
        printf("NUMERO NEGATIVO");
    }
    else
    {
        printf("ERROR");
    }

    return 0;
}

/*Hacer el programa que nos permita introducir un número por teclado y nos informe si es positivo o
negativo*/
