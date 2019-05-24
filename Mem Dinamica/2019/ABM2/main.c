#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define OCUPADO 1
#define VACIO 0
#define T 3

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;
} eEmpleado;

void inicializarX(eEmpleado*,int);

void menuPrincipal(eEmpleado*,int);

void menuInformes(eEmpleado*,int);

int buscarLibre(eEmpleado*,int);

int buscarXid(eEmpleado*,int,int);

void darAlta(eEmpleado*,int,int*);

void mostrarEmpleado(eEmpleado* x);

void mostrarEmpleados(eEmpleado*,int);

void darModificacion(eEmpleado*,int);

void darBaja(eEmpleado*,int);

void ordenar(eEmpleado[],int);

void promediar(eEmpleado*,int);

void validarString(char x[]);

int validarEntero(char entero[]);

float validarFloat(char sueldo[]);

void comapunto(char sueldo[]);

char validarSeguir();

int main()
{

    eEmpleado* pEmp;

    pEmp = (eEmpleado*)malloc(sizeof(eEmpleado)*T);

    if(pEmp !=NULL)
    {
        //INICIALIZO?
        //EL 0 Y EL 1 SE USAN?
        //ALTA
        //ELIMINAR
        inicializarX(pEmp,T);

        menuPrincipal(pEmp,T);
    }
    else
    {
        printf("No se logro conseguir espacio en memoria\n");
        system("pause");
        exit(1);
    }

    free(pEmp);

    return 0;
}

void inicializarX(eEmpleado* x,int tam)
{
    if(x !=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            (x+i)->isEmpty = VACIO;
        }
    }
}


