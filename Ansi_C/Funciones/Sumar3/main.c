#include <stdio.h>
#include <stdlib.h>

int sumar3(void);

int main()
{
    int suma;

    suma = sumar3();

    printf("La suma es: %d", suma);

    return 0;
}

int sumar3(void)
{
    int x;
    int y;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d",&x);

    printf("Ingrese otro numero: ");
    scanf("%d",&y);

    resultado = x + y;

    return resultado;
}
