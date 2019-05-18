#include <stdio.h>
#include <stdlib.h>

void funcionModificadora(int* p);

int main()
{
    int x;

    printf("Ingrese un numero: ");
    scanf("%d",&x);

    int* q;
    int* p;

    funcionModificadora(&x);

    printf("%d\n",x);

    q = &x;

    p = q;

    //Los punteros empiezan con 0x

    printf("P es igual a Q?\n");

    if(p == q)
    {
        printf("Si\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}

void funcionModificadora(int* p)
{
    *p = 2000;
}
