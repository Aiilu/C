#include <stdio.h>
#include <stdlib.h>
#define RANGO 10

int main()
{
    int vector[RANGO];
    int i;
    int compras;
    char resp;
    int aux;

    for(i=0;i<RANGO;i++)
    {
        printf("Dia: %d\n",i+1);
        printf("Ingrese gasto del dia: ");
        scanf("%d",&compras);

        do{

            printf("Desea agregar otro gasto? s/n \n");
            fflush(stdin);
            scanf("%c",&resp);

            if(resp == 's')
            {
            printf("Ingrese otro gasto: ");
            scanf("%d",&aux);
            compras+=aux;
            }

        }while(resp !='n');

        vector[i]=compras;

        printf("El gasto del dia %d fue de %d\n",i+1,vector[i]);
    }

    return 0;
}

/*Una persona desea saber en qué día del mes realizó más gastos en compras, para ello ingresa por teclado
día a día lo que gastó por día, cargando un vector definido en memoria. Puede haber varias o ninguna
compra para un determinado día. Informar cual fue el día de mayor gasto*/