void menuPrincipal(eEmpleado* x,int tam)
{
    int opcion;
    int flag;
    char seguir = 's';
    char valOpcion[10];
    int idEmpleado = 1000;

    do
    {
        system ("COLOR B0");
        system("cls");
        printf("     =================================================\n");
        printf("     #            Trabajo Practico Nro. 2            #\n");
        printf("     #                                               #\n");
        printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
        printf("     =================================================\n");
        printf("     |                                               |\n");
        printf("                       1- Alta                        \n");
        printf("     |                                               |\n");
        printf("                       2- Modificar                   \n");
        printf("     |                                               |\n");
        printf("                       3- Baja                        \n");
        printf("     |                                               |\n");
        printf("                       4- Informes                    \n");
        printf("     |                                               |\n");
        printf("                       5- Salir                       \n");
        printf("     |                                               |\n");
        printf("     =================================================\n");
        printf("                                                      \n");
        printf("     Ingrese una opcion del menu: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            darAlta(x,tam,&idEmpleado);
            flag = 1;
            break;
        case 2:
            if(flag == 1)
            {
                system("cls");
                darModificacion(x,tam);
            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 3:
            if(flag == 1)
            {
                system("cls");
                darBaja(x,tam);
            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 4:
            if(flag == 1)
            {
                menuInformes(x,tam);

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los datos!\n");
            }
            break;
        case 5:
            system("cls");
            seguir = 'n';

            printf("     ==========================================\n");
            printf("     #               Saliendo...              #\n");
            printf("     ==========================================\n");
            printf("     |                                        |\n");
            printf("     |              Hasta luego!!!            |\n");
            printf("     |                                        |\n");
            printf("     ==========================================\n");

            break;
        default:
            printf("\n\n");
            printf("     ERROR. Esta opcion no es correcta\n");
        }

        fflush(stdin);
        printf("     Presione ENTER para continuar");
        getchar();

    }
    while(seguir == 's');
}

void menuInformes(eEmpleado* x,int tam)
{
    char seguir = 's';
    int opcion;
    char valOpcion[10];

    system("cls");

    do
    {
        printf("     =================================================\n");
        printf("     #                                               #\n");
        printf("     #               >>>> INFORMES <<<<              #\n");
        printf("     #                                               #\n");
        printf("     =================================================\n");
        printf("     |                                               |\n");
        printf("         1- Mostrar ordenados por Sector/Apellido     \n");
        printf("     |                                               |\n");
        printf("         2- Promedio y Total de Salarios              \n");
        printf("     |                                               |\n");
        printf("         3- Salir                                      \n");
        printf("     |                                               |\n");
        printf("     =================================================\n");
        printf("                                                      \n");
        printf("     Ingrese una opcion del menu: ");
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            ordenar(x,tam);
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            promediar(x,tam);
            printf("\n\n");
            system("pause");
            system("cls");
            break;
        case 3:
            seguir = 'n';
            break;
        default:
            printf("     ERROR. Esta opcion no es correcta\n");
            printf("\n\n");
            system("pause");
            system("cls");
        }
    }
    while(seguir == 's');

}


int buscarLibre(eEmpleado* x,int tam)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if((x+i)->isEmpty == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarXid(eEmpleado* x,int tam, int id)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if((x+i)->id == id && (x+i)->isEmpty == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

eEmpleado* new_Empleado()
{

    eEmpleado* nuevo;

    nuevo = (eEmpleado* ) malloc(sizeof(eEmpleado));

    if( nuevo != NULL)
    {

        nuevo->id = 0;
        strcpy(nuevo->nombre, "");
        strcpy(nuevo->apellido, "");
        nuevo->sueldo = 0;
        nuevo->sector = 0;
        nuevo->isEmpty = 0;
    }


    return nuevo;


}

void darAlta(eEmpleado* x,int tam,int* pId)
{
    int index;
    int idEmpleado = *pId;
    char seguir = 's';
    char nombre[51];
    char apellido[51];
    char sueldo[10];
    char sector[5];

    if(x==NULL)
    {
        printf("Hubo un error, no se puede dar de Alta\n");
    }

    else
    {
        do
        {
            system("cls");

            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #              >>>> Alta Empleado <<<<          #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");


            //ESTO ESTA BIEN?
            eEmpleado* empleado = new_Empleado();

            index = buscarLibre(x,tam);

            if(index == -1)
            {
                printf("     No hay mas espacio para cargar\n");
                printf("\n\n");
                system("pause");
                break;
            }
            else
            {
                empleado->id = idEmpleado;

                printf("     Ingrese nombre: ");
                fflush(stdin);
                gets(nombre);

                validarString(nombre);

                strcpy(empleado->nombre,nombre);

                printf("     Ingrese apellido: ");
                fflush(stdin);
                gets(apellido);

                validarString(apellido);

                strcpy(empleado->apellido,apellido);

                printf("     Ingrese sueldo: ");
                fflush(stdin);
                gets(sueldo);

                empleado->sueldo = validarFloat(sueldo);

                printf("     Ingrese sector: ");
                fflush(stdin);
                gets(sector);

                empleado->sector = validarEntero(sector);

                empleado->isEmpty = OCUPADO;

                *(x+index) = *empleado;

                printf("\n\n");

                printf("     Empleado cargado con exito!!\n");

                printf("\n\n");

                *pId = idEmpleado++;

                seguir = validarSeguir();

                free(empleado);

            }


        }
        while(seguir == 's' || seguir =='S');
    }

}


void mostrarEmpleado(eEmpleado* x)
{
    if(x !=NULL)
    {
        printf("%6d %4s %8s %14.2f %7d\n",x->id,x->nombre,x->apellido,x->sueldo,x->sector);
    }
}

void mostrarEmpleados(eEmpleado* x,int tam)
{
    int cont = 0;

    system("cls");

    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #               >>>> Empleados <<<<             #\n");
    printf("     #                                               #\n");
    printf("     =================================================\n");
    printf("\n\n");
    printf("     ID  Nombre  Apellido    Sueldo     Sector\n\n");

    if(x !=NULL && tam >0)
    {
        for(int i=0; i<tam; i++)
        {
            if((x+i)->isEmpty == OCUPADO)
            {
                cont++;
                mostrarEmpleado(x+i);
            }
        }

        if(cont == 0)
        {
            printf("     No hay ningun empleado que mostrar\n");
        }
    }
    else
    {
        printf("     No se pueden mostrar los empleados\n");
    }
}

void darModificacion(eEmpleado* x,int tam)
{
    int id;
    char valId[10];
    int opcion;
    int indice;
    char seguir;
    char nuevoNombre[51];
    char nuevoApellido[51];
    char valOpcion[10];
    char nuevoSalario[10];
    char nuevoSector[5];

     if(x==NULL)
    {
        printf("Hubo un error, no se puede Modificar\n");
    }
    else
    {

    mostrarEmpleados(x,tam);

    printf("\n\n");

    printf("     Ingrese el ID del empleado a modificar: ");
    gets(valId);

    id = validarEntero(valId);

    printf("\n\n");

    indice = buscarXid(x,tam,id);

    if(indice == -1)
    {
        printf("     No hay ningun empleado con el ID %d\n",id);
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
        printf("     1. Nombre\n     2. Apellido\n     3. Salario\n     4. Sector\n");
        printf("     Ingrese opcion: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
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

                validarString(nuevoNombre);

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
        case 2:
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

                validarString(nuevoApellido);

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
        case 3:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #           >>>> Modificar salario <<<<         #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                printf("     Ingrese un nuevo salario: ");
                fflush(stdin);
                gets(nuevoSalario);

                (x+indice)->sueldo = validarFloat(nuevoSalario);

                printf("\n\n");
                printf("     Modificacion exitosa!\n");

            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;
        case 4:
            system("cls");
            printf("     =================================================\n");
            printf("     #                                               #\n");
            printf("     #            >>>> Modificar sector <<<<         #\n");
            printf("     #                                               #\n");
            printf("     =================================================\n");

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                printf("     Ingrese un nuevo sector: ");
                fflush(stdin);
                gets(nuevoSector);

                (x+indice)->sector = validarEntero(nuevoSector);

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
    char valId[10];
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
    gets(valId);

    id = validarEntero(valId);

    indice = buscarXid(x,tam,id);

    printf("\n\n");

    if(indice == -1)
    {
        system("pause");
        printf("     No hay ningun empleado con el ID %d\n",id);
    }
    else
    {
        system("pause");
        printf("     ID  Nombre  Apellido    Sueldo     Sector\n\n");
        mostrarEmpleado((x+indice));

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            (x+indice)->isEmpty = VACIO;
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


void ordenar(eEmpleado* x,int tam)
{
    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #           >>>> Ordenar empleados  <<<<        #\n");
    printf("     #                                               #\n");
    printf("     =================================================\n");

    eEmpleado aux;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp((x+i)->apellido,(x+j)->apellido)>0)
            {
                aux = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = aux;
            }
            else if(strcmp((x+i)->apellido,(x+j)->apellido) == 0 && (x+i)->sector > (x+j)->sector)
            {
                aux = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = aux;
            }
        }
    }

    mostrarEmpleados(x,tam);
}

void promediar(eEmpleado* x,int tam)
{
    printf("     =================================================\n");
    printf("     #                                               #\n");
    printf("     #      >>>> Promedio y Total de Salarios <<<<   #\n");
    printf("     #                                               #\n");
    printf("     =================================================\n");

    int contSueldos = 0;
    float sumaSueldos = 0;
    int contMaxSueldo = 0;
    float promSueldos;
    int esta = 0;
    int esta1 = 0;

    for(int i=0; i<tam; i++)
    {
        if((x+i)->isEmpty == OCUPADO)
        {
            esta++;
            contSueldos++;
            sumaSueldos+=(x+i)->sueldo;
        }
    }

    if(esta == 0)
    {
        printf("     No hay empleados\n");
    }
    else
    {
        promSueldos = sumaSueldos/contSueldos;

        printf("     La suma total de los salarios es de: %.2f y el promedio total seria: %.2f\n", sumaSueldos,promSueldos);

        printf("\n\n");

        for(int i=0; i<tam; i++)
        {
            if((x+i)->isEmpty == OCUPADO && (x+i)->sueldo > promSueldos)
            {
                printf("     ID  Nombre  Apellido    Sueldo     Sector\n\n");
                mostrarEmpleado(x+i);
                contMaxSueldo++;
                esta1++;
            }
        }

        if(esta1 == 0)
        {
            printf("\n\n");
            printf("     No hay ningun empleado que supere el sueldo promedio\n");
        }
        else
        {
            printf("\n\n");
            printf("     La cant de empleados que superan el sueldo promedio  es de: %d\n",contMaxSueldo);
        }

    }
}


void validarString(char x[])
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0 || strlen(x)>51 || x[0] == '\0')
        {
            printf("     Reingrese solo caracteres alfabeticos <51: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

float validarFloat(char sueldo[])
{
    float sueldoK;

    while(strlen(sueldo)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(sueldo);
    }

    for(int i=0; i<strlen(sueldo); i++)
    {

        sueldoK = atof(sueldo);

        while(isalpha(sueldo[i]) != 0 || sueldoK <= 0 || sueldo[i] == ' ')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(sueldo);
            i=0;
            comapunto(sueldo);
            sueldoK = atof(sueldo);
        }

    }

    return sueldoK;
}

void comapunto(char sueldo[])
{
    char coma=',';
    char punto='.';

    for (int i=0; i<strlen(sueldo); i++)
    {
        if (sueldo[i] == coma)
        {
            sueldo[i] = punto;
        }
    }
}

int validarEntero(char entero[])
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
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
