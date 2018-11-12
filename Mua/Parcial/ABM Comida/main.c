#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{
    int id;
    char descripcion[20];

} eComida;

typedef struct
{
    int dia;
    int mes;
    int anio;

} efecha;

typedef struct
{
    int id;
    int idComida;
    int idEmp;
    efecha fecha;
    int isEmpty;

} eAlmuerzo;

void listarSectores(eSector sectores[], int tam);
void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[]);
void inicializarEmpleados(eEmpleado lista[], int tam);
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam);
int buscarLibre(eEmpleado lista[], int tam);
int buscarEmpleado(eEmpleado lista[], int tam, int legajo);
void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void ModificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam);
void harcodearEmpleados(eEmpleado empleados[]);
void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector);
void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector);

int menu();
void cargarSectores(eSector sectores[]);
void cargarComidas(eComida comidas[]);
void listarComidas(eComida c[], int tam);
void altaAlmuerzo(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame, eSector s[], int tams, int* pId);
int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam);
void inicializarAlmuerzos(eAlmuerzo lista[], int tam);
void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena);
void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eEmpleado e[], int tame);
void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame);

void inicializarEmpleados(eEmpleado lista[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        lista[i].isEmpty = 1;
    }
}

void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int tam)
{
    char descSector[20];

    obtenerSector(sectores, tam, unEmpleado.idSector, descSector);

    printf("%4d %10s   %2c    %6.2f %10s\n", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, descSector);
}

void mostrarEmpleados(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    system("cls");
    printf("Legajo   Nombre  Sexo   Sueldo     Sector\n\n");

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 0)
        {
            mostrarEmpleado(lista[i], sectores, tamSector);
        }
    }

    printf("\n\n");


}


int buscarLibre(eEmpleado lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado lista[], int tam, int legajo)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {

        if( lista[i].legajo == legajo && lista[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int indice;
    int legajo;
    int existe;
    int idSector;
    eEmpleado nuevoEmpleado;

    indice = buscarLibre(lista, tam);

    system("cls");
    printf("*** Alta empleado ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        existe = buscarEmpleado(lista, tam, legajo);

        if( existe != -1)
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);
            //  mostrarEmpleado(lista[existe]);
            system("pause");

        }
        else
        {

            nuevoEmpleado.legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);
            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado.sexo);
            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            listarSectores(sectores, tamSector);
            printf("\nIngrese sector: ");
            scanf("%d", &idSector);

            nuevoEmpleado.idSector = idSector;

            nuevoEmpleado.isEmpty = 0;

            lista[indice] = nuevoEmpleado;

        }
    }

}


void bajaEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{

    int legajo;
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja empelado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSector);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {

            lista[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

void ModificarEmpleado(eEmpleado lista[], int tam, eSector sectores[], int tamSector)
{
    int legajo;
    int indice;
    char seguir;
    float nuevoSueldo;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(lista, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado de legajo %d\n\n", legajo);
        system("pause");
    }
    else
    {
        mostrarEmpleado(lista[indice], sectores, tamSector);

        printf("\nModifica sueldo? s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Modificacion cancelada\n\n");

        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            lista[indice].sueldo = nuevoSueldo;

            printf("Modificacion exitosa\n\n");
        }
        system("pause");
    }





}

void ordenarEmpleadosXlegajo(eEmpleado lista[], int tam)
{
    eEmpleado auxEmpleado;
    for(int i=0; i<tam-1; i++)
    {
        for(int j= i+1; j < tam; j++)
        {

            if( lista[i].legajo > lista[j].legajo)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;

            }
        }
    }

    printf("Empleados ordenados con exito!!!\n\n");


}

void harcodearEmpleados(eEmpleado empleados[])
{

    eEmpleado x[]=
    {

        {1111, "juan", 'm', 23000,1,0},
        {2222, "luis", 'm', 18000, 1, 0},
        {1234, "ana", 'f', 21000, 5,0},
        {5643, "melisa", 'f', 24000, 2, 0},
        {2312, "mia", 'f', 34000, 3, 0},
        {7768, "mauro", 'm', 32000,5, 0},
        {1324, "alberto", 'm', 26000, 4,0},
        {9876, "valentina", 'f', 32000,5, 0}

    };

    for(int i=0; i < 8; i++)
    {

        empleados[i] = x[i];
    }




}

