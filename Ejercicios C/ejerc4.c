#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    float resta;

    printf ("Ingrese un N°: ");
    scanf ("%d",&num1);

    printf ("Ingrese un N°: ");
    scanf ("%d",&num2);

    resta = (num1-num2);
    printf ("La resta es: %.2f\n",resta);

    if (resta>0) {
        printf ("Resultado positivo");
    }
    else {
        printf ("Resultado negativo");
    }



       return 0;
}
