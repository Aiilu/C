
#include <stdio.h>
#include <stdlib.h>
#include "Calculos2.h"

int sumarValores(int a, int b)
{
    return a+b;
}

int restarValores(int a, int b)
{
    return a-b;
}

float dividirValores(float a,float b)
{
    return a/b;
}

int multiplicarValores(int a, int b)
{
    return a*b;
}
int factorial(int a)
{
    long long int factorA;
    int factorialDeA;
    factorA=1;
    for (factorialDeA = a; factorialDeA >= 1; factorialDeA--)
        {
            factorA = factorA * factorialDeA;
        }
        return printf("\nEl factorial del valor %d es: %d ",a,factorA);

}
