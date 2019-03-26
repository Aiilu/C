#include "torrez.h"

int obtenerMaximo(int x, int y, int z)
{
    int max;

    if(x>=y && x>z)
    {
        printf("El maximo es el primer numero ingresado: %d",x);
        max=x;
    }
    else if(y>x && y>=z)
    {
        printf("El maximo es el segundo numero ingresado: %d",y);
        max=y;
    }
    else
    {
        printf("El maximo es el tercer numero ingresado: %d",z);
        max=z;
    }

    return max;
}

