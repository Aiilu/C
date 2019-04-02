#include <stdio.h>
#include <stdlib.h>

int contarPares(int vec[],int tam);

int main()
{
    int vec[]={2,4,6,5,9,11};
    int num;

    num=contarPares(vec,6);

    printf("Hay %d Nª Pares",num);

    return 0;
}

int contarPares(int vec[],int tam)
{
    int i;
    int cont=0;

    for(i=0;i<tam;i++)
    {
        if(vec[i] %2 == 0)
        {
            cont++;
        }
    }

    return cont;
}
