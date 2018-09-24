#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cont=0;
    int acum=0;
    float promedio;

    for (cont=0;cont<5;cont++)
    {
        printf ("Ingrese un N°:");
        scanf ("%d",&numero);

        acum+=numero;
    }

    promedio = (float)acum/cont;
    printf ("El promedio es: %.2f",promedio);
   /* int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroCuatro;
    int numeroCinco;
    float media;

    printf ("Ingrese el num: ");
    scanf ("%d", &numeroUno);

    printf ("Ingrese el num: ");
    scanf ("%d", &numeroDos);

    printf ("Ingrese el num: ");
    scanf ("%d", &numeroTres);

    printf ("Ingrese el num: ");
    scanf ("%d", &numeroCuatro);

    printf ("Ingrese el num: ");
    scanf ("%d", &numeroCinco);

    media = (numeroUno+numeroDos+numeroTres+numeroCuatro+numeroCinco)/5;

    printf ("El promedio es de: %.2f", media);*/



    return 0;
}
