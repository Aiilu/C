#include <stdio.h>
#include <stdlib.h>

int main()
{

int vec[5];
int i;

for(i=0;i<5;i++)
{
    printf("Ingrese un numero: \n");
    scanf("%d",vec+i); // lo guardo en vec + i ( corro en 1 la posicion del vector )
}

for(i=0;i<5;i++)
{
    printf("\n %d \n",*(vec+i)); //antes se mostraba asi vec[i]
}
    return 0;
}
