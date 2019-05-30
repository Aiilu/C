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

    int opcion;
    char seguir = 's';

    if(lista == NULL)
    {
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }

    inicializarEmp(lista,T);

    do
    {
        printf("1. Cargar Empleados\n");
        printf("2. Alta de Empleados\n");
        printf("3. Modificacion de Empleados\n");
        printf("4. Baja de Empleados\n");
        printf("5. Buscar x Apellido\n");
        printf("6. Listar\n");
        printf("7. Guardar Empleados\n");
        printf("8. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            cargarEmpleado(lista,T);
            break;
        case 2:
            altaEmpleado(lista,T);
            break;
        case 3:
            darModificacion(lista,T);
            break;
        case 4:
            darBaja(lista,T);
            break;
        case 5:
            buscarApellido(lista,T);
            break;
        case 6:
            mostrarEmpleados(lista,T);
            break;
        case 7:
            imprimirEmpleados(lista,T);
            break;
        case 8:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');

    system("pause");

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


void mostrarEmpleados(eEmpleado* emp, int tam)
{
    if(emp !=NULL && tam > 0)
    {
        printf("Id  Nombre  Apellido\n");

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
        printf("%d %s %s\n",emp->id,emp->nombre,emp->apellido);
    }
}

void altaEmpleado(eEmpleado* emp, int tam)
{
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

            free(nuevoEmp);
        }

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

void cargarEmpleado(eEmpleado* emp, int tam)
{
    int indice;
    FILE* f;
    int cant;

    if(emp !=NULL)
    {
        f = fopen("./bin.dat","rb");

        if(f !=NULL)
        {
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
        }

        fclose(f);
    }

}

void buscarApellido(eEmpleado* emp, int tam)
{
    char auxApellido[20];
    int flag = 0;

    printf("Ingrese el apellido a buscar: ");
    fflush(stdin);
    gets(auxApellido);

    printf("Id  Nombre  Apellido\n");

    for(int i=0; i<tam; i++)
    {
        if((emp+i)->estado == 1 && stricmp(auxApellido,(emp+i)->apellido)==0)
        {
            mostrarEmpleado(emp+i);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Este apellido no existe\n");
    }
}

void darModificacion(eEmpleado* x,int tam)
{
    int auxId;
    int id;
    int opcion;
    int indice;
    char seguir;
    char nuevoNombre[51];
    char nuevoApellido[51];

    if(x==NULL)
    {
        printf("Hubo un error, no se puede Modificar\n");
    }
    else
    {

        mostrarEmpleados(x,tam);

        printf("\n\n");

        printf("     Ingrese el ID del empleado a modificar: ");
        scanf("%d",&auxId);

        indice = buscarId(x,tam,auxId);

        if(indice == -1)
        {
            printf("     No hay ningun empleado con el ID %d\n",auxId);
        }
        else
        {
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #               >>>> Empleado <<<<              #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");

            mostrarEmpleado((x+indice));

            printf("     Que desea modificar?\n");
            printf("     1. Id\n     2. Nombre\n     3. Apellido\n");
            printf("     Ingrese opcion: ");
            scanf("%d",&opcion);

            switch(opcion)
            {
            case 1:
                system("cls");
                printf("     =================================================\n");
                printf("     #                                               #\n");
                printf("     #           >>>> Modificar id <<<<              #\n");
                printf("     #                                               #\n");
                printf("     =================================================\n");

                seguir = validarSeguir();

                if(seguir == 's' || seguir == 'S')
                {
                    printf("     Ingrese un nuevo id: ");
                    scanf("%d",&id);

                    (x+indice)->id = id;

                    printf("\n\n");
                    printf("     Modificacion exitosa!\n");

                }
                else
                {
                    printf("\n\n");
                    printf("     Modificacion cancelada\n");
                }
                break;
            case 2:
                system("cls");
                printf("     =================================================\n");
                printf("     #                                               #\n");
                printf("     #           >>>> Modificar nombre <<<<          #\n");
                printf("     #                                               #\n");
                printf("     =================================================\n");

                seguir = validarSeguir();

                if(seguir == 's' || seguir == 'S')
                {
                    printf("     Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(nuevoNombre);

                    strcpy((x+indice)->nombre,nuevoNombre);

                    printf("\n\n");
                    printf("     Modificacion exitosa!\n");

                }
                else
                {
                    printf("\n\n");
                    printf("     Modificacion cancelada\n");
                }
                break;
            case 3:
                system("cls");
                printf("     =================================================\n");
                printf("     #                                               #\n");
                printf("     #           >>>> Modificar apellido <<<<        #\n");
                printf("     #                                               #\n");
                printf("     =================================================\n");

                seguir = validarSeguir();

                if(seguir == 's' || seguir == 'S')
                {
                    printf("     Ingrese un nuevo apellido: ");
                    fflush(stdin);
                    gets(nuevoApellido);

                    strcpy((x+indice)->apellido,nuevoApellido);

                    printf("\n\n");
                    printf("     Modificacion exitosa!\n");

                }
                else
                {
                    printf("\n\n");
                    printf("     Modificacion cancelada\n");
                }
                break;
            default:
                printf("\n\n");
                printf("     ERROR. Esta opcion no es correcta\n");
            }
        }

    }
}

void darBaja(eEmpleado* x,int tam)
{
    int id;
    int indice;
    char seguir;

    if(x == NULL)
    {
        printf("Hubo un error, no se dar de Baja\n");
    }
    else
    {
        mostrarEmpleados(x,tam);

        printf("\n\n");

        printf("     Ingrese ID empleado a eliminar: ");
        scanf("%d",&id);

        indice = buscarId(x,tam,id);

        printf("\n\n");

        if(indice == -1)
        {
            system("pause");
            printf("     No hay ningun empleado con el ID %d\n",id);
        }
        else
        {
            system("pause");
            printf("     ID  Nombre  Apellido\n\n");
            mostrarEmpleado((x+indice));

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                (x+indice)->estado = 0;
                printf("\n\n");
                printf("     Empleado eliminado con exito\n");
            }
            else
            {
                printf("\n\n");
                printf("     Baja cancelada\n");
            }
        }
    }
}
