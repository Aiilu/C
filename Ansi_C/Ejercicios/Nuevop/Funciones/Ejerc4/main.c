#include <stdio.h>
#include <stdlib.h>
#define T 10

void buscar(int x[], int tam);

int main()
{

    int i;
    int x[T];

    for(i=0;i<T;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&x[i]);
    }

    buscar(x,T);


    return 0;
}

void buscar(int x[], int tam)
{
   int i;
   int valor;
   int cont = 0;
   int flag = 0;

   printf("Ingrese el numero a buscar: ");
   scanf("%d",&valor);

   for(i=0;i<tam;i++)
   {
       if(x[i] == valor)
       {
           cont++;
           flag = 1;
       }
   }
        printf("El numero %d se repite %d veces\n",valor,cont);

        if(flag==0)
        {
            printf("El numero no se encontro\n");
        }
}

/*4- Cargar un vector de 20 elementos con n�meros reales.
Usar una funci�n para ver la cantidad de veces que se repite un n�mero en el vector.
La funci�n debe tener el siguiente prototipo
intbuscar(float num)
Donde num es el n�mero a buscar dentro del vector.
La funci�n retorna un int que indica la cantidad de veces que se encontr� num.
De no encontrarse el n�mero se debe retornar 0 (cero) e informar desde el main que el n�mero no se encontr�.*/
