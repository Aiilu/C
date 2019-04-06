#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int i;
    int flag=0;
    int max;
    int min;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);

        if(num>max || flag==0)
        {
            max=num;
        }
        if(num<min || flag==0)
        {
            min=num;
            flag=1;
        }
    }

    printf("El mayor numero ingresado es: %d\n",max);
    printf("El menor numero ingresado es: %d",min);

    return 0;
}

/*Hacer unprograma que imprima el mayor y el menor de una serie de 5 números que vamos introduciendo
por teclado*/
