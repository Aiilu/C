#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define T 10

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
    int estado;
} eEmpleado;

int menu();
void inicializarEmp(eEmpleado* emp, int tam);
eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int, char*, char*, float);
int buscarLibre(eEmpleado* emp, int tam);
void mostrarEmpleados(eEmpleado* emp, int tam);
void mostrarEmpleado(eEmpleado* emp);
void altaEmpleado(eEmpleado* emp, int tam);
void imprimirEmpleados(eEmpleado* emp, int tam);
void guardarEmpleadosBinarios(eEmpleado* emp, int tam);
void cargarEmpleado(eEmpleado* emp, int tam);

int main()
{
    char seguir = 's';

    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)*T);

    if(lista == NULL)
    {
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }

    inicializarEmp(lista,T);

    do
    {
        switch(menu())
        {
            //verificar con r, por que no existe
        case 1:
            cargarEmpleado(lista,T);
            system("pause");
            break;
        case 2:
            altaEmpleado(lista,T);
            system("pause");
            break;
        case 3:
            mostrarEmpleados(lista,T);
            system("pause");
            break;
        case 4:
            guardarEmpleadosBinarios(lista,T);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista,T);
            system("pause");
            break;
        case 6:
            printf("Hasta luego\n");
            system("pause");
            seguir = 'n';
            break;
        default:
            printf("Esta opcion no existe\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    free(lista);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("   Menu de Opciones\n");
    printf("1. Cargar Empleados\n");
    printf("2. Alta Empleado\n");
    printf("3. Listar Empleado\n");
    printf("4. Guardar empleados archivo\n");
    printf("5. Imprimir empleados\n"); //hacer un archivo de texto
    printf("6. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
void inicializarEmp(eEmpleado* emp, int tam)
{
    if(emp !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            (emp+i)->estado = 0;
        }
    }
}

eEmpleado* new_Empleado()
{
    eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(emp !=NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre," ");
        strcpy(emp->apellido," ");
        emp->sueldo = 0;
        emp->estado = 0;
    }

    return emp;
}

eEmpleado* new_EmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{
    eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(emp !=NULL)
    {
        emp->id = id;
        strcpy(emp->nombre,nombre);
        strcpy(emp->apellido,apellido);
        emp->sueldo = sueldo;
        emp->estado = 1;
    }

    return emp;
}

int buscarLibre(eEmpleado* emp, int tam)
{
    int indice = -1;

    if(emp !=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if((emp+i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


void mostrarEmpleados(eEmpleado* emp, int tam)
{
    if(emp !=NULL && tam > 0)
    {
        printf("Id  Nombre  Apellido  Sueldo\n");

        for(int i=0; i<tam; i++)
        {
            if((emp+i)->estado == 1)
            {
                mostrarEmpleado(emp+i);
            }
        }
    }
}

void mostrarEmpleado(eEmpleado* emp)
{
    if(emp !=NULL)
    {
        printf("%d %s %s %.2f\n",emp->id,emp->nombre,emp->apellido,emp->sueldo);
    }
}

void altaEmpleado(eEmpleado* emp, int tam)
{
    int indice;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];
    float auxFloat;

    indice = buscarLibre(emp,tam);

    if(indice == -1)
    {
        printf("No hay lugar\n");
        system("pause");
    }
    else
    {

        printf("Ingrese id: ");
        scanf("%d",&auxInt);

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxCad);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(auxCad2);

        printf("Ingrese sueldo: ");
        scanf("%f",&auxFloat);

        eEmpleado* nuevoEmp = new_EmpleadoParam(auxInt,auxCad,auxCad2,auxFloat);

        if(nuevoEmp !=NULL)
        {
             //el lugar donde lo quiero guardar
            *(emp+indice) = *nuevoEmp;
        }

        free(nuevoEmp);
    }

}

void imprimirEmpleados(eEmpleado* emp, int tam)
{
    FILE* f;

    if(emp !=NULL && tam > 0)
    {
        f = fopen("./listaEmpleados.txt","w");

        if(f !=NULL)
        {
            fprintf(f,"Id  Nombre  Apellido  Sueldo\n");

            for(int i=0; i<tam; i++)
            {
                if((emp+i)->estado == 1)
                {
                     fprintf(f,"%d %s %s %.2f\n",(emp+i)->id,(emp+i)->nombre,(emp+i)->apellido,(emp+i)->sueldo);
                }
            }

            fprintf(f,"\n\n");
        }

        fclose(f);
    }
}

void guardarEmpleadosBinarios(eEmpleado* emp, int tam)
{
    FILE* f;

    if(emp !=NULL && tam > 0)
    {
        f = fopen("./empleados.bin","wb");

        if(f !=NULL)
        {
            for(int i=0; i<tam; i++)
            {
                if((emp+i)->estado == 1)
                {
                    fwrite((emp+i),sizeof(eEmpleado),1,f);
                }
            }
        }

        fclose(f);
    }
}

void cargarEmpleado(eEmpleado* emp, int tam)
{
    int indice;
    FILE* f;
    int cant;

    f = fopen("./empleados.bin","rb");

    while(!feof(f))
    {
        //voy a leer de a uno hasta que llegue a fin de fichero
        indice = buscarLibre(emp,tam);

        //si no lo lee, es x que esta corrupto o es eof
        cant = fread((emp+indice), sizeof(eEmpleado),1,f);

        if(cant < 1)
        {
            if(feof(f))
            {
            break;
            }
            else
            {
                printf("Problemas para leer el archivo\n");
            }
        }
    }

    fclose(f);

}
