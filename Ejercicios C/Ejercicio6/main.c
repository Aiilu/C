#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cont=0;
    int contPosit=0;
    int contNeg=0;

    for (cont=0; cont<10; cont++)
    {
        printf ("Ingrese un N°: ");
        scanf ("%d",&numero);

        if (numero>0)
        {
            contPosit++;
        }
        else
        {
            contNeg++;
        }
    }

    printf ("Hay %d\n N° Positivos.\n Hay %d\n N° Negativos",contPosit,contNeg);

    return 0;
}
