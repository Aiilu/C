#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[25];
    char nombreCompleto[]="";
    int i;

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(apellido);

    strcat(nombreCompleto,apellido);
    strcat(nombreCompleto,", ");
    strcat(nombreCompleto,nombre);

    strlwr(nombreCompleto);

    nombreCompleto[0] = toupper(nombreCompleto[0]);

    for(i=0;i<strlen(nombreCompleto);i++)
    {
        if(nombreCompleto[i] == ' ')
        {
            nombreCompleto[i+1] = toupper(nombreCompleto[i+1]);
        }
    }

    puts(nombreCompleto);

    return 0;
}
