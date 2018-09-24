#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int prod;
    int cuad;

    printf ("Ingrese un N°: ");
    scanf ("%d",&num1);

    printf ("Ingrese un N°: ");
    scanf ("%d",&num2);

    prod = (float)num1*num2;
    printf ("El producto es: %d\n",prod);

    cuad = (float)num1*num2;
    printf ("El cuadrado del numero %d\n es %d",num1,cuad);

     return 0;
}
