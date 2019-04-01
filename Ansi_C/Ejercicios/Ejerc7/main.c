#include <stdio.h>
#include <stdlib.h>

int main()
{

    float radio;
    float longCirc;
    float areaCirc;
    float pi;

    pi = 3.141592;

    printf("Ingrese la radio: ");
    scanf("%f",&radio);

    longCirc = 2*pi*radio;
    areaCirc = pi*radio*radio;

    printf ("La Longitud de la Circunferencia de un circulo es %f\n",longCirc);
    printf ("El area de un circulo es %f",areaCirc);

    return 0;
}

/*Diseñar un programa que calcule la longitud de la circunferencia y el área del círculo de radio dado.*/
