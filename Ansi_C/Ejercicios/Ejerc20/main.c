#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    for(i=1;i<=numero;i++)
    {
        printf("%d\n",i);
    }

    return 0;
}

/*Hacer el programa que imprima todos los números naturales que hay desde la unidad hasta un número que
introducimos por teclado*/
