#include <stdio.h>
#include <stdlib.h>

int main()
{
int vector[10];
int i;
int mayor;

for (i=0; i<10; i++){
   printf( "ingrese 10 numeros enteros");
   scanf("%d", &vector[i]);
}

for (i=0; i<10; i++){
    if (vector[i]> mayor){
    mayor=vector[i];
    }
}
printf("El mayor es %d\n", mayor);

    return 0;
}
