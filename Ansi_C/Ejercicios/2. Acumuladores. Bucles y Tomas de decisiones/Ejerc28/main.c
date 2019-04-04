#include <stdio.h>
#include <stdlib.h>

int main()
{

  int a=0;
  int j;
  int i;

    for (j=2;j<=100;j++){//por definicion el 1 no es primo, se empieza en 2
         for(i=1;i<=100;i++)//divide a j entre los números del 1 al 100
         {
           if(j%i==0) // si num1 módulo de i es 0, incrementamos a en 1.
           a++;
         }
           if (a==2){ //si solo tiene dos números divisores entonces es primo y se imprime
            printf("%d\n", j);
                    }
                        }
    return 0;
}

/*Escribir en y codificar en C un programa que muestre los números primos comprendidos entre 0 y 100*/
