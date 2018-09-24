#include <stdio.h>
#include <stdlib.h>

int main()
{
   int base;
   int altura;
   float superficie;

   printf ("Ingrese base: ");
   scanf ("%d",&base);

   printf ("Ingrese altura: ");
   scanf ("%d",&altura);

   superficie = (base*altura)/2;
   printf ("La superficie del triangulo es de %.2f",superficie);

    return 0;
}
