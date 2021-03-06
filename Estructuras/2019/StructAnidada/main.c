#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define TAM 15
#define SEC 4
#define COM 5
#define ALM 20

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

typedef struct
{
    int id;
    char descripcion[20];
} eComida;

typedef struct
{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
} eAlmuerzo;

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
void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm);
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
void mismoSalario(eEmpleado x[], int tam, eSector sec[], int tamSec);
void cantHombres(eEmpleado x[], int tam, eSector sec[], int tamSec);
void harcodeAlmuerzos(eAlmuerzo x[], int tam);
void harcodeComidas(eComida x[], int tam);
void empMasPerdedor(eEmpleado x[], int tam, eSector sec[], int tamSec);
void mostrarComidas(eComida x[], int tam, int idComida, char cadena[]);
void listarComidas(eComida x[], int tam);
void mostrarAlmuerzos(eAlmuerzo alm[], int tamAlm, eEmpleado emp[], int tam, eComida com[], int tamCom);
void mostrarAlmuerzo(eAlmuerzo alm, eEmpleado emp[], int tam, eComida com[], int tamCom);
void almuerzosXemp(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXdescrip(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);
void almuerzosXmismaFecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm);
void almuerzosMasComido(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm);
int comparar(eFecha fech, eFecha fecha);
void almuerzosXsector(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec);

int main()
{
    char seguir = 's';
    char confirma;
    eEmpleado lista[TAM];
    eSector sector[SEC];
    eComida comida[COM];
    eAlmuerzo almuerzo[ALM];
    //inicializarEmpleados(lista, TAM); // llamada
    harcodeEmpleado(lista,TAM);
    harcodeSectores(sector,SEC);
    harcodeComidas(comida,COM);
    harcodeAlmuerzos(almuerzo,ALM);

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
            menuInformes(lista,TAM, sector, SEC, comida, COM, almuerzo, ALM);
            system("pause");
            break;

        case 5:
            //printf("\nListar empleados\n\n");
            mostrarEmpleados(lista, TAM, sector, SEC);
            system("pause");
            break;


        case 6:
            //printf("\nListar empleados\n\n");
            mostrarAlmuerzos(almuerzo,ALM,lista,TAM,comida,COM);
            system("pause");
            break;

        case 7:
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
    printf("6- Mostrar Almuerzos\n");
    printf("7- Salir\n\n");
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
        {2222, "Ana", 'f', 30000,1, {2,7,2010},1},
        {2211, "Jorge", 'm', 28000,1,{14,5,2013},1},
        {3241, "Alberto", 'm', 35000,1, {2,9,2010},2},
        {8944, "Sonia", 'f', 39000,1, {12,3,2012},2},
        {2231, "Miguel", 'm', 29700,1, {28,7,2009},2},
        {6578, "Adrian", 'm', 43200,1, {11,1,2016}, 3},
        {3425, "Carolina", 'f', 32300,1, {19,10,2004},3},
        {7654, "Diego", 'm', 35000,0, {23,6,2010}, 2},
        {3456, "Mirta", 'f', 30000,1, {2,7,2009},1},
        {4567, "Ximena", 'f', 35000,1, {2,9,1995},2},
        {8900, "Ailen", 'f', 39000,1, {12,3,1996},2},
        {6599, "Silvia", 'f', 43200,1, {11,1,2017}, 3},
        {3234, "Brisa", 'f', 32300,0, {19,10,2003},3},
        {7623, "Juan Carlos", 'm', 35000,0, {23,6,2011}, 2}
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }
}

void harcodeComidas(eComida x[], int tam)
{
    eComida hardcode[]=
    {
        {1, "Milanesa"},
        {2, "Pescado"},
        {3, "Tortilla"},
        {4, "Salmon"},
        {5, "Empanadas"}

    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
    }
}

