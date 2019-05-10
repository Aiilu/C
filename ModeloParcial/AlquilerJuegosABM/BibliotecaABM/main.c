#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define SOC 10
#define LIB 10
#define AUT 5
#define PRE 15
#define VACIO 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[51];
    char email[51];
    eFecha fechaIngreso;
    int ocupado;

} eSocio;

typedef struct
{
    int cod;
    char titulo[51];
    int codAutor;

} eLibros;

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];

} eAutores;

typedef struct
{
    int codPrestamo;
    int codLibro;
    int codSocio;
    eFecha fechaPrestamo;
    int ocupado;

} ePrestamos;

/*------------------------------------------------------------------------------------------------------------------

                                            PROTOTIPOS

--------------------------------------------------------------------------------------------------------------------*/

int cargarId();
char validarSeguir();
/*------------------------------------------------------------------------------------------------------------------

                                                 MAIN

--------------------------------------------------------------------------------------------------------------------*/

int main()
{
    char seguir = 's';

    eSocio socio[SOC];
    eLibros libro[LIB];
    eAutores autor[AUT];
    ePrestamos prestamo[PRE];

    inicializarSocios(socio, SOC); // llamada
    inicializarPrestamos(prestamo,PRE);

    harcodeLibros(libro,LIB);
    harcodeAutores(autor,AUT);


    do
    {
        switch(menu())
        {


        case 1:
            altaSocio(socio,SOC);
            system("pause");
            break;


        case 2:
            bajaSocio(socio,SOC);
            system("pause");
            break;


        case 3:
            ModificacionSocio(socio,SOC);
            system("pause");
            break;


        case 4:
            menuListar(socio,SOC,libro,LIB,autor,AUT);
            system("pause");
            break;


        case 5:
            altaPrestamo(prestamo,PRE,socio,SOC,libro,LIB,autor,AUT);
            system("pause");
            break;


        case 6:
            mostrarPrestamos(prestamo,PRE,socio,SOC,libro,LIB,autor,AUT);
            system("pause");
            break;


        case 7:
            //mostrarAlquileres(alquiler,ALQ,cliente,TAM,juego,7);
            system("pause");
            break;

        case 8:
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

void inicializarSocios(eSocio x[], int tam)
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
    printf("                  1- Alta Socio                       \n");
    printf("     |                                               |\n");
    printf("                  2- Baja Socio                       \n");
    printf("     |                                               |\n");
    printf("                  3- Modificacion Socio               \n");
    printf("     |                                               |\n");
    printf("                  4- Listar                           \n");
    printf("     |                                               |\n");
    printf("                  5- Alta Prestamo                    \n");
    printf("     |                                               |\n");
    printf("                  6- Listar Prestamos                 \n");
    printf("     |                                               |\n");
    printf("                  7- Informes                         \n");
    printf("     |                                               |\n");
    printf("                  8- Salir                            \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



int buscarLibre(eSocio x[], int tam)
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



int buscarSocio(eSocio x[], int tam, int legajo)
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

int buscarLibro(eLibros x[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( x[i].cod == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void mostrarSocio(eSocio socio)
{

    printf("     %d   %s   %s    %c   %s   %s   %0d/%0d/%d\n", socio.codigo, socio.nombre, socio.apellido, socio.sexo, socio.telefono, socio.email, socio.fechaIngreso.dia, socio.fechaIngreso.mes, socio.fechaIngreso.anio);

}

void mostrarAutor(eAutores autor)
{

    printf("     %d   %s   %s\n", autor.id, autor.nombre, autor.apellido);

}

void mostrarLibro(eLibros libro)
{

    printf("     %d   %s\n", libro.cod, libro.titulo);

}



void mostrarLibros(eLibros x[], int tam)
{

    for(int i=0; i < tam; i++)
    {
            mostrarLibro(x[i]);
    }

}


void mostrarAutores(eAutores x[], int tam)
{

    for(int i=0; i < tam; i++)
    {
           mostrarAutor(x[i]);
    }

}



void mostrarSocios(eSocio x[], int tam)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(x[i].ocupado == OCUPADO)
        {

            mostrarSocio(x[i]);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("     No hay socios que mostrar\n\n");
    }

}



void altaSocio(eSocio x[], int tam)
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


            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(x[indice].apellido);


            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &x[indice].sexo);


            printf("Ingrese telefono: ");
            fflush(stdin);
            gets(x[indice].telefono);

            printf("Ingrese Email: ");
            fflush(stdin);
            gets(x[indice].email);

            printf("Ingrese fecha de Ingreso\n");
            printf("Formato aa/mm/dddd (dejen una coma donde deberia estar la barra): ");
            scanf("%d %d %d",&x[indice].fechaIngreso.dia,&x[indice].fechaIngreso.mes,&x[indice].fechaIngreso.anio);

            x[indice].ocupado = OCUPADO;

            printf("\nEl Socio ha sido registrado con exito!!!\n\n");

            printf("\n\n");

            seguir = validarSeguir();

        }

    }
    while(seguir == 'S' || seguir == 's');

}

void menuListar(eSocio x[],int tam, eLibros lib[], int tamLib, eAutores aut[], int tamAut)
{
    char seguir = 's';
    int opcion;

    do
    {

        system("cls");
        printf("1- Listar x Apellido/Nombre\n");
        printf("2- Listar Libros x Titulo\n");
        printf("3- Listar Autores por Nombre\n");
        printf("4- Salir\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {

        case 1:
            listarXapellidoNombre(x,tam);
            break;

        case 2:
            listarLibroXtitulo(lib,tamLib);
            break;

        case 3:
            listarAutorXnombre(aut,tamAut);
            break;

        case 4:
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

void listarLibroXtitulo(eLibros lib[], int tamLib)
{
    eLibros aux;

    for(int i=0; i<tamLib-1; i++)
    {
        for(int j=i+1; j<tamLib; j++)
        {
            if(strcmp(lib[i].titulo,lib[j].titulo)>0)
            {
                aux = lib[i];
                lib[i] = lib[j];
                lib[j] = aux;
            }
        }
    }

    mostrarLibros(lib,tamLib);
}


void listarAutorXnombre(eAutores aut[], int tamAut)
{
    eAutores aux;

    for(int i=0; i<tamAut-1; i++)
    {
        for(int j=i+1; j<tamAut; j++)
        {
            if(strcmp(aut[i].nombre,aut[j].nombre)>0)
            {
                aux = aut[i];
                aut[i] = aut[j];
                aut[j] = aux;
            }
        }
    }

    mostrarAutores(aut,tamAut);

}
void bajaSocio(eSocio x[], int tam)
{

    int legajo;
    char seguir;
    int esta;

    printf("Baja Socio\n");
    printf("\n\n");
    mostrarSocios(x,tam);

    printf("Ingrese Codigo Socio: ");
    scanf("%d", &legajo);
    printf("\n\n");


    esta = buscarSocio(x,tam,legajo);


    if( esta == -1)
    {

        printf("\nEl codigo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("Socio a eliminar\n");
        mostrarSocio(x[esta]);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            x[esta].ocupado = VACIO;
            printf("\nSocio eliminado con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}


void ModificacionSocio(eSocio x[], int tam)
{

    int legajo;
    float sueldo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char email[51];
    char telefono[51];
    int opcion;
    int esta;
    char seguir;

    printf("Modificacion Socio\n");
    printf("\n\n");
    mostrarSocios(x,tam);

    printf("Ingrese Codigo Socio: ");
    scanf("%d", &legajo);


    esta = buscarSocio(x, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl Codigo %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("\n\n");
        printf("Socio a modificar\n");
        mostrarSocio(x[esta]);

        printf("     Que desea modificar?\n");
        printf("     1. Nombre\n     2. Apellido\n     3. Sexo\n     4. Telefono\n     5. Email\n");
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

            printf("Modificar Apellido\n");

            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            gets(apellido);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                strcpy(x[esta].apellido,apellido);

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

            printf("Modificar Sexo\n");

            printf("Ingrese nuevo sexo: ");
            fflush(stdin);
            scanf("%c",&sexo);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                x[esta].sexo = sexo;

                printf("\n\n");
                printf("Modificacion exitosa!\n");
            }
            else
            {
                printf("\n\n");
                printf("     Modificacion cancelada\n");
            }
            break;

        case 4:
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

        case 5:
            system("cls");

            printf("Modificar Email\n");

            printf("Ingrese nuevo email: ");
            fflush(stdin);
            gets(email);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {
                strcpy(x[esta].email,email);

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

void listarXapellidoNombre(eSocio x[], int tam)
{
    eSocio aux;

    for(int i=0; i<tam; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(x[i].apellido,x[j].apellido)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
            else if(strcmp(x[i].apellido,x[j].apellido)== 0 && strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }

    mostrarSocios(x,tam);
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

void harcodeLibros(eLibros lib[], int tamLib)
{
    eLibros hardcode[]=
    {
        {101, "Insomnia",1},
        {102, "Pulsaciones",2},
        {103, "Harry Potter",3},
        {104, "El cuarto mono",5},
        {105, "El señor de los Anillos",7},
        {106, "Sky",7},
        {107, "Monster High",7},
        {108, "Bajo la misma Estrella",3},
        {109, "Juegos del Hambre",2},
        {110, "Un hombre en el cuarto",5}
    };

    for(int i=0; i<tamLib; i++)
    {
        lib[i]=hardcode[i];
    }
}

void listarLibros(eLibros lib[], int tamLib)
{
    printf(" codLibro   Titulo\n");
    printf("\n\n");

    for(int i=0; i<tamLib; i++)
    {
        printf(" %d   %s\n",lib[i].cod,lib[i].titulo);
    }
}

void listarAutores(eAutores aut[], int tamAut)
{
    printf(" codAutor   Nombre   Apellido\n");
    printf("\n\n");

    for(int i=0; i<tamAut; i++)
    {
        printf(" %d   %s   %s\n",aut[i].id,aut[i].nombre,aut[i].apellido);
    }
}

void ObtenerLibros(eLibros lib[], int tamLib, int idLibros, char cadena[])
{
    for(int i=0; i<tamLib; i++)
    {
        if(lib[i].cod == idLibros)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,lib[i].titulo);

        }
    }
}


void harcodeAutores(eAutores aut[], int tamAut)
{
    eAutores hardcode[]=
    {
        {1, "Mirian","Casandra"},
        {2, "Ailen","Torrez"},
        {3, "Felipe","Contreras"},
        {5, "Anastasia","Grey"},
        {7, "Bunge","Mario"}

    };

    for(int i=0; i<tamAut; i++)
    {
        aut[i]=hardcode[i];
    }
}


/*------------------------------------------------------------------------------------------------------------------

                                ALTA ALMUERZOS

--------------------------------------------------------------------------------------------------------------------*/

void inicializarPrestamos(ePrestamos pre[], int tamPre)
{

    for(int i=0; i < tamPre; i++)
    {
        pre[i].ocupado = VACIO;
    }
}



int buscarLibrePrestamo(ePrestamos pre[], int tamPre)
{

    int indice = -1;

    for(int i=0; i < tamPre; i++)
    {
        if(pre[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarPrestamos(ePrestamos pre[], int tamPre, int legajo)
{
    int indice= -1;

    for(int i=0; i<tamPre; i++)
    {
        if(pre[i].codPrestamo == legajo && pre[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}



void altaPrestamo(ePrestamos pre[], int tamPre, eSocio x[], int tam, eLibros lib[], int tamLib, eAutores aut[], int tamAut)
{
    int id;
    int idLibro;
    int indice;
    int esta;
    int esta2;
    char seguir;
    eFecha fecha;

    do
    {

        system("cls");
        printf("Alta Prestamos\n");


        indice = buscarLibrePrestamo(pre,tamPre);


        if(indice == -1)
        {
            printf("No hay mas espacio para cargar prestamos\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {
            pre[indice].codPrestamo = cargarIdPrestamo();

            mostrarSocios(x,tam);


            printf("Ingrese codSocio: ");
            scanf("%d",&id);


            esta = buscarSocio(x,tam,id);

            if(esta == -1)
            {
                printf("No existe\n");
                printf("\n\n");
                system("pause");
                break;
            }
            else
            {
               pre[esta].codSocio = id;
            }


            listarLibros(lib,tamLib);
            fflush(stdin);
            printf("Ingrese codLibro: ");
            scanf("%d",&idLibro);


            esta2 = buscarLibro(lib,tamLib,idLibro);

            if(esta2 == -1)
            {
                printf("No existe\n");
                printf("\n\n");
                system("pause");
                break;
            }
            else
            {
              pre[esta2].codLibro = idLibro;
            }


            printf("Ingrese fecha de Prestamo\n");
            printf("dd/mm/aaaa: ");
            scanf("%d %d %d",&fecha.dia,&fecha.mes,&fecha.anio);


            pre[indice].fechaPrestamo = fecha;


            pre[indice].ocupado = OCUPADO;


            printf("El Prestamo se ha registrado con exito!!\n");


            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}

void mostrarPrestamo(ePrestamos pre, eSocio x[], int tam, eLibros lib[], int tamLib, eAutores aut[], int tamAut)
{
    char nombre[51];
    char titulo[51];
    char nombreAutor[51];
    int loMuestro;

    for(int i=0; i<tam; i++)
    {
        if(x[i].codigo == pre.codSocio)
        {
            strcpy(nombre,x[i].nombre);
            loMuestro = x[i].ocupado;
            break;
        }
    }

    for(int j=0; j<tamLib; j++)
    {
        if(lib[j].cod == pre.codLibro)
        {
            for(int k=0; k<tamAut; k++)
            {
                if(lib[j].codAutor == aut[k].id)
                {
                    strcpy(titulo,lib[j].titulo);
                    strcpy(nombreAutor,aut[k].nombre);
                    break;
                }
            }
        }
    }

    if(loMuestro)
    {
        printf("%4d %02d/%02d/%d %d %10s %10s %10s\n", pre.codPrestamo, pre.fechaPrestamo.dia, pre.fechaPrestamo.mes, pre.fechaPrestamo.anio, pre.codSocio, nombre, titulo, nombreAutor);
    }

}



void mostrarPrestamos(ePrestamos pre[], int tamPre, eSocio x[], int tam, eLibros lib[], int tamLib, eAutores aut[], int tamAut)
{
    int flag = 0;

    system("cls");
    printf("  codPrestamos  Fecha  codCliente  Nombre  Libro  Autor\n\n");


    for(int i=0; i<tamPre; i++)
    {
        if(pre[i].ocupado == OCUPADO)
        {
            mostrarPrestamo(pre[i],x,tam,lib,tamLib,aut,tamAut);
            flag = 1;
        }
    }


    if(flag == 0)
    {
        printf("No hay prestamos cargados\n");
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

int cargarIdPrestamo()
{
    static int idPrestamo = 1000;


    return idPrestamo++;
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
