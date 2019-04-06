#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int menu();
void hacerBoleta(int[], int[], int);
void sacarGanancias(int[], int[], int);

int main()
{
    char resp = 's';
    int codVendedor[TAM]={1,2,3};
    int precVendedor[TAM]={1200,1500,2000};

    do{
        switch(menu())
        {
      case 1:
          //hacerBoleta(codVendedor,precVendedor,TAM);
        break;
      case 2:
          sacarGanancias(codVendedor,precVendedor,TAM);
        break;
      case 3:
        resp = 'n';
        break;
      default:
        printf("Esta opcion no existe\n");
        }

    }while(resp!='n');

    return 0;
}

int menu()
{
    int opcion;

    printf("1-Ingresar Boleta\n");
    printf("2-Ganancia\n");
    printf("3-Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

/*void hacerBoleta(int codigo[], int precio[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese el numero de vendedor: ");
        scanf("%d",&codigo[i]);

        printf("Ingrese el valor de lo vendido: ");
        scanf("%d",&precio[i]);

        printf("\n\n");
    }
}*/

void sacarGanancias(int codigo[], int precio[], int tam)
{
    int i;
    int acum1=0;
    int acum2=0;
    int acum3=0;
    int uno;
    int dos;
    int tres;

    for(i=0;i<tam;i++)
    {
      if( i == 0)
      {
          acum1+=precio[i];
      }
      if( i == 1)
      {
          acum2+=precio[i];
      }
      if( i == 2)
      {
          acum3+=precio[i];
      }
    }

    uno = acum1*5/1000;
    dos = acum2*5/1000;
    tres= acum3*5/1000;

    printf("Ganancia de %d del vendedor numero %d\n",uno,codigo[0]);
    printf("Ganancia de %d del vendedor numero %d\n",dos,codigo[1]);
    printf("Ganancia de %d del vendedor numero %d\n",tres,codigo[2]);
}

/*En una tienda de artículos para caballeros al final del día se carga en la computadora las boletas que
confeccionaron los distintos vendedores para saber cuánto fue la comisión del día de cada uno de ellos. Los
datos que se ingresan (por boleta) son: el número de vendedor y el importe. Cuando no hay más boletas
para cargar se ingresa 0. Teniendo en cuenta que el negocio tiene 3 vendedores y que el porcentaje sobre
las ventas es del 5%, indicar cuánto ganó cada vendedor en el día*/
