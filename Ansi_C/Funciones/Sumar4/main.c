#include <stdio.h>
#include <stdlib.h>

void sumar4(void);

int main()
{
     sumar4();

    return 0;
}

void sumar4(void)
{
    int x;
    int y;
    int resultado;

    printf("Ingrese un numero: ");
    scanf("%d",&x);

    printf("Ingrese otro numero: ");
    scanf("%d",&y);

    resultado = x + y;

    printf("La suma es: %d", resultado);
}
