#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;

}ePendrive;

int cargarPendrive(ePendrive*);
void mostrarPendrive(ePendrive*);

int main()
{
    ePendrive miPendrive;

    if(cargarPendrive(&miPendrive))
    {
    mostrarPendrive(&miPendrive);
    }

    return 0;
}

int cargarPendrive(ePendrive* pen)
{
    int todoOk = 0;

    if(pen !=NULL)
    {

    printf("\nIngrese codigo de Pendrive: ");
    scanf("%d",&pen->codigo);

    printf("\nIngrese la marca: ");
    fflush(stdin);
    gets(pen->marca);

    printf("\nIngrese su capacidad: ");
    scanf("%d",&pen->capacidad);

    printf("\nIngrese el precio: ");
    scanf("%f",&pen->precio);

    todoOk = 1;
    }

    return todoOk;
}

void mostrarPendrive(ePendrive* pen)
{
   /*printf("\nCodigo pendrive: %d", pen->codigo);
   printf("\nMarca del pendrive: %s", pen->marca);
   printf("\nCapacidad del pendrive: %d", pen->capacidad);
   printf("\nPrecio del pendrive: %.2f", pen->precio);*/

   if(pen !=NULL)
   {

   printf("%d %s %d %.2f", pen->codigo, pen->marca, pen->capacidad, pen->precio);
   }
}
