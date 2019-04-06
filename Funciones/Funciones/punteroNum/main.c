#include <stdio.h>
#include <stdlib.h>
#include "torrez.h"

int main()
{
    int x = 100;
    int flagX;
    char msj[20] = {"Ingrese un numero: "};

    flagX = getInt(&x, 3, msj);

    if(flagX == 1)
    {
    printf("X vale: %d\n",x);
    }
    else
    {
    printf("No se puedo cargar la variable");
    }

    return 0;
}
