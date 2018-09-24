#include <stdio.h>
#include <stdlib.h>

int main()
{
    int radio;
    int longCircunf;
    int areaCirc;
    float pi;

    pi = 3.141592;

    printf ("Ingrese el valor de la radio: ");
    scanf ("%d",&radio);

    longCircunf = 2*pi*radio;

    areaCirc = pi*radio*radio;

    printf ("La Longitud de la Circunferencia de un circulo es %d\n",longCircunf);
    printf ("El area de un circulo es %d",areaCirc);


    return 0;
}
