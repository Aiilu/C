#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int cuad;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    cuad = numero*numero;

    while(numero <0)
    {
         printf("ERROR. El numero debe ser mayor que cero: ");
         scanf("%d",&numero);
    }

    /*
    if(num <0)
    {
      printf("ERROR. El numero debe ser mayor que cero; );
      scanf("%d",&numero);
    }
    else
    {
      printf("El cuadrado del numero es: %d",cuad);
    }*/

    printf("El cuadrado del numero es: %d",cuad);

    return 0;
}

/*Escribir el programa necesario para calcular y mostrar el cuadrado de un número. El número debe ser
mayor que cero, en caso de error que aparezca el mensaje "ERROR, el número debe ser mayor que cero"*/