void harcodeAlmuerzos(eAlmuerzo x[], int tam)
{
    eAlmuerzo hardcode[]=
    {
        {100,1234,1,{12,4,2019}},
        {101,2222,3,{13,4,2019}},
        {102,2211,2,{13,4,2019}},
        {103,3241,4,{15,4,2019}},
        {104,8944,5,{13,4,2019}},
        {105,2231,1,{17,4,2019}},
        {106,6578,3,{17,4,2019}},
        {107,3425,5,{17,4,2019}},
        {108,8944,4,{24,4,2019}},
        {109,7654,2,{25,4,2019}},
        {110,8944,1,{12,4,2019}},
        {111,3456,3,{13,4,2019}},
        {112,8944,2,{13,4,2019}},
        {113,4567,4,{15,4,2019}},
        {114,8900,5,{26,4,2019}},
        {115,1234,2,{17,4,2019}},
        {116,6599,3,{17,4,2019}},
        {117,3234,5,{17,4,2019}},
        {118,1234,4,{20,4,2019}},
        {119,7623,2,{21,4,2019}}
    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
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

void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
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
        printf("10- Empleados con el mismo Salario\n");
        printf("11- Cant de Hombres x Sector\n");
        printf("12- Empleado que menos gana\n");
        printf("13- Almuerzos x Empleado\n");
        printf("14- Almuerzos x Fecha\n");
        printf("15- Mostrar Empleados sg la comida\n");
        printf("16- Mostrar Almuerzos del mismo Dia\n");
        printf("17- Mostrar el almuerzo mas comido\n");
        printf("18- Almuerzos x Sector\n");
        printf("19- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            printf("\n\n");
            printf("Ingrese anio a buscar: ");
            scanf("%d",&anio);

            empleadoXanio(x,tam,anio,sec,tamSec);
            break;

        case 2:
            listarEmpXsector(x,tam,sec,tamSec);
            break;

        case 3:
            totalEmpxSector(x,tam,sec,tamSec);
            break;

        case 4:
            empXsector(x,tam,sec,tamSec);
            break;

        case 5:
            sectMasEmpleados(x,tam,sec,tamSec);
            break;

        case 6:
            empMasGanadorXsector(x,tam,sec,tamSec);
            break;

        case 7:
            sectorMujeres(x,tam,sec,tamSec);
            break;

        case 8:
            promSector(x,tam,sec,tamSec);
            break;

        case 9:
            menorIgual2009(x,tam,sec,tamSec);
            break;

        case 10:
            mismoSalario(x,tam,sec,tamSec);
            break;

        case 11:
            cantHombres(x,tam,sec,tamSec);
            break;

        case 12:
            empMasPerdedor(x,tam,sec,tamSec);
            break;


        case 13:
            almuerzosXemp(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 14:
            almuerzosXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 15:
            almuerzosXdescrip(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 16:
            almuerzosXmismaFecha(x,tam,com,tamCom,alm,tamAlm);
            break;

        case 17:

            break;


        case 18:
            almuerzosXsector(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 19:
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
    int flag;

    for(int i=0; i<tamSec; i++)
    {
        flag = 0;
        mayor = 0;
        for(int j=0; j<tam; j++)
        {

            if( (x[j].sueldo > mayor || flag ==0) && x[j].sector == sec[i].id && x[j].ocupado == 1 )
            {
                mayor = x[j].sueldo;

                flag = 1;
            }

        }

        if(flag == 0)
        {
            printf("Esta vacio\n");
        }
        else
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].sueldo == mayor && x[i].ocupado == 1 && x[j].sector == sec[i].id )
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

void mismoSalario(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float mismo;
    int flag;

    for(int i=0; i<tamSec; i++)
    {
        flag = 0;
        mismo = 0;

        for(int j=0; j<tam; j++)
        {

            if( (x[j].sueldo == mismo || flag ==0) && x[j].ocupado == 1 )
            {
                mismo = x[j].sueldo;

                flag = 1;
            }

        }

        if(flag == 0)
        {
            printf("Esta vacio\n");
        }
        else
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].sueldo == mismo && x[j].ocupado == 1 && x[j].sector == sec[i].id)
                {
                    mostrarEmpleado(x[j],sec,tamSec);
                }
            }
        }
    }
}

void cantHombres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int cont = 0;

    for(int i=0; i<tamSec; i++)
    {

        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == 1 && x[j].sexo == 'm')
            {
                cont++;
            }
        }

    }

    printf("\n\n");
    printf("Total de hombres x Sector: %d\n\n",cont);

    if(cont == 0)
    {
        printf("No hay ningun hombre\n");
    }
}

void empMasPerdedor(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    float menor;

    for(int i=0; i<tamSec; i++)
    {
        menor = 99999;

        for(int j=0; j<tam; j++)
        {

            if(x[j].sueldo < menor && x[j].ocupado==1)
            {
                menor = x[j].sueldo;
            }
        }
    }

    for (int i=0; i<tam; i++)
    {
        if (x[i].sueldo == menor && x[i].ocupado == 1)
        {
            printf("Empleado que menos gana\n");
            printf("\n\n");
            mostrarEmpleado(x[i],sec,tamSec);
            break;
        }
    }
}

void mostrarAlmuerzo(eAlmuerzo alm, eEmpleado emp[], int tam, eComida com[], int tamCom)
{
    eEmpleado emp1;

    char cadena[20];
    int indice;

    indice = buscarEmpleado(emp,tam,alm.idEmpleado);

    emp1 = emp[indice];

    mostrarComidas(com,tamCom,alm.idComida,cadena);

    printf("%4d %d %10s %10s %02d/%02d/%d\n", alm.id, emp1.legajo, emp1.nombre, cadena, alm.fecha.dia, alm.fecha.mes, alm.fecha.anio);


}

