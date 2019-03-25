#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int i;
    int numPositivos=0;
    int numNegativos=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&numero);

        while(numero == 0)
        {
            printf("ERROR. Ingrese un numero que NO SEA CERO: ");
            scanf("%d",&numero);
        }

        if(numero>0)
        {
            numPositivos+=numero;
        }
        else if(numero<0)
        {
            numNegativos+=numero;
        }
    }

    printf("La suma de los positivos es: %d\n",numPositivos);
    printf("El producto de los negativos es: %d",numNegativos);

    return 0;
}

/*Diseñar en un programa que permita ingresar 10 números, ninguno de ellos igual a cero. Se pide sumar los
positivos, obtener el producto de los negativos y luego mostrar ambos resultados*/
