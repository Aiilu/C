#include <stdio.h>
#include <stdlib.h>

int calcular(int,int);

int main()
{
    int base;
    int altura;
    int superficie;

    while(base!=0 && altura!=0)
    {
     printf("Ingrese la superficie: ");
     scanf("%d",&base);
     printf("\n\n");
     printf("Ingrese la altura: ");
     scanf("%d",&altura);
     if(base==0 && altura==0)
     {
       break;
     }
     else
     {
     superficie=calcular(base,altura);
     }
    }


    printf("La superficie del triangulo es: %d",superficie);

    return 0;
}

int calcular(int b,int a)
{
    int superficie;

    superficie = b*a;

    return superficie;

}
/*1- Escribir un programa que por medio de una función calcule la superficie de un rectángulo.
 El programa continúa calculando superficies hasta que se ingresen ambos lados con valor cero.*/
