#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int cantImpar=0;

    for(i=0;i<=100;i++)
    {
      if(i%2!=0)
      {
          cantImpar++;
          printf("%d\n",i);
      }
    }

    printf("La cant de numeros impares es %d",cantImpar);

    return 0;
}

/*Escribir en C un programa que muestre los números impares entre 0 y 100 y que imprima cuantos impares
hay*/
