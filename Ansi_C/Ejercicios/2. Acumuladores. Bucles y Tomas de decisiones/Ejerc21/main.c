#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    int numero;
    int contMult=0;

    printf("Ingrese un numero: ");
    scanf("%d",&numero);

    for(i=1;i<=numero;i++)
    {
        if(numero%3==0)
         {
            contMult++;
         }
    }

    printf("Cant de Multiplos de 3: %d",contMult);


    return 0;
}

/*Hacer el programa que nos permita contar los múltiplos de 3 desde la unidad hasta un número que
introducimos por teclado*/
