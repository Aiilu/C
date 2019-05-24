#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char cadena[] = "que pasha?";
    char aux;

    f = fopen("archivo.txt", "r");

    if(f == NULL)
    {
        printf("Error\n");
        exit(1);
    }

    //fprintf(f,"Hola Archivo de Prueba, %s", cadena);

    while(!feof(f))
    {
        aux = fgetc(f);

        printf("%c",aux);
    }

    fclose(f);

    return 0;
}
