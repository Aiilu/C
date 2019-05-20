#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>

#define PELI 15
#define CAT 5
#define ACT 10
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
    int id;
    char titulo[50];
    eFecha fecha;
    int categoria;
    int ocupado;
} ePeliculas;

typedef struct
{
    int id;
    char descripcion[20];

} eCategorias;

typedef struct
{
    int id;
    int idPelicula;
    int idCategoria;
    char nombre[20];
    char pais[20];
    int ocupado;
} eActor;

/*------------------------------------------------------------------------------------------------------------------

                                            PROTOTIPOS

--------------------------------------------------------------------------------------------------------------------*/
char validarSeguir();
int cargarId();
int cargarIdActor();
/*------------------------------------------------------------------------------------------------------------------

                                                 MAIN

--------------------------------------------------------------------------------------------------------------------*/

int main()
{
    char seguir = 's';

    ePeliculas peliculas[PELI];
    eCategorias categorias[CAT];
    eActor actores[ACT];

    harcodePeliculas(peliculas,PELI);
    harcodeCategorias(categorias,CAT);

    //inicializarEmpleados(lista, TAM); // llamada
    inicializarActores(actores,ACT);


    do
    {
        switch(menu())
        {


        case 1:
            //altaEmpleado(lista, TAM, sector, SEC);
            altaPelicula(peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 2:
            //bajaEmpleado(lista, TAM, sector, SEC);
            bajaPeliculas(peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 3:
            //ModificacionEmpleado(lista,TAM, sector, SEC);
            ModificacionPeliculas(peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 4:
            //menuInformes(lista,TAM, sector, SEC, comida, COM, almuerzo, ALM);
            mostrarPeliculas(peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 5:
            //mostrarEmpleados(lista, TAM, sector, SEC);
            ordenarXanio(peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 6:
            //altaAlmuerzo(lista,TAM,sector,SEC,almuerzo,ALM,comida,COM);
            altaActor(actores,ACT,categorias,CAT,peliculas,PELI);
            system("pause");
            break;


        case 7:
            //mostrarAlmuerzos(almuerzo,ALM,lista,TAM,comida,COM);
            mostrarActores(actores,ACT,peliculas,PELI,categorias,CAT);
            system("pause");
            break;

        case 8:
            //mostrarAlmuerzos(almuerzo,ALM,lista,TAM,comida,COM);
            ordenarActoresXpais(actores,ACT,peliculas,PELI,categorias,CAT);
            system("pause");
            break;


        case 9:
            //mostrarAlmuerzos(almuerzo,ALM,lista,TAM,comida,COM);
            system("pause");
            break;

        case 10:
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

void inicializarPeliculas(ePeliculas vec[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        vec[i].ocupado = VACIO;
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
    printf("                  1- Alta Pelicula                    \n");
    printf("     |                                               |\n");
    printf("                  2- Baja Pelicula                    \n");
    printf("     |                                               |\n");
    printf("                  3- Modificacion Pelicula            \n");
    printf("     |                                               |\n");
    printf("                  4- Mostrar Peliculas                \n");
    printf("     |                                               |\n");
    printf("                  5- Mostrar Peliculas x Anio         \n");
    printf("     |                                               |\n");
    printf("                  6- Alta Actores                     \n");
    printf("     |                                               |\n");
    printf("                  7- Mostrar Actores/Peliculas        \n");
    printf("     |                                               |\n");
    printf("                  8- Mostrar x Pais de Origen         \n");
    printf("     |                                               |\n");
    printf("                  9- Informes                         \n");
    printf("     |                                               |\n");
    printf("                  10- Salir                            \n");
    printf("     |                                               |\n");
    printf("     =================================================\n");
    printf("                                                      \n");
    printf("     Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}



int buscarLibre(ePeliculas vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int buscarPeliculas(ePeliculas vec[], int tam, int legajo)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == legajo && vec[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



void mostrarPelicula(ePeliculas pel, eCategorias cat[], int tamCat)
{
    char cadena[20];

    mostrarCategorias(cat,tamCat,pel.categoria,cadena);

    printf("     %d   %s   %s   %0d/%0d/%d\n", pel.id, pel.titulo, cadena, pel.fecha.dia, pel.fecha.mes, pel.fecha.anio);

}



void mostrarPeliculas(ePeliculas vec[], int tam, eCategorias cat[], int tamCat)
{
    int cont= 0;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].ocupado == OCUPADO)
        {

            mostrarPelicula(vec[i],cat,tamCat);
            cont++;
        }
    }

    if(cont == 0)
    {
        printf("     No hay empleados que mostrar\n\n");
    }

}



void altaPelicula(ePeliculas vec[], int tam, eCategorias cat[], int tamCat)
{
    int indice;
    int idCategoria;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Pelicula\n");
        indice = buscarLibre(vec, tam);


        if(indice == -1)
        {
            printf("No hay lugar\n");
            system("pause");
            break;
        }
        else
        {


            vec[indice].id = cargarId();


            printf("Ingrese nombre de la pelicula: ");
            fflush(stdin);
            gets(vec[indice].titulo);

            listarCategorias(cat,tamCat);

            printf("Ingrese ID Categoria: ");
            scanf("%d",&idCategoria);

            vec[indice].categoria = idCategoria;

            printf("Ingrese fecha de estreno\n");
            printf("dd/mm/aaaa: ");
            scanf("%d %d %d",&vec[indice].fecha.dia,&vec[indice].fecha.mes,&vec[indice].fecha.anio);

            vec[indice].ocupado = OCUPADO;

            printf("\nLa pelicula ha sido registrada con exito!!!\n\n");

            printf("\n\n");

            seguir = validarSeguir();

        }

    }
    while(seguir == 'S' || seguir == 's');

}



void bajaPeliculas(ePeliculas vec[], int tam, eCategorias cat[], int tamCat)
{

    int legajo;
    char seguir;
    int esta;

    system("cls");
    printf("Baja Pelicula\n");
    printf("\n\n");
    mostrarPeliculas(vec,tam,cat,tamCat);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    printf("\n\n");


    esta = buscarPeliculas(vec, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("Pelicula a eliminar\n");
        mostrarPelicula(vec[esta],cat,tamCat);

        seguir = validarSeguir();

        if(seguir == 's' || seguir == 'S')
        {
            vec[esta].ocupado = VACIO;
            printf("\Pelicula eliminada con exito\n");
        }
        else
        {
            printf("\nLa eliminacion ha sido cancelada\n");
        }

    }

}



void ModificacionPeliculas(ePeliculas vec[], int tam, eCategorias cat[], int tamCat)
{

    int legajo;
    float sueldo;
    char titulo[50];
    eFecha fech;
    int opcion;
    int esta;
    char seguir;

    printf("Modificacion Pelicula\n");
    printf("\n\n");
    mostrarPeliculas(vec,tam,cat,tamCat);

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);


    esta = buscarPeliculas(vec, tam, legajo);


    if( esta == -1)
    {

        printf("\nEl ID %d no esta registrado en el sistema\n", legajo);
    }
    else
    {
        printf("\n\n");
        printf("Pelicula a modificar\n");
        mostrarPelicula(vec[esta],cat,tamCat);

        printf("     Que desea modificar?\n");
        printf("     1. Titulo\n     2. Fecha\n");
        printf("     Ingrese opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            printf("Modificar Titulo\n");

            printf("Ingrese nuevo titulo: ");
            fflush(stdin);
            gets(titulo);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                strcpy(vec[esta].titulo,titulo);

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

            printf("Modificar Fecha\n");

            printf("Ingrese nueva fecha: ");
            fflush(stdin);
            scanf("%d %d %d",&fech.dia,&fech.mes,&fech.anio);

            seguir = validarSeguir();

            if(seguir == 's' || seguir == 'S')
            {

                vec[esta].fecha = fech;

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
            printf("Esta opcion no existe\n");
            break;

        }
    }

}

void ordenarXanio(ePeliculas vec[], int tam, eCategorias cat[], int tamCat)
{
    ePeliculas auxPeli;

    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(vec[i].fecha.anio > vec[j].fecha.anio)
            {
                auxPeli = vec[i];
                vec[i] = vec[j];
                vec[j] = auxPeli;
            }
        }
    }

    mostrarPeliculas(vec,tam,cat,tamCat);
}


/*
void menuInformes(eEmpleado x[],int tam, eSector sec[], int tamSec, eComida com[], int tamCom, eAlmuerzo alm[], int tamAlm)
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

void empleadoXanio(eEmpleado x[],int tam, int anio, eSector sec[], int tamSec)
{
    int cont=0;

    for(int i=0; i<tam; i++)
    {
        if(x[i].ocupado == OCUPADO && x[i].fecha.anio == anio)
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
        if(x[i].sector == idSector && x[i].ocupado == OCUPADO)
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
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                cont++;
            }
        }

        printf("Cant de Empleados: %d\n\n",cont);

    }

    if(cont == 0)
    {
        printf("No hay empleados que contar\n");
    }

}



void empXsector(eEmpleado x[], int tam, eSector sec[], int tamSec)
{

    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {

        printf("Sector: %s\n",sec[i].descripcion);

        for(int j=0; j<tam; j++)
        {

            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;
            }

        }
    }


    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n");
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
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
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

            if( (x[j].sueldo > mayor || flag ==0) && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO )
            {
                mayor = x[j].sueldo;
            }

        }


        for(int j=0; j<tam; j++)
        {
            if(x[j].sueldo == mayor && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id )
            {
                mostrarEmpleado(x[j],sec,tamSec);
            }
        }
    }


}



void sectorMujeres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {

        for(int j=0; j<tam; j++)
        {
            if(x[j].ocupado == OCUPADO && x[j].sector == sec[i].id && x[j].sexo == 'f')
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;

            }
        }
    }


    if(flag == 0)
    {
        printf("No hay ninguna mujer\n");
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
        if(x[i].sector == idSector && x[i].ocupado == OCUPADO)
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
    int flag = 0;

    for(int i=0; i<tamSec; i++)
    {
        for(int j=0; j<tam; j++)
        {
            if(x[j].fecha.anio <=2009 && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO)
            {
                printf("Sector: %s\n",sec[i].descripcion);
                mostrarEmpleado(x[j],sec,tamSec);
                flag = 1;
            }
        }
    }


    if(flag == 0)
    {
        printf("No hay ningun empleado con el anio <=2009");
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


        printf("%d",i);
        printf("flag: %d\n",flag);
        printf("mismo: %d\n",mismo);


        for(int j=0; j<tam; j++)
        {
            if( (x[j].sueldo == mismo || flag == 0) && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id)
            {
                mismo = x[j].sueldo;
                printf("acumulador: %f\n",mismo);
                flag = 1;


            }
        }


        if(flag == 0)
        {
            printf("Ningun empleado tiene el mismo salario\n");
            break;
        }


        else
        {
            for(int j=0; j<tam; j++)
            {
                if(x[j].sueldo == mismo && x[j].ocupado == OCUPADO)
                {
                    printf("%f",mismo);
                    mostrarEmpleado(x[j],sec,tamSec);


                }
            }
        }


        printf("i: ", i);
    }
}



void cantHombres(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    int cont = 0;

    for(int i=0; i<tamSec; i++)
    {


        for(int j=0; j<tam; j++)
        {
            if(x[j].sector == sec[i].id && x[j].ocupado == OCUPADO && x[j].sexo == 'm')
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
    int flag=0;

    for(int i=0; i<tamSec; i++)
    {
        menor = 0;

        for(int j=0; j<tam; j++)
        {

            if( (x[j].sueldo < menor || flag == 0) && x[j].sector == sec[i].id && x[j].ocupado == OCUPADO )
            {
                menor = x[j].sueldo;
                flag = 1;
            }

        }

        for(int j=0; j<tam; j++)
        {
            if(x[j].sueldo == menor && x[j].ocupado == OCUPADO && x[j].sector == sec[i].id )
            {
                mostrarEmpleado(x[j],sec,tamSec);
            }
        }

    }

}


void ordenarEmpXsectorYnombre(eEmpleado x[], int tam, eSector sec[], int tamSec)
{
    char descI[20];
    char descJ[20];
    eEmpleado aux;


    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            mostrarSectores(sec,tamSec,x[i].sector,descI);
            mostrarSectores(sec,tamSec,x[j].sector,descJ);


            if(strcmp(descI,descJ)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
            else if(strcmp(descI,descJ)==0 && strcmp(x[i].nombre,x[j].nombre)>0)
            {
                aux = x[i];
                x[i] = x[j];
                x[j] = aux;
            }
        }
    }


    mostrarEmpleados(x,tam,sec,tamSec);
}
*/
/*------------------------------------------------------------------------------------------------------------------

                                       HARCODEOS/OBTENER

--------------------------------------------------------------------------------------------------------------------*/

void harcodePeliculas(ePeliculas vec[], int tam)
{
    ePeliculas hardcode[]=
    {
        {1000, "El hombre que Araña",{12,3,2000},1,1},
        {1001, "Virgo a los 40",{2,7,2010},2,1},
        {1002, "Cementerio de Sosas",{14,5,2013},3,1},
        {1003, "El secreto de tu hoyo",{2,9,2010},4,1},
        {1004, "Buscandosela a nemo",{12,3,2012},5,1},
        {1005, "Capitana Feminazi",{28,7,2009},1,1},
        {1006, "La vida del Brayan",{11,1,2016},2,1},
        {1007, "El Ayuwoky",{19,10,2004},3,1},
        {1008, "50 sombras de Vicky",{23,6,2010},4,1},
        {1009, "Planeta de los Sosas",{2,7,2009},5,1},
        {1010, "La banana Mecanica",{2,9,1995},1,0},
        {1011, "Todoloroso",{12,3,1996},2,0},
        {1012, "La Ailen",{11,1,2017},3,0},
        {1013, "Diario de una Macrisis",{19,10,2003},4,0},
        {1014, "Tetanic",{23,6,2011},5,0}
    };


    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }
}

void harcodeCategorias(eCategorias vec[], int tam)
{
    eCategorias hardcode[]=
    {
        {1, "Ciencia Ficcion"},
        {2, "Comedia"},
        {3, "Terror"},
        {4, "Drama"},
        {5, "Suspenso"}
    };

    for(int i=0; i<tam; i++)
    {
        vec[i]=hardcode[i];
    }

}



void listarCategorias(eCategorias x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s\n",x[i].id,x[i].descripcion);
    }
}



void mostrarCategorias(eCategorias x[], int tam, int idCategoria, char cadena[])
{
    for(int i=0; i<tam; i++)
    {
        if(x[i].id == idCategoria)
        {
            //COPIAR LA DESCRIPCION DE LA CADENA
            //DESTINO/ORIGEN
            strcpy(cadena,x[i].descripcion);

        }
    }
}



/*void harcodeComidas(eComida x[], int tam)
{
    eComida hardcode[]=
    {
        {1, "Milanesa",80},
        {2, "Pescado",90},
        {3, "Tortilla",100},
        {4, "Salmon",150},
        {5, "Empanadas",105}

    };

    for(int i=0; i<tam; i++)
    {
        x[i]=hardcode[i];
    }
}

void listarComidas(eComida x[], int tam)
{
    printf(" ID   Descripcion\n");
    printf("\n\n");

    for(int i=0; i<tam; i++)
    {
        printf(" %d   %s %.2f\n",x[i].id,x[i].descripcion, x[i].precio);
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



void harcodeAlmuerzos(eAlmuerzo x[], int tam)
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

void inicializarActores(eActor x[], int tamAlm)
{

    for(int i=0; i < tamAlm; i++)
    {
        x[i].ocupado = VACIO;
    }
}



int buscarLibreActor(eActor x[], int tamAlm)
{

    int indice = -1;

    for(int i=0; i < tamAlm; i++)
    {
        if(x[i].ocupado == VACIO)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarActor(eActor alm[], int tamAlm, int legajo)
{
    int indice= -1;

    for(int i=0; i<tamAlm; i++)
    {
        if(alm[i].id == legajo && alm[i].ocupado == OCUPADO)
        {
            indice = i;
            break;
        }
    }

    return indice;

}



void altaActor(eActor x[], int tam, eCategorias cat[], int tamCat, ePeliculas pel[], int tamPel)
{
    int id;
    char nombre[20];
    char nacionalidad[20];
    int indice;
    char seguir;

    do
    {

        system("cls");
        printf("Alta Actores\n");

        indice = buscarLibreActor(x,tam);


        if(indice == -1)
        {
            printf("No hay mas espacio para cargar actores\n");
            printf("\n\n");
            system("pause");
            break;
        }
        else
        {
            x[indice].id = cargarIdActor();

            mostrarPeliculas(pel,tamPel,cat,tamCat);

            printf("Ingrese ID Pelicula: ");
            scanf("%d",&id);

            x[indice].idPelicula = id;

            printf("Ingrese nombre del Actor a interpretar la pelicula: ");
            fflush(stdin);
            gets(nombre);

            strcpy(x[indice].nombre,nombre);

            printf("Ingrese nacionalidad: ");
            fflush(stdin);
            gets(nacionalidad);

            strcpy(x[indice].pais,nacionalidad);

            x[indice].ocupado = OCUPADO;

            printf("El Actor se ha registrado con exito!!\n");

            seguir = validarSeguir();

        }
    }
    while(seguir == 'S' || seguir == 's');
}

void mostrarActor(eActor x, ePeliculas pel[], int tamPel, eCategorias cat[], int tamCat)
{
    char nombre[21];
    int loMuestro;

    for(int i=0; i<tamPel; i++)
    {
        if(pel[i].id == x.idPelicula)
        {
            strcpy(nombre,pel[i].titulo);
            loMuestro = pel[i].ocupado;
            break;
        }
    }

    if(loMuestro)
    {
        printf("%4d %4d %10s %10s %10s\n", x.id, x.idPelicula, nombre, x.nombre, x.pais);
    }

}

void mostrarActores(eActor x[], int tam, ePeliculas pel[], int tamPel, eCategorias cat[], int tamCat)
{
    int flag = 0;


    system("cls");
    printf("  ID Actor   ID Pelicula   Titulo  Actor   Nacionalidad\n\n");


    for(int i=0; i<tam; i++)
    {

            if(x[i].ocupado == OCUPADO)
            {
            mostrarActor(x[i],pel,tamPel,cat,tamCat);
            flag = 1;
            }
    }


    if(flag == 0)
    {
        printf("No hay actores cargados\n");
    }

}

void ordenarActoresXpais(eActor x[], int tam, ePeliculas pel[], int tamPel, eCategorias cat[], int tamCat)
{
    eActor aux;

    for(int i=0; i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
           if(strcmp(x[i].pais,x[j].pais)>0)
           {
               aux = x[i];
               x[i] = x[j];
               x[j] = aux;
           }
        }

        mostrarActores(x,tam,pel,tamPel,cat,tamCat);
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

int cargarIdActor()
{
    static int idActor = 1111;


    return idActor++;
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
