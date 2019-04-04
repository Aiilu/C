#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int mesa[TAM]={1,2,3,4,5};
    int venta[TAM]={240,200,0,199,0};
    int i;
    int j;
    int aux;
    int acum=0;

    for(i=0;i<TAM;i++)
    {
        acum=acum+venta[i];
    }

    printf("La venta total del dia fue: %d\n", acum);

    for(i=0;i<TAM;i++)
    {
        if(venta[i] == 0)
        {
            printf("La mesa %d no fue ocupada en todo el dia\n", mesa[i]);
        }
    }

    for(i=0; i<TAM-1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(venta[i]>venta[j])
            {
                aux=venta[i];
                venta[i]=venta[j];
                venta[j]=aux;

                aux=mesa[i];
                mesa[i]=mesa[j];
                mesa[j]=aux;
            }
        }
    }

    printf("MESA   VENTA\n");

    for(i=0;i<TAM;i++)
    {
        printf(" %d      %d  \n", mesa[i], venta[i]);

    }




    return 0;
}


/*68. Un restaurante que dispone de 50 mesas, necesita llevar cuenta de las ventas diarias. Para ello cada vez que
una mesa es ocupada se registra el número de mesa y el valor de lo que van consumiendo. Una vez que se
cierra el local se deben obtener los siguientes resultados
a- Venta total del día
b- Indicar cuales fueron las mesas que no se ocuparon en todo el día.
c- Listado ordenado por venta que muestre Nro de mesa Venta*/
