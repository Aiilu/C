#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    float cuadrado;

    printf ("Ingrese un N° mayor a 0: ");
    scanf ("%d",&num);

    while (num<0)
        {
            printf ("ERROR. El N° tiene que ser mayor a 0\n");
            printf ("Ingrese nuevamente: ");
            scanf ("%d",&num);
        }
    cuadrado = (float)num*num;
    printf ("El cuadrado del N° %d es: %.2f\n",num,cuadrado);

       return 0;
}
