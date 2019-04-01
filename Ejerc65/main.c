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

    menu(vector);

    return 0;
}

void menu(int vector[])
{
    int opcion;
    int flag = 0;

    printf("MENU DE VECTORES\n");
    printf("1.CARGAR UN VECTOR.\n");
    printf("2.ORDENAR UN VECTOR.\n");
    printf("3.MOSTRAR UN VECTOR.\n");
    printf("4.SALIR.\n");
    printf("ELIJA UNA OPCION PARA CONTINUAR: ");
    scanf("%d",&opcion);

    switch(opcion)
    {
    case 1:
        cargarVector(vector,10);
        flag = 1;
        break;
    case 2:
        if(flag == 1)
        {
        ordenarVector(vector,10);
        }
        else
        {
            printf("Primero debe cargar el Vector\n");
        }
        break;
    case 3:
        if(flag == 1)
        {
            mostarVector(vector,10);
        }
        break;
    case 4:
        break;
    default:
        printf("Esta opcion no es valida\n");
    }

}

int cargarVector(int vector[], int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d",&vector[i]);
    }

    return 0;
}

 int ordenarVector(int vector[],int len)
 {
    int i;
    int j;
    int aux;

    for(i=0; i<len-1; i++)
	 {
	  for(j=i+1; j<len; j++)
		 {
		   if(vector[i]<vector[j])
           {
		   aux=vector[i];
		   vector[i]=vector[j];
		   vector[j]=aux;

           }
		 }
	 }

	 return 0;
 }

/*Realizar un programa que por medio de un menú de opciones y trabajando con un vector de 50 enteros me
permita:
a- Cargar el vector
b- Ordenar el vector
c- Mostrar el vector
d- Salir*/
