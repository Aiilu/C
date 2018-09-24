#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    float suma;

    printf ("Ingrese un N°: ");
    scanf ("%d",&numeroUno);

    printf ("Ingrese un N°: ");
    scanf ("%d",&numeroDos);

    suma = numeroUno+numeroDos;
    printf ("La suma es: %.2f",suma);

    return 0;
}
