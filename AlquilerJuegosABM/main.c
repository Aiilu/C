#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define TAM 10
#define ALQ 15
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int codigo;
    char nombre[51];
    char sexo;
    char telefono[51];
    char domicilio[51];
    int ocupado;

} eCliente;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
    int ocupado;

} eAlquileres;

typedef struct
{
    int id;
    char descripcion[20];

} eCategoria;

typedef struct
{
    int codigo;
    char descripcion[51];
    int importe;
    int idCategoria;

} eJuego;

/*------------------------------------------------------------------------------------------------------------------

                                            PROTOTIPOS

--------------------------------------------------------------------------------------------------------------------*/

int menu();
void inicializarClientes(eCliente x[], int tam);

int cargarId();
char validarSeguir();
/*------------------------------------------------------------------------------------------------------------------

                                                 MAIN

--------------------------------------------------------------------------------------------------------------------*/

int main()
{
    char seguir = 's';

    eCliente cliente[TAM];
    eAlquileres alquiler[ALQ];
    eJuego juego[7];
    eCategoria categoria[5];

    inicializarClientes(cliente, TAM); // llamada
    inicializarAlquileres(alquiler, ALQ);

    harcodeJuegos(juego,7);
    harcodeCategorias(categoria,5);


    do
    {
        switch(menu())
        {


        case 1:
            altaCliente(cliente,TAM);
            system("pause");
            break;


        case 2:
            bajaCliente(cliente,TAM);
            system("pause");
            break;


        case 3:
            ModificacionCliente(cliente,TAM);
            system("pause");
            break;


        case 4:
            mostrarClientes(cliente,TAM);
            system("pause");
            break;


        case 5:
            listarXnombreSexo(cliente,TAM);
            system("pause");
            break;


        case 6:
            altaAlquiler(alquiler,ALQ,cliente,TAM,categoria,5,juego,7);
            system("pause");
            break;


        case 7:
            mostrarAlquileres(alquiler,ALQ,cliente,TAM,juego,7);
            system("pause");
            break;


        case 8:

            system("pause");
            break;


        case 9:
            system("cls");
            printf("Hasta luego");
            seguir = 'n';
            break;


        default:
            printf("\n     Opcion invalida\n\n");
            system("pause");
            break;
        }

    }
    while(seguir == 's');

    return 0;
}

/*------------------------------------------------------------------------------------------------------------------

                                           ABM EMPLEADO

--------------------------------------------------------------------------------------------------------------------*/

void inicializarClientes(eCliente x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].ocupado = VACIO;
    }
}



