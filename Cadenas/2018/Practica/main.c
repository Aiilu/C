#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char cadena1[5];
    char cadena2[100]="Hola como estas?";

    strncpy(cadena1,cadena2,4);//copia el origen al destino y la cant de caracteres

    puts(cadena1);
    return 0;
}
