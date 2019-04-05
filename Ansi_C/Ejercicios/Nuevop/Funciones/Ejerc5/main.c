#include <stdio.h>
#include <stdlib.h>
#define T 5

int menu();
void cargarVector(int x[],int tam);
void mostrarVector(int x[], int tam);

int main()
{
   char seguir = 's';
   int array[T];

   do{
    switch(menu())
    {
  case 1:
      cargarVector(array,T);
      seguir = 's';
    break;
  case 2:
      mostrarVector(array,T);
    break;
  case 3:
    break;
  default:
    printf("Opcion no valida\n");
    }
    }while(seguir !='n');

    return 0;
}

/*Cuando se elija la opción (dentro de main) se debería llamar a la función que realice la tarea correspondiente.
1- Se carga un vector de 30 enteros.
2- Se muestra el vector.
3- Salir del programa.*/

int menu()
{
    int opcion;

    printf("1-Ingreso de Datos\n");
    printf("2-Mostrar\n");
    printf("3-Salir\n");
    printf("Ingrese una opcion del menu: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void cargarVector(int x[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&x[i]);
    }
}

void mostrarVector(int x[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("%d\n",x[i]);
    }
}