int menu()
{
    int opcion;
    system("cls");
    system("COLOR F0");
    printf("     =================================================\n");
    printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
    printf("     =================================================\n");
    printf("     |                                               |\n");
    printf("                  1- Alta Cliente                     \n");
    printf("     |                                               |\n");
    printf("                  2- Baja Cliente                    \n");
    printf("     |                                               |\n");
    printf("                  3- Modificacion Cliente             \n");
    printf("     |                                               |\n");
    printf("                  4- Informar                         \n");
    printf("     |                                               |\n");
    printf("                  5- Listar x Nombre/Sexo             \n");
    printf("     |                                               |\n");
    printf("                  6- Alta Alquiler                    \n");
    printf("     |                                               |\n");
    printf("                  7- Listar Alquileres                \n");
    printf("     |                                               |\n");
    printf("                  8- Informes                         \n");
    printf("     |                                               |\n");
    printf("                  9- Salir                            \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



int buscarLibre(eCliente x[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(x[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int buscarCliente(eCliente x[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( x[i].codigo == legajo && x[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void mostrarCliente(eCliente cliente)
{

    printf("     %d   %s   %c    %s   %s\n", cliente.codigo,cliente.nombre,cliente.sexo,cliente.telefono,cliente.domicilio);

}



void mostrarClientes(eCliente x[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(x[i].ocupado == OCUPADO)
        {

            mostrarCliente(x[i]);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("     No hay empleados que mostrar\n\n");
    }

}



void altaCliente(eCliente x[], int tam)
{
    int indice;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Cliente\n");
        indice = buscarLibre(x, tam);


        if(indice == -1)
        {
            printf("No hay lugar\n");
            system("pause");
            break;
        }
        else
        {


            x[indice].codigo = cargarId();

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(x[indice].nombre);


            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &x[indice].sexo);


            printf("Ingrese telefono: ");
            fflush(stdin);
            gets(x[indice].telefono);

            printf("Ingrese domicilio: ");
            fflush(stdin);
            gets(x[indice].domicilio);

            x[indice].ocupado = OCUPADO;

            printf("\nEl empleado ha sido registrado con exito!!!\n\n");

            printf("\n\n");

            seguir = validarSeguir();

        }

    }
    while(seguir == 'S' || seguir == 's');

}



void bajaCliente(eCliente x[], int tam)
{

    int legajo;
    char seguir;
    int esta;

    printf("Baja Cliente\n");
    printf("\n\n");
    mostrarClientes(x,tam);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    printf("\n\n");


    esta = buscarCliente(x,tam,legajo);


    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("Cliente a eliminar\n");
        mostrarCliente(x[esta]);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            x[esta].ocupado = VACIO;
            printf("\nCliente eliminado con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}



void ModificacionCliente(eCliente x[], int tam)
{

    int legajo;
    float sueldo;
    char nombre[51];
    char domicilio[51];
    char telefono[51];
    int opcion;
    int esta;
    char seguir;

    printf("Modificacion Cliente\n");
    printf("\n\n");
    mostrarClientes(x,tam);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);


    esta = buscarCliente(x, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("\n\n");
        printf("Empleado a modificar\n");
        mostrarCliente(x[esta]);

        printf("     Que desea modificar?\n");
        printf("     1. Nombre\n     2. Domicilio\n     3. Telefono\n");
        printf("     Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Modificar Nombre\n");

            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            gets(nombre);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                strcpy(x[esta].nombre,nombre);

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

            printf("Modificar Domicilio\n");

            printf("Ingrese nuevo domicilio: ");
            fflush(stdin);
            gets(domicilio);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                strcpy(x[esta].domicilio,domicilio);

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

            printf("Modificar Telefono\n");

            printf("Ingrese nuevo telefono: ");
            fflush(stdin);
            gets(telefono);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                strcpy(x[esta].telefono,telefono);

                printf("\n\n");
                printf("Modificacion exitosa!\n");
            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        default:
            printf("Esta opcion no existe\n");
            break;

        }
    }

}

void listarXnombreSexo(eCliente x[], int tam)
{
    eCliente aux;

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
            else if(strcmp(x[i].nombre,x[j].nombre)== 0 && x[i].sexo > x[j].sexo)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
     }
    }

    mostrarClientes(x,tam);
}

/*void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
{
    char seguir = 's';
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
        printf("10- Cant de Comidas Comidas\n");
        printf("11- Cant de Hombres x Sector\n");
        printf("12- Empleado que menos gana\n");
        printf("13- Almuerzos x Empleado\n");
        printf("14- Almuerzos x Fecha\n");
        printf("15- Mostrar Empleados sg la descripcion comida\n");
        printf("16- Mostrar Almuerzos del mismo Dia\n");
        printf("17- Mostrar el almuerzo mas comido\n");
        printf("18- Almuerzos x Sector\n");
        printf("19- Clientes que no comieron\n");
        printf("20- Almuerzos x Hombres\n");
        printf("21- Comidas + comidas x Mujeres\n");
        printf("22- Almuerzos de los empleados mas perdedores\n");
        printf("23- Importes pagados x Cliente\n");
        printf("24- Recaudacion x Fecha\n");
        printf("25- Mostrar Empleados sg ID Comida\n");
        printf("26- Mostrar mujeres sg comida\n");
        printf("27- Almuerzo mas Comido x Sector\n");
        printf("28- Listar Empleados x Sector/Nombre\n");
        printf("29- Salir\n\n");
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
            contadorComida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
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
            almuerzosMasComido2(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 18:
            almuerzosXsector(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 19:
            empleadosQueNoAlmorzaron(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 20:
            AlmuerzosXhombres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 21:
            AlmuerzosMasComidosXmujeres(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 22:
            almuerzosEmpMasPerdedor(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 23:
            importesEmpleado(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;

        case 24:
            totalXfecha(x,tam,com,tamCom,alm,tamAlm,sec,tamSec);
            break;


        case 25:
            almuerzoXcomida(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 26:
            almuerzosXmujeres(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 27:
            almuerzoMasComidoXsector(x,tam,sec,tamSec,alm,tamAlm,com,tamCom);
            break;


        case 28:
            ordenarEmpXsectorYnombre(x,tam,sec,tamSec);
            break;

        case 29:
            seguir = 'n';
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
*/
/*------------------------------------------------------------------------------------------------------------------

                                       HARCODEOS/OBTENER

--------------------------------------------------------------------------------------------------------------------*/

/*void harcodeEmpleado(eEmpleado vec[], int tam)
{
    eEmpleado hardcode[]=
    {
        {1234, "Juan", 'm', 30000,1,{12,3,2000}, 4},
        {2222, "Ana", 'f', 28000,1, {2,7,2010},1},
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
}*/

void harcodeCategorias(eCategoria cat[], int tamCat)
{
    eCategoria hardcode[]=
    {
        {1, "Juego de Mesa"},
        {2, "Juego de Azar"},
        {3, "Juego de Estrategia"},
        {4, "Juego de Salon"},
        {5, "Juego de Magia"}
    };

    for(int i=0; i<tamCat; i++)
    {
        cat[i]=hardcode[i];
    }
}

void listarCategorias(eCategoria cat[], int tamCat)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tamCat; i++)
    {
        printf(" %d   %s\n",cat[i].id,cat[i].descripcion);
    }
}

void listarJuegos(eJuego ju[], int tamJu, eCategoria cat[], int tamCat)
{
    printf(" ID   Descripcion   Importe\n");
    printf("\n\n");

    for(int i=0; i<tamJu; i++)
    {
            printf(" %d   %s   %d\n",ju[i].codigo,ju[i].descripcion,ju[i].importe);
    }
}

void ObtenerCategorias(eCategoria cat[], int tamCat, int idCategoria, char cadena[])
{
    for(int i=0; i<tamCat; i++)
    {
        if(cat[i].id == idCategoria)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,cat[i].descripcion);

        }
    }
}


void harcodeJuegos(eJuego ju[], int tamJu)
{
    eJuego hardcode[]=
    {
        {1, "Ajedrez", 45, 1},
        {2, "Truco", 50, 1},
        {3, "Jenga", 130, 2},
        {4, "Twister", 200, 3},
        {5, "Escondidas", 100, 4},
        {6, "TaTeTi",20, 5},
        {7, "Wally",100, 5}

    };

    for(int i=0; i<tamJu; i++)
    {
        ju[i]=hardcode[i];
    }
}


void obtenerJuegos(eJuego ju[], int tamJu, int idJuego, char cadena[])
{
    for(int i=0; i<tamJu; i++)
    {
        if(ju[i].codigo == idJuego)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,ju[i].descripcion);
        }
    }
}


/*void harcodeAlmuerzos(eAlmuerzo x[], int tam)
{
    eAlmuerzo hardcode[]=
    {
        {100,1234,1,{12,4,2019},0},
        {101,2222,3,{13,4,2019},1},
        {102,2211,2,{13,4,2019},1},
        {103,3241,4,{15,4,2019},1},
        {104,8944,5,{13,4,2019},1},
        {105,2231,1,{17,4,2019},1},
        {106,6578,3,{17,4,2019},1},
        {107,3425,5,{17,4,2019},0},
        {108,8944,4,{24,4,2019},1},
        {109,7654,2,{25,4,2019},1},
        {110,8944,1,{12,4,2019},1},
        {111,3456,3,{13,4,2019},1},
        {112,8944,2,{13,4,2019},1},
        {113,4567,4,{15,4,2019},1},
        {114,8900,5,{26,4,2019},1},
        {115,1234,2,{17,4,2019},1},
        {116,6599,3,{17,4,2019},1},
        {117,3234,5,{17,4,2019},1},
        {118,1234,4,{20,4,2019},1},
        {119,7623,2,{21,4,2019},1}
    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
    }
}
*/
/*------------------------------------------------------------------------------------------------------------------

                                ALTA ALMUERZOS

--------------------------------------------------------------------------------------------------------------------*/

void inicializarAlquileres(eAlquileres alq[], int tamAlq)
{

    for(int i=0; i < tamAlq; i++)
    {
        alq[i].ocupado = VACIO;
    }
}



int buscarLibreAlquiler(eAlquileres alq[], int tamAlq)
{

    int indice = -1;

    for(int i=0; i < tamAlq; i++)
    {
        if(alq[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarAlquileres(eAlquileres alq[], int tamAlq, int legajo)
{
    int indice= -1;

    for(int i=0; i<tamAlq; i++)
    {
        if(alq[i].codAlquiler == legajo && alq[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}



void altaAlquiler(eAlquileres alq[], int tamAlq, eCliente x[], int tam, eCategoria cat[], int tamCat, eJuego ju[], int tamJu)
{
    int id;
    int idJuego;
    int indice;
    char seguir;
    eFecha fecha;

    do
    {

        system("cls");
        printf("Alta Alquileres\n");


        indice = buscarLibreAlquiler(alq,tamAlq);


        if(indice == -1)
        {
            printf("No hay mas espacio para cargar alquileres\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {
            alq[indice].codAlquiler = cargarIdAlquiler();


            mostrarClientes(x,tam);


            printf("Ingrese ID Cliente: ");
            scanf("%d",&id);


            alq[indice].codCliente = id;

            listarJuegos(ju,tamJu,cat,tamCat);
            fflush(stdin);
            printf("Ingrese ID Juego: ");
            scanf("%d",&idJuego);


            alq[indice].codJuego = idJuego;


            printf("Ingrese fecha de Alquiler\n");
            printf("dd/mm/aaaa: ");
            scanf("%d %d %d",&fecha.dia,&fecha.mes,&fecha.anio);


            alq[indice].fecha = fecha;


            alq[indice].ocupado = OCUPADO;


            printf("El Alquiler se ha registrado con exito!!\n");


            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}

void mostrarAlquiler(eAlquileres alq, eCliente x[], int tam, eJuego ju[], int tamJu)
{
    char nombre[20];
    char juego[20];
    int loMuestro;

    for(int i=0; i<tam; i++)
    {
        if(x[i].codigo == alq.codCliente)
        {
            strcpy(nombre,x[i].nombre);
            loMuestro = x[i].ocupado;
            break;
        }
    }

    for(int j=0; j<tamJu; j++)
    {
        if(ju[j].codigo == alq.codJuego)
        {
            strcpy(juego,ju[j].descripcion);
            break;
        }
    }

    if(loMuestro)
    {
        printf("%4d %02d/%02d/%d %d %10s %10s\n", alq.codAlquiler, alq.fecha.dia, alq.fecha.mes, alq.fecha.anio, alq.codCliente, nombre, juego);
    }

}



void mostrarAlquileres(eAlquileres alq[], int tamAlq, eCliente x[], int tam, eJuego ju[], int tamJu)
{
    int flag = 0;

    system("cls");
    printf("  ID Alquiler  Fecha  ID Cliente  Nombre  Juego\n\n");


    for(int i=0; i<tamAlq; i++)
    {
        if(alq[i].ocupado == OCUPADO)
        {
            mostrarAlquiler(alq[i],x,tam,ju,tamJu);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay alquileres cargados\n");
    }

}

/*------------------------------------------------------------------------------------------------------------------

                                                VALIDACIONES

--------------------------------------------------------------------------------------------------------------------*/

int cargarId()
{
    static int id = 1;


    return id++;
}

int cargarIdAlquiler()
{
    static int idAlquiler = 1000;


    return idAlquiler++;
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


int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}
