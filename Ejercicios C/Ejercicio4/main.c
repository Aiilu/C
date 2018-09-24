#include <stdio.h>
#include <stdlib.h>

int main()
{
    int valorUno;
    int valorDos;
    float resta;

    printf ("Ingrese un valor: ");
    scanf ("%d",&valorUno);

    printf ("Ingrese otro valor: ");
    scanf ("%d",&valorDos);

    resta = valorUno-valorDos;
    printf ("La resta es: %.2f\n",resta);

    if (resta>0)
    {

        printf ("Resultado Positivo");
    }

    else if (resta<0)
    {

        printf ("Resultado Negativo");
    }

    else
    {

        printf ("Resultado Cero");
    }

    fflush (stadin);
    return 0;
}
