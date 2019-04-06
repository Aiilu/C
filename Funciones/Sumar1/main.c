#include <stdio.h>
#include <stdlib.h>

int sumar1(int, int);

int main()
{
    int x;
    int y;
    //int resultado;

    printf("Ingrese un numero: ");
    scanf("%d",&x);

    printf("Ingrese otro numero: ");
    scanf("%d",&y);

    //resultado = sumar1(x,y);

    //printf("La suma es: %d ",resultado);

    printf("La suma es: %d ",sumar1(x,y));
    return 0;
}

int sumar1(int numero1, int numero2)
{
    int suma;

    suma = numero1 + numero2;

    return suma;
}
