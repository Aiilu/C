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

/*4- Cargar un vector de 20 elementos con números reales.
Usar una función para ver la cantidad de veces que se repite un número en el vector.
La función debe tener el siguiente prototipo
intbuscar(float num)
Donde num es el número a buscar dentro del vector.
La función retorna un int que indica la cantidad de veces que se encontró num.
De no encontrarse el número se debe retornar 0 (cero) e informar desde el main que el número no se encontró.*/
