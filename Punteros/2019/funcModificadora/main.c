#include <stdio.h>
#include <stdlib.h>

void funcionModificadora(int* p);

int main()
{
    int x = 100;
    int* q;
    int* p;

    funcionModificadora(&x);

    printf("%d\n",x);

    q = &x;

    p = q;

    printf("P es igual a Q?\n");

    if(p==q)
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
