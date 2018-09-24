#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5];
    int i;
    for(i=0;i<6;i++) {
        printf("Ingrese un numero");
        scanf("%d",&vector[i]); //si ponemos algo, se desborda, no pertenece al valor
    }
      //printf("%d",vector);

    for(i=0;i<6;i++) {
    printf ("%d\n",vector[i]);
    }
    return 0;
}
//no puedo leer el valor, pero si mostrarlo
