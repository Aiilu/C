#include <stdio.h>
#include <stdlib.h>

/*
Modifico una variable, pasandole su direccion de memoria como un puntero.
*/



void miFuncion(int* x);

int main()
{

    int x=5;

    miFuncion(&x);

    printf(" %d \n ",x);


    return 0;
}

void miFuncion(int* x)
{
    *x=35; // de esta manera le indico que modifique la direccion de memoria de x.

}
