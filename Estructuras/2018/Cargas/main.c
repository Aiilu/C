#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    printf(" Ingrese numero 1: ");
    scanf( "%d",  & num1);
    printf(" Ingrese numero 2: ");
    scanf( "%d", & num2);
    printf(" Ingrese numero 3: ");
    scanf( "%d", & num3);
    if(!(num1== num2  || num1 == num3 &&num3== num2  || num3 == num1 ))
    {
        if (num1<num2 && num1>num3)
        {
            printf(" el numero del medio es: %d ", num1);
        }
        else if(num2>num1 && num2<num3)
        {
            printf(" el numero del medio es: %d", num2);

        }
        else
        {

            printf(" el numero del medio es: %d", num3);
        }

    }
    else
    {
        printf("ERROR. tienes dos o tres numeros iguales");
    }
    return 0;
}
