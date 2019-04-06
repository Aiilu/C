#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    int numero3;
    int numero4;

    printf("Ingrese el primer numero: ");
    scanf("%d",&numero1);

    printf("Ingrese el segundo numero: ");
    scanf("%d",&numero2);

    printf("Ingrese el tercer numero: ");
    scanf("%d",&numero3);

    printf("Ingrese el cuarto numero: ");
    scanf("%d",&numero4);

    if(numero1>= numero2 && numero1>= numero3 && numero1>= numero4)
    {
        printf("El numero mas alto es el primero que ingreso: %d",numero1);
    }
    else if(numero2>= numero1 && numero2>= numero3 && numero2>= numero4)
    {
        printf("El numero mas alto es el segundo que ingreso: %d",numero2);
    }
    else if(numero3>= numero1 && numero3>= numero2 && numero3>= numero4)
    {
        printf("El numero mas alto es el tercero que ingreso: %d",numero3);
    }
    else if(numero4>= numero1 && numero4>= numero2 && numero4>=numero3)
    {
        printf("El numero mas alto es el cuarto que ingreso: %d",numero4);
    }

    return 0;
}

/*. Diseñar un programa que lea 4 números e imprima el mayor de los cuatro*/
