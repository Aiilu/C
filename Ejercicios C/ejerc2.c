#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    float suma;

    printf ("Ingrese un N°:");
    scanf ("%d",&num1);

    printf ("Ingrese otro N°:");
    scanf ("%d",&num2);

    suma = (num1+num2);
    printf ("La suma es: %.2f",suma);

    return 0;
}

