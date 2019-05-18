#include <stdio.h>
#include <stdlib.h>

void f1(int x[], int tam);
void f2(int x[], int tam);
void f3(int* x, int tam);
void f4(int* x, int tam);

int main()
{
    int vec[] = {3,2,6,4,5};

    f1(vec,5);

    printf("\n");

    f2(vec,5);

    printf("\n");

    f3(vec,5);

    printf("\n");

    f4(vec,5);

    return 0;
}

void f1(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
      printf("%d",x[i]);
    }
}

void f2(int x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}

void f3(int* x, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",x[i]);
    }
}

void f4(int* x, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d",*(x+i));
    }
}
