#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i;
    int j;
    int a;

    for(i=0;i<=100;i++)
    {
        if(i%5==0)
        {
            printf("%d\n",i);
        }
    }

    printf("\n\n");

    for(j=0;j<=100;j++)
    {
        if(j%7==0)
        {
            printf("%d\n",j);
        }
    }

    printf("\n\n");

    for(a=0;a<=100;a++)
    {
        if(a%7==0 && a%5==0)
        {
            printf("%d\n",a);
        }
    }

    return 0;
}

/*Calcular y generar los primeros 100 números múltiplos de 5, de 7 y de ambos*/
