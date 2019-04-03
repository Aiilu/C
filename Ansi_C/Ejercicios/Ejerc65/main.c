#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int mostrarMenu();
int cargarVector(int[], int);
int ordenarVector();
int mostarVector(int[], int);
int mostrarVectorOrdenado(int vector[], int len);

int main()
{
    int vector[TAM];
    char seguir='s';
    char validar='w';

    do
    {
        switch(mostrarMenu())
        {
        case 1:
            cargarVector(vector,TAM);
            seguir = 's';
            break;
        case 2:
            ordenarVector(vector,TAM);
            validar = 'w';
            break;
        case 3:
            if(validar == 'w')
            {
             mostrarVectorOrdenado(vector,TAM);
            }
            else
            {
            mostarVector(vector,TAM);
            }
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Opcion Invalida\n");
            break;
        }

        system("pause");
    }
    while(seguir == 's');

    return 0;
}

int mostrarMenu()
{
    int opcion;

    printf("MENU DE VECTORES\n");
    printf("1.CARGAR UN VECTOR.\n");
    printf("2.ORDENAR UN VECTOR.\n");
    printf("3.MOSTRAR UN VECTOR.\n");
    printf("4.SALIR.\n");
    printf("ELIJA UNA OPCION PARA CONTINUAR: ");
    scanf("%d",&opcion);

    return opcion;
}

int cargarVector(int vector[], int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        printf("Ingrese un valor: ");
        scanf("%d\n",&vector[i]);
    }

    return 0;
}

 int ordenarVector()
 {

    printf("SE ESTA ORDENANDO EL VECTOR\n");

	 return 0;
 }

 int mostarVector(int vector[], int len)
 {
     int i;

     for(i=0;i<len;i++)
     {
         printf("%d\n",vector[i]);
     }

     return 0;
 }

 int mostrarVectorOrdenado(int vector[], int len)
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

		 printf("%d\n",vector[i]);
	 }

	 return 0;
 }



/*Realizar un programa que por medio de un menú de opciones y trabajando con un vector de 50 enteros me
permita:
a- Cargar el vector
b- Ordenar el vector
c- Mostrar el vector
d- Salir*/
