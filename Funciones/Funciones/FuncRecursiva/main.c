#include <stdio.h>
#include <stdlib.h>

long int factorial(int);

int main()
{
    int num;
    int rta;

    printf("Ingrese un numero: ");
    fflush(stdin);
    scanf("%d",&num);

    rta=factorial(num);

    printf("El factorial de %d es: %d",num,rta);

    return 0;
}

long int factorial(int n)
{
    long rta;

    if(n <= 1)
    {
        rta = 1;
    }
    else
    {
        rta = n*factorial(n-1);
    }

    return rta;
}
