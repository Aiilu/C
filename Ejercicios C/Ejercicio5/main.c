#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int cuadradoNumUno;

    printf ("Ingrese un N°: ");
    scanf ("%d",&numeroUno);

    cuadradoNumUno = numeroUno*numeroUno;

    if (cuadradoNumUno<0)
    {

        printf ("ERROR. El N° debe ser >0 ");
    }
    else
    {

        printf ("El cuadrado del N° %d\n es %d",numeroUno,cuadradoNumUno);
    }
    return 0;
}
