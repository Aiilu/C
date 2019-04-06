#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cantEscrita;
    char texto[]="ALOO";

    FILE* f;

    f = fopen("banco.txt", "w");

    if(f==NULL)
    {
     printf("Error de apertura");
     exit(1);
    }

    cantEscrita = fwrite(texto,sizeof(char),strlen(texto),f);
    if(cantEscrita<strlen(texto))
    {
        printf("Error al escribir el archivo");
    }

    fclose(f);

    return 0;
}

/*
 FILE* f;

    f = fopen("archivo.txt", "w");

    if(f==NULL)
    {
        printf("Problemas al crear el archivo");
        exit(1);
    }

    fprintf(f, " ");
    fprintf(f, "Hola mundo");

    fclose(f);
    */
