#include <stdio.h>
#include <stdlib.h>

void menu();
int cargarVector(int[], int);
int ordenarVector(int[], int);
int mostarVector(int[], int);
int salir(int[],int);

int main()
{
    int vector[10];

    menu();

    return 0;
}

void menu(int vector[])
{
    int opcion;

    printf("**********MENU DE VECTORES**********\n");
    printf("*ELIJA UNA OPCION PARA CONTINUAR:***\n");
    printf("*1)CARGAR UN VECTOR.****************\n");
    printf("*2)ORDENAR UN VECTOR.***************\n");
    printf("*3)MOSTRAR UN VECTOR.***************\n");
    printf("*4)SALIR.***************************\n");
    printf("************************************\n");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        cargarVector();
        break;
    case 2:
        ordenarVector();
        break;
    case 3:
        mostrarVector();
        break;
    case 4:
        salir();
        break;
    default:
        printf("Esta opcion no es valida\n");
        break;
    }

}

int cargarVector(int vector[])
{

    for(int i=0; i<10; i++)
    {
        printf("Ingrese el %d° numero: \n", i);
        scanf("%d", vector[i]);
    }

    return 0;
}

int ordenarVector(int vector[], int 10)
{
   int i,j;
   int temp;

   for(i=1;i<10;i++)
   {
        temp = vector[i];
        j=i-1;

        while(j>=0 && temp<vector[j])
        {
            vector[j+1] = vector[j];
            j--;
        }

        vector[j+1]=temp;
    }

    return 0;
}

int mostarVector(int vector[],10)
{
    for(i=0, i<10;i++)
        printf("-%d-", vector[i]);

        return 0;
}

int salir(int vector[],10)
{
    for(i=0, i<10;i++)
        printf("-%d-", vector[i]);

        return 0;
}
/*Realizar un programa que por medio de un menú de opciones y trabajando con un vector de 50 enteros me
permita:
a- Cargar el vector
b- Ordenar el vector
c- Mostrar el vector
d- Salir*/
