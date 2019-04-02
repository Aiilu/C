#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[10];
    int i;
    int aux;
    int j;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d",&vector[i]);
        while(vector[i] == 0)
        {
            printf("ERROR. Ingrese un numero que no sea cero: ");
            scanf("%d",&vector[i]);
        }
    }

    printf("VECTOR INGRESADO: ");
    for(i=0;i<10;i++)
    {
        printf("%d\n",vector[i]);
    }

    printf("POSITIVOS FORMA DECRECIENTE: ");
    for(i=0;i<10;i++)
    {
        for(j=0;j+1;j++)
        {
            if(vector[i]>0){
             if(vector[i]<vector[j])
             {
                 aux=vector[i];
                 vector[i]=vector[j];
                 vector[j]=aux;
            }
         }
        }

            printf("%d\n",vector[i]);

    }

    printf("NEGATIVOS FORMA CRECIENTE: ");

    return 0;
}

/* Leer 20 números enteros (positivos y negativos) distintos de cero. Mostrar el vector tal como fue ingresado
y luego mostrar los positivos ordenados en forma decreciente y por último mostrar los negativos ordenados
en forma creciente*/
