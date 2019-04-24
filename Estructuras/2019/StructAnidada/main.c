#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define TAM 10
#define SEC 4

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

typedef struct
{

    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int ocupado;
    eFecha fecha;
    int sector;
} eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado vec[], int tam);
int buscarLibre(eEmpleado vec[], int tam);
int buscarEmpleado(eEmpleado vec[], int tam, int legajo);
void mostrarEmpleado(eEmpleado emp, eSector sec[], int tamSec);
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void altaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void bajaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void ModificacionEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec);
void harcodeEmpleado(eEmpleado vec[], int tam);
void menuInformes(eEmpleado vec[],int tam, eSector sec[], int tamSec);
void harcodeSectores(eSector vec[], int tam);
void listarSectores(eSector x[], int tam);
void mostrarSectores(eSector x[], int tam, int idSector, char cadena[]);
void listarEmpXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void totalEmpxSector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void sectMasEmpleados(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empleadosMasGanadores(eEmpleado x[], int tam, eSector sec[], int tamSec);
void empMasGanadorXsector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void sectorMujeres(eEmpleado x[], int tam, eSector sec[], int tamSec);
void promSector(eEmpleado x[], int tam, eSector sec[], int tamSec);
void menorIgual2009(eEmpleado x[], int tam, eSector sec[], int tamSec);

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];
    eSector sector[SEC];
    //inicializarEmpleados(lista, TAM); // llamada
    harcodeEmpleado(lista,TAM);
    harcodeSectores(sector,SEC);

    do
    {
        switch(menu())
        {

        case 1:
            // printf("\nAlta empleado\n\n");
            altaEmpleado(lista, TAM, sector, SEC);
            system("pause");
            break;

        case 2:
            //printf("\nBaja empleado\n\n");
            bajaEmpleado(lista, TAM, sector, SEC);
            system("pause");
            break;

        case 3:
            //printf("\nModificacion empleado\n\n");
            ModificacionEmpleado(lista,TAM, sector, SEC);
            system("pause");
            break;

        case 4:
            //printf("\nOrdenar empleados\n\n");
            menuInformes(lista,TAM, sector, SEC);
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sector, SEC);
            system("pause");
            break;

        case 6:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');

    return 0;
}

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificacion Empleado\n");
    printf("4- Informes\n");
    printf("5- Mostrar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].legajo == legajo && vec[i].ocupado == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void mostrarEmpleado(eEmpleado emp, eSector sec[], int tamSec)
{
    char cadena[20];

    mostrarSectores(sec,tamSec,emp.sector,cadena);

    printf("  %d   %s   %c    %.2f   %02d/%02d/%d   %s\n", emp.legajo, emp.nombre, emp.sexo, emp.sueldo, emp.fecha.dia, emp.fecha.mes, emp.fecha.anio, cadena);

}

void mostrarEmpleados(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == 1)
        {

            mostrarEmpleado(vec[i],sec,tamSec);
            cont++;
        }
    }
    if(cont == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }
}

void altaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{
    int indice;
    int legajo;
    int idSector;
    int esta;

    indice = buscarLibre(vec, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n");
    }
    else
    {

        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(vec, tam, legajo);

        if( esta == -1)
        {
            vec[indice].legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(vec[indice].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &vec[indice].sexo);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[indice].sueldo);

            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.dia);

            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.mes);

            printf("Ingrese dia de ingreso: ");
            scanf("%d",&vec[indice].fecha.anio);

            //MOSTRAR OPCIONES CON SUS DESCRIPCIONES

            listarSectores(sec,tamSec);

            printf("Ingrese ID Sector: ");
            scanf("%d",&idSector);

            vec[indice].sector = idSector;

            vec[indice].ocupado = 1;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

        }
        else
        {

            printf("Ya existe un empleado con el legajo %d\n", legajo);

            mostrarEmpleado(vec[esta],sec,tamSec);
        }
    }
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{

    int legajo;
    char confirma;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta],sec,tamSec);

        printf("\nConfirma la eliminacion? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            vec[esta].ocupado = 0;
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}

