#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int contador = 0;

    printf( "\n " );

    for ( numero = 1 ; numero <= 100 ; numero += 2 )
    {
        contador++;
        printf( "%d\n ", numero );
    }

    printf("Cantidad de impares: %d\n" , contador );

    return 0;
}
