#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int estado;
} Eempleado;

void mostrarEmpleado(Eempleado x);
void mostrarEmpleados(Eempleado[],int);
void ordenamiento(Eempleado[], int);
int cargarEmpleado(Eempleado[], int);
int buscarVacio(Eempleado[], int); //busca un elemento disponible

int main()
{
    Eempleado emp[T];
    int i;
    int opcion;


    for(i=0; i<T; i++)
    {
        emp[i].estado = VACIO;
    }

    do
    {
        printf("1.Alta Empleado\n");
        printf("2. Mostrar Empleado\n");
        printf("3. Ordenar Empleado\n");
        printf("4. Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            if(cargarEmpleado(emp,T)==-1)
            {
                printf("No hay espacio\n");
            }
            else
            {
                printf("Empleado generado\n");
            }
            break;
        case 2:
            mostrarEmpleados(emp,T);
            break;
        case 3:
            ordenamiento(emp,T);
            break;
        case 4:
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");
    }
    while(opcion !=4);

    return 0;
}

void mostrarEmpleado(Eempleado x)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n",x.legajo,x.nombre,x.sexo,x.sueldo);
}

void mostrarEmpleados(Eempleado y[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(y[i].estado == OCUPADO)
        {
            mostrarEmpleado(y[i]);
        }
    }

}

void ordenamiento(Eempleado y[], int tam)
{
    printf("Ordenamiento: \n");
    int i;
    int j;
    Eempleado aux;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(y[i].sueldo < y[j].sueldo)
            {
                aux = y[i];
                y[i] = y[j];
                y[j] = aux;
            }
        }
    }

    for(i=0; i<tam; i++)
    {
        if(y[i].estado == OCUPADO)
        {
            mostrarEmpleado(y[i]);

        }
    }
}

int cargarEmpleado(Eempleado y[], int tam)
{
    char auxCad[100];

    int index = buscarVacio(y,tam);

  if(index !=-1)
        {

            //cargarDatos();
            printf("Ingrese legajo: ");
            scanf("%d",&y[index].legajo);

            while(y[index].legajo<1000 || y[index].legajo>9999)
            {
                printf("ERROR. Ingrese legajo de 4 cifras: ");
                scanf("%d",&y[index].legajo);
            }

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad)>19)
            {
                printf("ERROR. Ingrese nombre menor a 19 caracteres: ");
                fflush(stdin);
                gets(auxCad);
            }

            strcpy(y[index].nombre,auxCad);

            printf("Ingrese el sexo, F/M: ");
            fflush(stdin);
            scanf("%c",&y[index].sexo);

            while(y[index].sexo != 'f' && y[index].sexo != 'm' && y[index].sexo !='F' && y[index].sexo !='M')
            {
                printf("ERROR. Ingrese F o M: ");
                fflush(stdin);
                scanf("%c",&y[index].sexo);
            }

            printf("Ingrese el sueldo: ");
            scanf("%f",&y[index].sueldo);
            while(y[index].sueldo < 0)
            {
                printf("ERROR. Ingrese un sueldo positivo: ");
                scanf("%f",&y[index].sueldo);
            }

            y[index].estado = OCUPADO;

        }

        return index;
}

int buscarVacio(Eempleado y[], int tam)
{
    int i;
    int indice = -1;

    for(i=0; i<tam; i++)
    {
        if(y[i].estado == VACIO)
        {
           indice = i;
           break;
        }
    }

    return indice;
}