void ModificacionEmpleado(eEmpleado vec[], int tam, eSector sec[], int tamSec)
{

    int legajo;
    char confirma;
    float nuevoSueldo;
    int esta;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    esta = buscarEmpleado(vec, tam, legajo);

    if( esta == -1)
    {

        printf("\nEl legajo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        mostrarEmpleado(vec[esta],sec,tamSec);

        printf("\nQuiere cambiar el sueldo? s/n");
        fflush(stdin);
        confirma = tolower(getche());

        if(confirma == 's')
        {
            printf("\nIngrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);
            //valido sueldo
            vec[esta].sueldo = nuevoSueldo;
        }
        else
        {
            printf("\nNo se ha modificado el sueldo\n");
        }

    }

}

void harcodeEmpleado(eEmpleado vec[], int tam)
{
    eEmpleado hardcode[]=
    {
        {1234, "Juan", 'm', 30000,1,{12,3,2000}, 4},
        {2222, "Ana", 'f', 32000,1, {2,7,2010},1},
        {2211, "Jorge", 'm', 28000,1,{14,5,2013},1},
        {3241, "Alberto", 'm', 35000,1, {2,9,2010},2},
        {8944, "Sonia", 'f', 39000,1, {12,3,2012},2},
        {2231, "Miguel", 'm', 29700,1, {28,7,2009},2},
        {6578, "Adrian", 'm', 43200,1, {11,1,2016}, 3},
        {3425, "Lucia", 'f', 32300,0, {19,10,2004},3},
        {5546, "Gaston", 'm', 29760,0, {13,9,2006},4},
        {7654, "Diego", 'm', 35000,0, {23,6,2010}, 2}
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }
}

void empleadoXanio(eEmpleado x[],int tam, int anio, eSector sec[], int tamSec)
{
    int cont=0;

    for(int i=0; i<tam; i++)
    {
        if(x[i].ocupado == 1 && x[i].fecha.anio == anio)
        {
            cont++;
            mostrarEmpleado(x[i],sec,tamSec);
        }
    }

    if(cont == 0)
    {
        printf("No hay empleados que buscar\n");
    }

}

void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec)
{
    char seguir = 's';
    char confirma;
    int opcion;
    int anio;

    do
    {

        system("cls");
        printf("1- Mostrar Empleados Por Anio\n");
        printf("2- Mostrar Empleados de un Sector\n");
        printf("3- Cantidad de Empleados x Sector\n");
        printf("4- Empleados x Sector\n");
        printf("5- Sectores con mas empleados\n");
        printf("6- Empleados que mas ganan x Sector\n");
        printf("7- Sectores con Mujeres\n");
        printf("8- Promedio y Total de Salarios de un Sector\n");
        printf("9- Nacidos <= 2009\n");
       printf("10- Empleados con el mismo Salario"\n);
       printf("11- Cant de Hombres x Sector\n");
       printf("12- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\n\n");
            printf("Ingrese anio a buscar: ");
            scanf("%d",&anio);

            empleadoXanio(x,tam,anio,sec,tamSec);
            system("pause");
            break;

        case 2:
            listarEmpXsector(x,tam,sec,tamSec);
            system("pause");
            break;

        case 3:
            totalEmpxSector(x,tam,sec,tamSec);
            system("pause");
            break;

        case 4:
            empXsector(x,tam,sec,tamSec);
            system("pause");
            break;

        case 5:
            sectMasEmpleados(x,tam,sec,tamSec);
            system("pause");
            break;

        case 6:
            empMasGanadorXsector(x,tam,sec,tamSec);
            system("pause");
            break;

        case 7:
            sectorMujeres(x,tam,sec,tamSec);
            system("pause");
            break;

        case 8:
            promSector(x,tam,sec,tamSec);
            system("pause");
            break;

        case 9:
            menorIgual2009(x,tam,sec,tamSec);
            system("pause");
            break;

        case 10:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }

        system("pause");
        system("cls");
    }
    while(seguir == 's');
}

