#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;

}ePendrive;

void mostrarPendrive(ePendrive*);
ePendrive* new_pendrive();

int main()
{
    ePendrive* pen1, *pen2;

    pen1 = new_pendrive();
    pen2 = new_pendrive();

    mostrarPendrive(pen1);
    mostrarPendrive(pen2);

    free(pen1);
    free(pen2);

    return 0;
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

ePendrive* new_pendrive()
{
    ePendrive *p;

    p = (ePendrive*) malloc(sizeof(ePendrive));

    if(p == NULL)
    {
        p->codigo = 0;
        strcpy(p->marca,"");
        p->capacidad = 0;
        p->precio = 0;
    }

    return p;
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
