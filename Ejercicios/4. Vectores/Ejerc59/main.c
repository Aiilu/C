#include <stdio.h>
#include <stdlib.h>
#define RANGO 10

int main()
{
    int vector[RANGO];
    int i;
    int max;
    int flag=0;

    for(i=0;i<RANGO;i++)
    {
        printf("Ingrese un valor para el indice: ");
        scanf("%d",&vector[i]);

        while(vector[i]<0)
        {
            printf("ERROR. Ingrese el valor nuevamente: ");
            scanf("%d",&vector[i]);
        }
    }

    printf("EL MAYOR ES EL: ");
    for(i=0;i<RANGO;i++)
    {
        if(vector[i]> max || flag==0)
        {
            flag = 1;
            max = vector[i];
        }
    }

    printf("%d\n",max);

    printf("VECTOR COMPLETO: \n");
    for(i=0;i<RANGO;i++)
    {
        printf("%d",vector[i]);
    }

    return 0;
}

/*Leer 20 números enteros positivos, indicar cuál es el mayor y en qué orden fue leído (a que elemento
pertenece). Mostrar el vector completo*/
