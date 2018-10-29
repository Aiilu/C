#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* f;

    f = fopen("index.txt","w");

    char msj[]="Puto el que lo lee";

    if(f==NULL)
    {
    printf("Problemas al crear el archivo");
    exit(1);
    }

    fwrite(msj, sizeof(char),strlen(msj),f);

    fclose(f);

    return 0;
}