void harcodeSectores(eSector vec[], int tam)
{
    eSector hardcode[]=
    {
        {1, "RR.HH"},
        {2, "Contabilidad"},
        {3, "Sistemas"},
        {4, "Ventas"}
    };
    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }

}

void listarSectores(eSector x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s\n",x[i].id,x[i].descripcion);
    }
}

void mostrarSectores(eSector x[], int tam, int idSector, char cadena[])
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].id == idSector)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,x[i].descripcion);

        }
    }
}

void listarEmpXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int idSector;
    int flag = 0;

    system("cls");
    printf("  *** Listado de Sectores ***\n\n");

    listarSectores(sec,tamSec);
    printf("\n\n");
    printf("Ingrese ID Sector: ");
    scanf("%d",&idSector);

    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == idSector)
        {
            mostrarEmpleado(x[i],sec,tamSec);

            flag = 1;

        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar en este sector\n");
    }
}

void totalEmpxSector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{

    int cont = 0;

    for(int i=0; i<tamSec; i++)
    {

        printf("Sector: %s\n",sec[i].descripcion);

        cont = 0;

        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == 1)
            {
                cont++;
            }
        }

        printf("Cant de Empleados: %d\n\n",cont);

    }

}

void empXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{

    for(int i=0; i<tamSec; i++)
    {

        printf("Sector: %s\n",sec[i].descripcion);

        for(int j=0; j<tam; j++)
        {

            if(x[j].sector == sec[i].id && x[j].ocupado == 1)
            {
                mostrarEmpleado(x[j],sec,tamSec);
            }

        }
    }
}

void sectMasEmpleados(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int mayor;
    int totales[tamSec];
    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {
        totales[i] = 0;

        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == 1)
            {
                totales[i]++;
            }
        }
    }

    for(int i=0; i<tamSec; i++)
    {

        if(flag == 0  || totales[i]>mayor)
        {
            mayor = totales[i];
            flag = 1;
        }
    }

    printf("Cant mayor de empleados %d\n",mayor);

    for(int i=0; i<tamSec; i++)
    {
        if(totales[i] == mayor)
        {
            printf("Sector/es %s\n",sec[i].descripcion);
        }
    }

}

void empMasGanadorXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float mayor;
    int flag = 0;
    int flag1 = 0;

    for(int i=0; i<tamSec; i++)
    {
        for(int j=0; j<tam; j++)
        {

            if((x[j].sueldo > mayor && x[j].sector == sec[i].id && x[j].ocupado == 1) || (flag == 0))
            {
                mayor = x[j].sueldo;

                flag = 1;
            }

            if(x[j].sector == sec[i].id && x[j].ocupado == 1)
            {
                flag1 = 1;
            }

        }

        if(flag1 == 0)
        {
            printf("Esta vacio\n");
        }
        else
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].sueldo == mayor && x[i].ocupado == 1)
                {
                    mostrarEmpleado(x[j],sec,tamSec);
                }
            }
        }
    }

}

void sectorMujeres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    for(int i=0; i<tamSec; i++)
    {

        for(int j=0; j<tam; j++)
        {
            if(x[j].ocupado == 1 && x[j].sector == sec[i].id && x[j].sexo == 'f')
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);

            }
        }
    }
}

void promSector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int idSector;
    float prom;
    int flag=0;
    int cont=0;
    float acum=0;

    system("cls");
    printf("  *** Listado de Sectores ***\n\n");

    listarSectores(sec,tamSec);
    printf("\n\n");
    printf("Ingrese ID Sector: ");
    scanf("%d",&idSector);

    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == idSector && x[i].ocupado == 1)
        {
            flag = 1;
            cont++;
            acum+=x[i].sueldo;
        }
    }

    if(flag == 0)
    {
        printf("Sector Vacio\n");
    }
    else
    {
        prom = acum/cont;

        printf("La suma total de los salarios de este sector es %.2f y el promedio es de %.2f\n",acum,prom);
    }
}

void menorIgual2009(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    for(int i=0; i<tamSec; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].fecha.anio <=2009 && x[j].sector == sec[i].id && x[j].ocupado == 1)
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);
            }
        }
    }
}

