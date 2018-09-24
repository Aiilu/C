#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    int superficie;

    printf ("Ingrese base: ");
    scanf ("%d",&base);

    printf ("Ingrese altura: ");
    scanf ("%d",&altura);

    superficie = ((float)base*altura)/2;
    printf ("La superficie de un triangulo es de %d",superficie);


      return 0;
}
