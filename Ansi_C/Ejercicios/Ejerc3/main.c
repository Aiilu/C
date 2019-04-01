#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    int prod;
    int cuad;

    printf("Ingrese un numero: ");
    scanf("%f",&num1);

    while(num1 <=0)
    {
        printf("ERROR. Ingrese un numero MAYOR A CERO: ");
        scanf("%f",&num1);
    }

    printf("Ingrese otro numero: ");
    scanf("%f",&num2);

    while(num2 <=0)
    {
        printf("ERROR. Ingrese un numero MAYOR A CERO: ");
        scanf("%f",&num2);
    }

    prod = num1*num2;
    cuad = num1*num1;

    printf("El producto es de: %d\n",prod);
    printf("El cuadrado de num1 es: %d",cuad);

    return 0;
}

/*Escribir un programa que realice las siguientes acciones
 Limpie la pantalla
 Asigne a 2 variables numero1 y numero2 valores distintos de cero
 Efectúe el producto de dichas variables
 Muestre el resultado pos pantalla
 Obtenga el cuadrado de numero1 y lo muestre par pantalla*/
