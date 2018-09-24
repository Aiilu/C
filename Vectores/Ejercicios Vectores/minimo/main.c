#include <stdio.h>
#include <stdlib.h>

int main()
{
  int vector[10];
int i;
int menor;

for (i=0; i<10; i++){
   printf( "ingrese 10 numeros enteros");
   scanf("%d", &vector[i]);
}

for (i=0; i<10; i++){
    if (vector[i]< menor){
    menor=vector[i];
    }
}
printf("El menor es %d\n", menor);
    return 0;
}
