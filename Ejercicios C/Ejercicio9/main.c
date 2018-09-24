#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cont=0;
    char letra;
    int contA=0;
    int contE=0;
    int contI=0;
    int contO=0;
    int contU=0;

    for (cont=0;cont<20;cont++)
        {

        printf ("Ingrese un caracter: ");
        scanf ("%c",&letra);

    if (letra=='a') {
        contA++;
    }
    else if (letra=='e') {
        contE++;
    }
    else if (letra=='i') {
        contI++;
    }
    else if (letra=='o') {
        contO++;
    }
    else if (letra=='u') {
        contU++;
    }
    }
    printf ("Cantidad de letras A : %d\n", contA);
    printf ("Cantidad de letras E : %d\n", contE);
    printf ("Cantidad de letras I : %d\n", contI);
    printf ("Cantidad de letras O : %d\n", contO);
    printf ("Cantidad de letras U : %d\n", contU);
    return 0;
}
