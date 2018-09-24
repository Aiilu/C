#include <stdio.h>
#include <stdlib.h>

//Carga aleatoria:

int main ()
{
int vector[5];
vector[2]=9;   //los subindices guardan el valor del vector
vector[1]=2;
printf("%d",vector[2]); //con el cero tira basura

return 0;
}

/*Inicializar vector por extension:

int vector[10] = {1,2,3,4,5,6,7,8,9,10};

para inicializar vector por extension se usan {}

si no se coloca nada el valor por defecto es 0*/

/*Vectores inicializan en 0
   El 0 se llama limite inferior y el ultimo es el limite superior(n-1)
   int ejemplo[]---> vector
   int ejemplo[5--> cantidad de elementos que se pude guardar]

   ejemplo[2]= 9; guardar 9 en subindice 2
   printf("%d" , vector[2]);*/
