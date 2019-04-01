#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base;
    float altura;
    float superficie;

    printf("Ingrese la base: ");
    scanf("%f",&base);

    printf("Ingrese la altura: ");
    scanf("%f",&altura);

    superficie = (base*altura)/2;

    printf("La superficie de un triangulo es de: %.2f",superficie);

    return 0;
}

/*Diseñar un programa que calcule la superficie de un triángulo a partir del ingreso de su base y altura y
muestre el resultado.*/
