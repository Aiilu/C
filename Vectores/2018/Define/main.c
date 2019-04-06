#include <stdio.h>
#include <stdlib.h>
#define T 10

//cambia T a 10 en todo el programa al compilar
//#define T 10 ----> todo lo que se ponga con T va a valir 10

int main ()
{
int vector[5];
int i;
for(i=0;i<T;i++)             // va a iterar hasta que llegue al valor asignado a T
{
printf("Ingrese un numero");
scanf("%d", &vector[i]);
}

return 0;
}

int const Q=10;   // valor de constante que permanecera por todo el programa sin modificar. (Es de solo lectura)



/*Dif:


la variable constante ocupa espacio de memoria en cambio Define no ocupa lugar


no usar constantes*/
