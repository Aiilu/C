#include <stdio.h>
#include <stdlib.h>

void inicDelArray(int parametroVector[],int cantidad,int inicValor);
void mostrarArray(int[],int);

int main()
{
    int vector[5];
    inicDelArray(vector,5,-1);
    mostrarArray(vector,5);

    return 0;
}

void inicDelArray(int parametroVector[],int cantidad,int inicValor)
{
    for(;cantidad>0;cantidad--)
    {
        parametroVector[cantidad]=inicValor;
    }
}

void mostrarArray(int parametroVector[],int cantidad)
{
   for(;cantidad>0;cantidad--)
   {
     printf("%d\n",parametroVector[cantidad]);
   }
}

