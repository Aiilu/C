#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 3

int main()
{
    int legajo[T];
    //char nombres[10]; solo guarda 10 caracteres, o 10 grupos de un caracter. hay que usar matriz
    // a nombre le doy 2 dimensiones, la primera filas, la seg columnas. Hace m*m,fila x colum
    char nombres[T][21];//matriz de 10 filas de 20 caracteres
    int notas[T];
    float alturas[T];
    int i;


    for(i=0;i<T;i++) //en el mismo for pido todo los datos
    {
        printf("Ingrese legajo:");
        scanf("%d",&legajo[i]);

        printf("Ingrese nombre:");
        fflush(stdin);
        gets(nombres[i]);//si paso con[i]va a mostrar en que celda, en que caracter,vamos a leer una fila

         printf("Ingrese nota:");
        scanf("%d",&notas[i]);

         printf("Ingrese altura:");
        scanf("%f",&alturas[i]);

    }
    printf("%4s %20s %2s %5s\n" , "Legajo" , "Nombre" , "Nota" , "Altura");//para que ocupen el mismo ancho, tienen que ser variables
    for(i=0;i<T;i++)
    {
        printf("%4d %20s %2d %5f\n", legajo[i], nombres[i], notas[i], alturas[i] );
    }
    return 0;
}
    /*
    producto:
    marca
    precio
    vencimiento
    dimensiones
    tipo
    codigo*///tipo escalar se pisan, se hace con vectores paralelos
    /*vector paralelo: cada elemento tiene relacion con los mismo subindices, las mismas posiciones*/
