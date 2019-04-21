#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 2
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

void inicVacio(Eempleado[],int);
void menu(Eempleado[], int);
int buscarVacio(Eempleado[], int);
//int altaEmpleado(Eempleado[],int);
void altaEmpleado(Eempleado x[],int tam);
void mostrarEmpleado(Eempleado);
void mostrarEmpleados(Eempleado[],int);
void menuInformes(Eempleado[], int);
void ordenarNombrexLegajo(Eempleado[],int);
//int modificarEmpleado(Eempleado[],int);
void modificarEmpleado(Eempleado x[],int tam);
int bajaEmpleado(Eempleado[],int);
int utn_validarInt(int auxNumero,int min, int max);
int buscarEmpleado(Eempleado x[],int tam, int legajo);

int main()
{

    Eempleado emp[T];

    inicVacio(emp,T);
    menu(emp,T);

    return 0;
}

void menu(Eempleado x[], int tam)
{

    int opcion;

    do
    {

        printf("1-Dar de Alta\n");
        printf("2-Mostrar Empleados\n");
        printf("3-Informes\n");
        printf("4-Modificar\n");
        printf("5-Dar de Baja\n");
        printf("6-Salir\n");
        printf("Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            altaEmpleado(x,tam);
            break;
        case 2:
            mostrarEmpleados(x,tam);
            break;
        case 3:
            menuInformes(x,tam);
            break;
        case 4:
            modificarEmpleado(x,tam);
            break;
        case 5:
            if(bajaEmpleado(x,tam) !=0)
            {
                printf("Empleado dado de Baja con exito\n");
            }
            else
            {
                printf("Baja cancelada\n");
            }
            break;
        case 6:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Opcion incorrecta\n");
        }

        system("pause");
        system("cls");

    }
    while(opcion !=6);

}

void inicVacio(Eempleado x[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        x[i].estado = VACIO;
    }
}

int buscarVacio(Eempleado x[], int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == VACIO)
        {
            index = i;
            break;
        }
    }

    return index;
}

int buscarEmpleado(Eempleado x[],int tam, int legajo)
{
   int encontre = -1;

   for(int i=0;i< tam;i++)
   {
       if(x[i].legajo == legajo && x[i].estado == 1)
       {
           encontre = i;
           break;
       }
   }

   return encontre;
}

/*int altaEmpleado(Eempleado x[],int tam)
{

    int index = buscarVacio(x,tam);

    if(index !=-1)
    {
        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d",&x[index].legajo);

        if(buscarEmpleado(x,tam,x[index].legajo) == -1)
        {
            printf("Legajo aceptado\n");
        }
        else
        {
                printf("Legajo ya ocupado. Ingrese otro: \n");
                scanf("%d",&x[index].legajo);

        }

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(x[index].nombre);

        printf("Ingrese sexo (F/M): ");
        fflush(stdin);
        scanf("%c",&x[index].sexo);

        printf("Ingrese sueldo: ");
        scanf("%f",&x[index].sueldo);

        x[index].estado = OCUPADO;
    }

    return index;
}*/

void altaEmpleado(Eempleado x[],int tam)
{

    int index = buscarVacio(x,tam);
    int legajo;
     int esta;

    if(index == -1)
    {
        printf("NO HAY LUGAR\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d",&legajo);

        esta = buscarEmpleado(x,tam,legajo);

        if(esta == -1)
        {
           x[index].legajo = legajo;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(x[index].nombre);

        printf("Ingrese sexo (F/M): ");
        fflush(stdin);
        scanf("%c",&x[index].sexo);

        printf("Ingrese sueldo: ");
        scanf("%f",&x[index].sueldo);

        x[index].estado = OCUPADO;

        printf("Dado de alta con Exito\n");

        }
        else{

            printf("Ya existe\n");
            mostrarEmpleado(x[esta]);

        }


        }
}

void mostrarEmpleado(Eempleado x)
{
    printf("Legajo: %d Nombre: %s Sexo: %c Sueldo: %.2f\n",x.legajo,x.nombre,x.sexo,x.sueldo);
}

void mostrarEmpleados(Eempleado x[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == OCUPADO)
        {
            mostrarEmpleado(x[i]);
        }
    }
}

void menuInformes(Eempleado x[], int tam)
{
    int opcion;

    do
    {
        printf("1-Ordenar x nombre y legajo\n");
        printf("2-Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            ordenarNombrexLegajo(x,tam);
            break;
        case 2:
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion !=2);
}

void ordenarNombrexLegajo(Eempleado x[],int tam)
{
    Eempleado aux;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
            else if(strcmp(x[i].nombre,x[j].nombre)==0 && x[i].legajo > x[j].legajo)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }

    mostrarEmpleados(x,tam);
}

/*int modificarEmpleado(Eempleado x[],int tam)
{
    int index = 0;
    char seguir;
    int legajoTrucho;
    float importe;

    printf("   Empleados\n");

    mostrarEmpleados(x,tam);

    printf("Ingrese el legajo del empleado a buscar: ");
    scanf("%d",&legajoTrucho);

    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == OCUPADO && legajoTrucho == x[i].legajo)
        {
            mostrarEmpleado(x[i]);

            printf("Ingrese el nuevo sueldo del legajo %d: ",legajoTrucho);
            scanf("%f",&importe);

            printf("Esta seguro de esta modificacion?\n");
            fflush(stdin);
            seguir = getchar();
            seguir = toupper(seguir);

            if(seguir == 's' || seguir == 'S')
            {
                x[i].sueldo = importe;

                index = 1;
            }
        }
    }

    return index;
}*/

void modificarEmpleado(Eempleado x[],int tam)
{
    char seguir;
    int legajoTrucho;
    float importe;

    printf("   Empleados\n");

    mostrarEmpleados(x,tam);

    printf("Ingrese el legajo del empleado a buscar: ");
    scanf("%d",&legajoTrucho);

    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == OCUPADO && legajoTrucho == x[i].legajo)
        {
            mostrarEmpleado(x[i]);

            printf("Ingrese el nuevo sueldo del legajo %d: ",legajoTrucho);
            scanf("%f",&importe);

            printf("Esta seguro de esta modificacion?\n");
            fflush(stdin);
            seguir = getchar();
            seguir = toupper(seguir);

            if(seguir == 's' || seguir == 'S')
            {
                x[i].sueldo = importe;
                printf("Modificacion exitosa\n");
            }
            else
            {

               printf("Modificacion cancelada\n");
            }
        }
    }
}

int bajaEmpleado(Eempleado x[],int tam)
{
    int index = 0;

    char seguir;
    int legajoTrucho;

    printf("   Empleados\n");

    mostrarEmpleados(x,tam);

    printf("Ingrese el legajo del empleado a buscar: ");
    scanf("%d",&legajoTrucho);

    for(int i=0; i<tam; i++)
    {
        if(x[i].estado == OCUPADO && legajoTrucho == x[i].legajo)
        {
            mostrarEmpleado(x[i]);

            printf("Esta seguro de matar a este empleado?\n");
            fflush(stdin);
            seguir = getchar();
            seguir = toupper(seguir);

            if(seguir == 's' || seguir == 'S')
            {
                x[i].estado = VACIO;

                index = 1;
            }
        }
    }

    return index;
}
