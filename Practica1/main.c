#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unNumero;
    int otroNumero;
    //float unFlotante;
    //char unaLetra;
    //float suma;
    float division;

    printf ("Ingrese un N° : ");
    scanf ("%d",&unNumero);

    printf ("Ingrese otro N° : ");
    scanf ("%d",&otroNumero);

    printf ("Un N° es: %d\n",unNumero);
    printf ("Otro N° es: %d\n",otroNumero);

    division = (float)unNumero/otroNumero;
    printf ("La division da: %.2f", division);

    /*printf ("Ingrese un N° flotante: ");
    scanf ("%f",&numeroFlotante);
    printf ("Ingrese una letra: ");
    fflush (stdin);
    scanf ("%c",&unaLetra);

    printf ("El N° Flotante es: %.2f\n", numeroFlotante);
    printf ("La letra es: %c\n", unaLetra);

    suma = numeroFlotante+numeroEntero;
    printf ("La suma es: %.2f", suma);*/
return 0;
}

 /* int numeroEntero;
    float numeroFlotante;
    char unaLetra;

    numeroEntero = 55;
    numeroFlotante = 3.5;
    unaLetra = 'a';
    printf ("El Numero Entero es: %d\n El Numero Flotante es: %f\n La letra es: %c\n" , numeroEntero, numeroFlotante, unaLetra);*/