void listarSectores(eSector sectores[], int tam)
{

    printf("Id  Descripcion\n\n");
    for(int i=0; i< tam; i++)
    {
        printf("%d   %10s\n", sectores[i].id, sectores[i].descripcion);

    }
    printf("\n\n");
}

void obtenerSector(eSector sectores[], int tam, int idSector, char cadena[])
{

    for(int i=0; i < tam; i++)
    {

        if( sectores[i].id == idSector)
        {
            strcpy(cadena, sectores[i].descripcion);
        }
    }

}

void listarEmpleadosXSector(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    int idSector;
    char descripcion[20];
    int flag = 0;

    system("cls");
    printf("  *** Listado de Sectores ***\n\n");

    listarSectores(sectores, tamSector);
    printf("Ingrese sector: ");
    scanf("%d",&idSector);

    obtenerSector(sectores, tam, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(int i=0; i< tam; i++)
    {
        if(x[i].isEmpty == 0 && x[i].idSector == idSector)
        {
            mostrarEmpleado(x[i], sectores, tamSector);
            flag = 1;
        }
    }

    printf("\n\n");

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

void ordenarXSectorYNombre(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            obtenerSector(sectores, tamSector, x[i].idSector, descripcionI);
            obtenerSector(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].nombre, x[j].nombre) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }
    printf("\nEmpleados ordenados con exito!!!\n\n");

}

void mostrarEmpleadosMasGanadores(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;
    int flag2;

    system("cls");
    printf("\n*** Empleados que mas ganan por sector ***\n\n");

    for(int i=0; i < tamSector; i++)
    {

        obtenerSector(sectores, tamSector, sectores[i].id, descripcion);
        printf("Sector %s\n", descripcion);
        printf("--------------\n\n");
        flag = 0;
        flag2 = 0;
        for(int j=0; j < tam; j++)
        {
            if( (x[j].sueldo > maxSueldo && x[j].isEmpty == 0 && x[j].idSector == sectores[i].id) || flag == 0)
            {
                maxSueldo = x[j].sueldo;
                flag = 1;
            }

            if( x[j].isEmpty == 0 && x[j].idSector == sectores[i].id)
            {
                flag2 = 1;
            }

        }

        if(flag2 == 0)
        {
            printf("Sector Vacio\n");
        }
        else
        {

            for(int j=0; j < tam; j++)
            {
                if( x[j].sueldo == maxSueldo && x[j].isEmpty == 0)
                {
                    mostrarEmpleado(x[j], sectores, tamSector);
                }
            }

        }

        printf("\n\n");
    }
}

