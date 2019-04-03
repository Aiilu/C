#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[]={2,6,8,7,4,1,9,5,3,10};
    int i;
    int auxiliar;
    int j;

    /*for(i=0;i<10;i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d",&vector[i]);
        while(vector[i] == 0)
        {
            printf("ERROR. Ingrese un numero que no sea cero: ");
            scanf("%d",&vector[i]);
        }
    }*/

    printf("VECTOR INGRESADO: ");
    for(i=0;i<10;i++)
    {
        printf("%d\n",vector[i]);
    }

    printf("POSITIVOS FORMA DECRECIENTE: ");
    for(i=0;i<11-1;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(vector[i]<vector[j])
            {
                auxiliar=vector[i];
                vector[i]=vector[j];
                vector[j]=auxiliar;
            }
        }

        printf("%d\n",vector[i]);
    }

    printf("NEGATIVOS FORMA CRECIENTE: ");
    for(i=0;i<11-1;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(vector[i]>vector[j])
            {
                auxiliar=vector[i];
                vector[i]=vector[j];
                vector[j]=auxiliar;
            }
         }


        printf("%d\n",vector[i]);
    }

    return 0;
}

/* Leer 20 números enteros (positivos y negativos) distintos de cero. Mostrar el vector tal como fue ingresado
y luego mostrar los positivos ordenados en forma decreciente y por último mostrar los negativos ordenados
en forma creciente*/
