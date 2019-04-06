#include <stdio.h>
#include <stdlib.h>

int main()
{
int vector[10];
int i;

for (i=0; i<10; i++){
   printf( "ingrese 10 numeros enteros");
   scanf("%d", &vector[i]);
}

int mayor;
int menor;

for (i=0; i<10; i++){
    if (vector[i]> mayor){
    mayor=vector[i];
    }

    if(vector[i]<menor){
    menor=vector[i];
    }
}
printf("El mayor es %d\n", mayor);
printf("El menor es %d\n", menor);
    return 0;
}
