#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vecA[3]={11,2,3};
    int vecB[3]={10,9,2};
    int vecC[3];
    int i;

    for(i=0;i<3;i++)
    {
        if(vecA[i] >= vecB[i])
        {
            vecC[i] = vecA[i];
        }
        else
        {
            vecC[i] = vecB[i];
        }
    }

    for(i=0;i<3;i++)
    {
    printf("%d\n",vecC[i]);
    }

    return 0;
}

/*Leer dos vectores A y B de dimensión 100. Generar un tercer vector C de 100 elementos donde la
componente C[ i ] sea igual al mínimo valor de A[ i j y B[ i ]. Imprimir los tres vectores*/