void mostrarAlmuerzos(eAlmuerzo alm[], int tamAlm, eEmpleado emp[], int tam, eComida com[], int tamCom)
{
    int flag = 0;

    system("cls");
    printf("  ID   Legajo   Nombre  Comida  Fecha\n\n");

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if((alm[i].idEmpleado == emp[j].legajo || flag ==0 ) && emp[j].ocupado == 1)
            {
                for(int k=0; k<tamCom; k++)
                {
                    if(alm[i].idComida == com[k].id)
                    {
                        mostrarAlmuerzo(alm[i],emp,tam,com,tamCom);
                        flag = 1;
                    }
                }
            }
        }
    }

    if(flag == 0)
    {
        printf("No hay almuerzos cargados\n");
    }
}


void listarComidas(eComida x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s\n",x[i].id,x[i].descripcion);
    }
}

void mostrarComidas(eComida x[], int tam, int idComida, char cadena[])
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].id == idComida)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,x[i].descripcion);

        }
    }
}

void almuerzosXemp(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int legajo;
    int flag = 0;

    system("cls");

    mostrarEmpleados(x,tam,sec,tamSec);

    printf("Ingrese el legajo  a buscar: ");
    scanf("%d",&legajo);

    printf("\n\n");

    printf("ALMUERZOS DEL EMPLEADO %d\n",legajo);

    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].idEmpleado == legajo)
        {
            for(int k=0; k<tamCom; k++)
            {
                if(alm[i].idComida == com[k].id)
                {
                    printf("%d %10s\n",alm[i].id,com[k].descripcion);
                    flag = 1;

                }
            }
        }
    }

    if(flag == 0)
    {
        printf("Este empleado no tiene ningun almuerzo registrado\n");
    }
}

void almuerzosXfecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int flag = 0;
    eFecha fecha;

    system("cls");

    printf("Ingrese fecha de ingreso dd/mm/aaaa: ");
    scanf("%d %d %d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(comparar(alm[i].fecha,fecha) && alm[i].idEmpleado == x[j].legajo && x[j].ocupado == 1)
            {

                for(int j=0; j<tam; j++)
                {
                    if(x[j].ocupado == 1)
                    {
                        flag = 1;
                        mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                        break;
                    }
                }


            }

        }
    }

    if(flag == 0)
    {
        printf("Ningun empleado almorzo este dia\n");
    }

}

void almuerzosXdescrip(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    char descrip[20];
    int flag = 0;

    system("cls");

    listarComidas(com,tamCom);

    printf("Ingrese la comida a buscar: ");
    fflush(stdin);
    gets(descrip);

    printf("\n\n");

    for(int i=0; i<tamAlm; i++)
    {
        for(int j=0; j<tam; j++)
        {
            for(int k=0; k<tamCom; k++)
            {
                if(x[j].ocupado == 1 && x[j].legajo == alm[i].idEmpleado && stricmp(com[k].descripcion,descrip)==0 && com[k].id == alm[i].idComida)
                {
                    flag = 1;
                    mostrarEmpleado(x[j],sec,tamSec);
                }
            }
        }
    }

    if(flag == 0)
    {
        printf("Nadie almorzo esta comida\n");
    }
}

void almuerzosXmismaFecha(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
{

    for(int i=0; i<tamAlm; i++)
    {
        //alm[i].fecha.dia == alm[i].fecha.dia && alm[i].fecha.mes == alm[i].fecha.mes && alm[i].fecha.anio == alm[i].fecha.anio
        if(comparar(alm[i].fecha,alm[i].fecha)==1)
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].ocupado == 1 && x[j].legajo == alm[i].idEmpleado)
                {
                    mostrarAlmuerzo(alm[i],x,tam,com,tamCom);
                }
            }
        }
    }
}

int comparar(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}

void almuerzosXsector(eEmpleado x[], int tam, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm, eSector sec[], int tamSec)
{
    int sector;

    listarSectores(sec,tamSec);

    printf("Ingrese ID Sector:");
    scanf("%d",&sector);

    for(int i=0; i<tam; i++)
    {
        if(x[i].sector == sector && x[i].ocupado == 1)
        {
            for(int j=0; j<tamAlm; j++)
            {
                if(alm[j].idEmpleado == x[i].legajo)
                {
                    for(int k=0; k<tamCom; k++)
                    {
                        if(alm[j].idComida == com[k].id)
                        {
                            printf("%s %s %0d/%0d/%d\n",x[i].nombre,com[k].descripcion,alm[j].fecha);
                            break;
                        }
                    }

                }
            }
        }
    }
}
