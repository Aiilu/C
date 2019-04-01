#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    float resta;

    printf("Ingrese un numero: ");
    scanf("%f",&num1);

    printf("Ingrese otro numero: ");
    scanf("%f",&num2);

    resta = num1 - num2;

    printf("El valor de la resta es de: %.2f\n",resta);

    if(resta>0)
    {
      printf("RESULTADO POSITIVO");
    }
    else if(resta<0)
    {
      printf("RESULTADO NEGATIVO");
    }
    else
    {
      printf("RESULTADO CERO");
    }

    return 0;
}

/*Escribir un programa que realice las siguientes acciones:
 Limpie la pantalla
 Declare 2 variables y les asigne sendos valores
 Realice la resta de dichas variables y muestre por pantalla la leyenda "Resultado positivo" en caso de
ser mayor que cero o "Resultado negativo" si es menor que cero*/

