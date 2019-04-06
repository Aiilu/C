#include <stdio.h>
#include <stdlib.h>
#define RANGO 10

int main()
{
   int dias[RANGO];
    int lluvia;
    int cont=0;
    int acum=0;
    int masLluvia;
    int menosLluvia;
    int diaMayor=0;
    int diaMenor=9999;
    float prom;
    int i;

    for(i=0;i<=RANGO;i++)
    {
        printf("Ingrese la cantidad de lluvia en mm el dia %d:", i+1);
        scanf("%d",&lluvia);
        dias[i] = lluvia;
        cont++;
    }

    for(i=0;i<=RANGO;i++)
    {
        if(dias[i] > diaMayor)
        {
            masLluvia = i+1;
            diaMayor = dias[i];
        }

    }

    for(i=0;i<=RANGO;i++){

        if(dias[i] < diaMenor)
        {
            menosLluvia = i+1;
            diaMenor = dias[i];
        }
    }

    for(i=0;i<=RANGO;i++)
    {
        acum+=dias[i];
    }

    prom = acum/cont;

    printf("MAYOR CANTIDAD DE LLUVIA EN UN DIA: %d MM\n",diaMayor);
    printf("MENOR CANTIDAD DE LLUVIA EN UN DIA: %d MM\n",diaMenor);
    printf("DIA QUE MAS LLOVIO: %d\n",masLluvia);
    printf("DIA QUE MENOS LLOVIO: %d\n",menosLluvia);
    printf("PROMEDIO: %f\n",prom);

    return 0;
}
/*Se ingresa por consola la cantidad de agua caída, en milímetros día a día durante un mes. Se pide
determinar el día de mayor lluvia, el de menor y el promedio*/
