#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int mesa;
    int venta;
}eRest;

int main()
{
    eRest aux;
    int acum=0;

    eRest lista[] =
    {
        {1,240},
        {2,200},
        {3,0},
        {4,199},
        {5,0}
    };

    eRest* pEmp;

    pEmp = (eRest*)malloc(sizeof(eRest));

    pEmp = lista;

    for(int i=0;i<TAM;i++)
    {
        acum+=(pEmp+i)->venta;
    }

    printf("La venta total del dia fue: %d\n", acum);

    for(int i=0;i<TAM;i++)
    {
        if((pEmp+i)->venta == 0)
        {
            printf("La mesa %d no fue ocupada en todo el dia\n", (pEmp+i)->mesa);
        }
    }

    for(int i=0; i<TAM-1; i++)
    {
        for(int j=i+1; j<TAM; j++)
        {
            if((pEmp+i)->venta > (pEmp+j)->venta)
            {
                aux = *(pEmp+i);
                *(pEmp+i) = *(pEmp+j);
                *(pEmp+j) = aux;

            }
        }
    }

    printf("MESA   VENTA\n");

    for(int i=0;i<TAM;i++)
    {
        if((pEmp+i) !=0)
        {
              printf(" %d      %d  \n", (pEmp+i)->mesa, (pEmp+i)->venta);
        }

    }




    return 0;
}


/*68. Un restaurante que dispone de 50 mesas, necesita llevar cuenta de las ventas diarias. Para ello cada vez que
una mesa es ocupada se registra el número de mesa y el valor de lo que van consumiendo. Una vez que se
cierra el local se deben obtener los siguientes resultados
a- Venta total del día
b- Indicar cuales fueron las mesas que no se ocuparon en todo el día.
c- Listado ordenado por venta que muestre Nro de mesa Venta*/
