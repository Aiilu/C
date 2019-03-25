#include <stdio.h>
#include <stdlib.h>

int main()
{
     int num;

     printf("Ingrese un numero: ");
     scanf("%d",&num);

     if(num%2==0)
     {
         printf("El numero es Par");
     }
     else
     {
         printf("El numero es Impar");
     }

    return 0;
}

/*Hacer el programa que nos permita introducir un número por teclado y nos informe si es par o impar*/
