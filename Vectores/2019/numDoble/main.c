#include <stdio.h>
#include <stdlib.h>
#define LEN 5

void duplicarNum(int[],int);

int main()
{
    int vec[]={2,6,12,7,8};

    duplicarNum(vec,LEN);

    return 0;
}

void duplicarNum(int x[],int tam)
{
    int i;
    int resultado[5];

    for(i=0;i<tam;i++)
    {
        resultado[i] = x[i]*2;
    }

    for(i=0;i<tam;i++)
    {
        printf("El doble de %d es %d\n",x[i],resultado[i]);
    }
}
