#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    int acum=0;

    for(i=0;i<=100;i+=3)
    {
        acum+=i;
        printf("%d\n",i);
    }

    printf("La suma de la serie es %d",acum);

    return 0;
}

/*Dise�ar un programa que imprima y sume la serie de n�meros 3,6,9,12,...,99.*/
