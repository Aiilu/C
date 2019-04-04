#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    int numero;
    int suma=0;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    for(i=numero;i<=numero;i--)
    {
        suma+=numero;
    }

    printf("La suma de los numeros que le anteceden es %d",suma);

    return 0;
}

/*Ingresar un número entero por consola y efectuar la suma de todos los números que le anteceden,
comenzando desde 0 y mostrar el resultado por pantalla*/
