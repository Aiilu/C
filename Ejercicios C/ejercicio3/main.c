#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int producto;
    int cuadradoNumUno;

    printf ("Ingrese un N° distinto de 0 : ");
    scanf ("%d",&numeroUno);

    printf ("Ingrese otro N° distinto de 0 : ");
    scanf ("%d",&numeroDos);

    producto = numeroUno*numeroDos;
    printf ("El producto es: %d\n",producto);

    cuadradoNumUno = numeroUno*numeroUno;
    printf ("El cuadrado de %d\n es de %d",numeroUno,cuadradoNumUno);

    fflush (stadin);

    return 0;
}
