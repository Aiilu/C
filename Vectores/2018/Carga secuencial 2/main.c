#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[5];
    int i;

  // printf("%d",vector);
    /*se gestiona a traves de las dirrec de memoria, y el subindice por cuanto se
      multiplica para dividirse.
      Esto se llama aritmetica de punteros

    Siempre estructura repetitiva*/
    for(i=0;i<5;i++) {
    //printf ("%d\n",&vector[i]); //si pongo & muestro la dirrec de memoria y queremos el valor
    printf ("%d\n",vector[i]);
    }

    return 0;
}
