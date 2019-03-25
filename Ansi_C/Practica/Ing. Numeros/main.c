#include <stdio.h>
#include <stdlib.h>

int suma(int,int);

float promedio(int);

int main()
{
    int num;
    int num2;
    int resultado;
    float prom;

    printf("Ingrese un numero: ");
    scanf("%d",&num);

    printf("Ingrese un numero: ");
    scanf("%d",&num2);

    resultado = suma(num,num2);

    printf("El resultado es: %d", resultado);

    prom = promedio(resultado);

    printf("El promedio es: %.2f", prom);

    return 0;
}

int suma(int num1, int num2)
{
    int resultado;

    resultado = num1+num2;

    return resultado;
}

float promedio(int resultadoSuma)
{
    int prom;

    prom = resultadoSuma/2;

    return prom;
}

