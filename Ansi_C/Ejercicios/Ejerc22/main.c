#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int aux;

    printf("Ingrese un numero: ");
    scanf("%d",&num1);

    printf("Ingrese otro numero: ");
    scanf("%d",&num2);

    aux=num1;
    num1=num2;
    num2=aux;

    printf("INTERCAMBIANDO NUMEROS.....\n");
    system("pause");

    printf("El primer numero ahora es %d y el segundo %d",num1,num2);

    return 0;
}

/*Dise�ar el programa necesario para que habi�ndose le�do el valor de 2 variables NUM1 y NUM2 se
intercambien los valores de las variables, es decir que el valor que ten�a NUM1 ahora lo contenga NUM2 y
viceversa*/