int main()
{
    char seguir = 's';
    int idAlmuerzo = 1000;

    eSector sectores[5];
    eComida comidas[5];
    eAlmuerzo almuerzos[20];

    cargarSectores(sectores);
    cargarComidas(comidas);
    eEmpleado empleados[TAM];
    inicializarEmpleados(empleados,TAM);
    inicializarAlmuerzos(almuerzos, 20);
    harcodearEmpleados(empleados);

    do
    {
        switch(menu())
        {
        case 1:
            altaEmpleado(empleados, TAM, sectores, 5);
            break;
        case 2:
            bajaEmpleado(empleados,TAM, sectores, 5);
            break;
        case 3:
            ModificarEmpleado(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 5:
            ordenarEmpleadosXlegajo(empleados, TAM);
            system("pause");
            break;
        case 6:
            listarEmpleadosXSector(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 7:
            ordenarXSectorYNombre(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 8:
            mostrarEmpleadosMasGanadores(empleados, TAM, sectores, 5);
            system("pause");
            break;
        case 9:
            listarComidas(comidas, 5);
            system("pause");
            break;
        case 10:
            altaAlmuerzo(almuerzos, 20, comidas, 5, empleados, TAM, sectores, 5, &idAlmuerzo);
            system("pause");
            break;
        case 11:
            mostrarAlmuerzos(almuerzos, 20, comidas, 5, empleados, TAM);
            system("pause");
            break;
        case 20:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("\n*** Menu de Opciones ***\n\n");
    printf(" 1-  Alta\n");
    printf(" 2-  Baja\n");
    printf(" 3-  Modificacion\n");
    printf(" 4-  Listar Empleados\n");
    printf(" 5-  Ordenar Empleados\n");
    printf(" 6-  Mostrar Empleados x Sector\n");
    printf(" 7-  Ordenar Empleados x Sector y Nombre\n");
    printf(" 8-  Listar empleados ganadores\n");
    printf(" 9-  Listar Comidas\n");
    printf(" 10- Alta Almuerzo\n");
    printf(" 11- Mostrar Almuerzos\n");
    printf(" 20- Salir\n\n");
    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
void cargarSectores(eSector sectores[])
{
    eSector sec[]=
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };

    for(int i=0; i < 5; i++)
    {
        sectores[i] = sec[i];
    }
}

void cargarComidas(eComida comidas[])
{
    eComida food[]=
    {
        {1, "Milanesa"},
        {2, "Pizza"},
        {3, "Ensalada"},
        {4, "Pescado"},
        {5, "Lasagna"}
    };

    for(int i=0; i < 5; i++)
    {
        comidas[i] = food[i];
    }
}

void listarComidas(eComida c[], int tam)
{
    printf("\nLista de comidas\n\n");

    for(int i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",c[i].id, c[i].descripcion);
    }
    printf("\n\n");
}

void altaAlmuerzo(eAlmuerzo* a, int tama, eComida c[], int tamc, eEmpleado e[], int tame, eSector s[], int tams, int* pId)
{
    int idAlmuerzo = *pId;
    int legajo;
    int idComida;
    efecha fecha;
    eAlmuerzo nuevoAlmuerzo;
    int indice;

    indice = buscarLibreAlmuerzo(a, tama);

    if(indice == -1)
    {
        printf("No se pueden cargar mas almuerzos\n\n");
    }
    else
    {
        nuevoAlmuerzo.id = idAlmuerzo;

        mostrarEmpleados(e, tame, s, tams);

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        nuevoAlmuerzo.idEmp = legajo;

        listarComidas(c, tamc);
        printf("Ingrese comida: ");
        scanf("%d", &idComida);

        nuevoAlmuerzo.idComida = idComida;

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlmuerzo.fecha = fecha;

        nuevoAlmuerzo.isEmpty = 0;

        a[indice] = nuevoAlmuerzo;

        *pId = idAlmuerzo + 1;
    }
}

int buscarLibreAlmuerzo(eAlmuerzo lista[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void inicializarAlmuerzos(eAlmuerzo lista[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}

void mostrarAlmuerzos(eAlmuerzo a[], int tama, eComida c[], int tamc, eEmpleado e[], int tame)
{
    int flag = 0;

    system("cls");
    printf("id   fecha   Legajo   Nombre    Comida\n\n");

    for(int i=0; i < tama; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlmuerzo(a[i], c, tamc, e, tame);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados");
    }
    printf("\n\n");
}


void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida c[], int tamc, eEmpleado e[], int tame)
{
    char descComida[20];
    int indice;
    eEmpleado empleado;

    obtenerDescComida(c, tamc, unAlmuerzo.idComida, descComida);
    indice = buscarEmpleado(e, tame, unAlmuerzo.idEmp);

    empleado = e[indice];

    printf("%4d %02d/%02d/%d  %d %10s  %10s\n", unAlmuerzo.id, unAlmuerzo.fecha.dia, unAlmuerzo.fecha.mes, unAlmuerzo.fecha.anio, empleado.legajo, empleado.nombre, descComida);
}

void obtenerDescComida(eComida c[], int tamc, int idComida, char* cadena)
{
    for(int i=0; i < tamc; i++)
    {
        if( c[i].id == idComida)
        {
            strcpy(cadena, c[i].descripcion);
        }
    }
}
