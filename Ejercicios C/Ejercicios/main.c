#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int cont=0;
    int acum=0;
    float promedio;

    for (cont=0; cont<5; cont++)
    {

        printf ("Ingrese un N°: ");
        scanf ("%d",&num);

        acum+=num;
    }

    promedio = (float)acum/cont;
    printf ("El promedio es de %.2f",promedio);

    return 0;
}
