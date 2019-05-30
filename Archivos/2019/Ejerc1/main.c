#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 3

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int estado;
} eEmpleado;

void inicializarEmp(eEmpleado* emp, int tam);
eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int id, char* nombre, char* apellido);
int buscarLibre(eEmpleado* emp, int tam);
void mostrarEmpleados(eEmpleado* emp, int tam);
void mostrarEmpleado(eEmpleado* emp);
void altaEmpleado(eEmpleado* emp, int tam);
void imprimirEmpleados(eEmpleado* emp, int tam);
char validarSeguir();

int main()
{

    eEmpleado* lista = (eEmpleado*)malloc(sizeof(eEmpleado)*T);

    if(lista == NULL)
    {
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }

    inicializarEmp(lista,T);

    altaEmpleado(lista,T);

    imprimirEmpleados(lista,T);

    free(lista);

    return 0;
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
        emp->estado = 0;
    }

    return emp;
}

eEmpleado* new_EmpleadoParam(int id, char* nombre, char* apellido)
{
    eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(emp !=NULL)
    {
        emp->id = id;
        strcpy(emp->nombre,nombre);
        strcpy(emp->apellido,apellido);
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

int buscarId(eEmpleado* emp, int tam, int id)
{
    int indice = -1;

    if(emp !=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            if((emp+i)->estado == 1 && (emp+i)->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


void altaEmpleado(eEmpleado* emp, int tam)
{
    char seguir = 's';
    int indice;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];

    if(emp ==NULL)
    {
        printf("Hubo un error, no se puede dar de Alta\n");
    }
    else
    {
        do
        {
            indice = buscarLibre(emp,tam);

            if(indice == -1)
            {
                printf("No hay lugar\n");
                system("pause");
                break;
            }
            else
            {
                printf("Ingrese id: ");
                scanf("%d",&auxInt);

                while(buscarId(emp,tam,auxInt)!=-1)
                {
                    printf("Este ID ya existe\n");
                    printf("Ingrese nuevamente: ");
                    scanf("%d",&auxInt);
                }

                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(auxCad);

                printf("Ingrese apellido: ");
                fflush(stdin);
                gets(auxCad2);

                eEmpleado* nuevoEmp = new_EmpleadoParam(auxInt,auxCad,auxCad2);

                if(nuevoEmp !=NULL)
                {
                    //el lugar donde lo quiero guardar
                    *(emp+indice) = *nuevoEmp;
                }

                seguir = validarSeguir();

                free(nuevoEmp);
            }

        }
        while(seguir == 's' || seguir =='S');

    }

}

void imprimirEmpleados(eEmpleado* emp, int tam)
{
    FILE* f;

    if(emp !=NULL && tam > 0)
    {
        f = fopen("./bin.dat","wb");

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

char validarSeguir()
{
    char seguir;

    printf("     Desea continuar? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}
