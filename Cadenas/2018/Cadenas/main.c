#include <stdio.h>
#include <stdlib.h>
#include <string.h> //para el uso de cadenas

int main()
{
    char cadena[20];//="perro";
    //int cantidad;
    char cadena2[50]="gato";
    int estado;

    //strcpy(cadena,"perro");

    estado=strcmp(cadena2,"armadillo");

   /* cantidad = strlen(cadena); //para contar

    printf("%d",cantidad);*/

    //printf("%s",cadena);

    printf("%d",estado);


    return 0;
}
/* //Ingresar por cadena
   //char cadena[20]="hola"; //={'h','o','l','a','\0'} extension
  char cadena[20];

  //ingresa usuario

  printf("Ingrese texto: ");
  fflush(stdin);
  //scanf("%s",&cadena); no sirve
  gets(cadena);

  printf("%s",cadena);*/

