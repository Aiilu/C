#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "Parser.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Validaciones.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados);

int main()
{

    int opcion;
    int opcion2;
    char seguir = 's';
    LinkedList* listaVendedores = ll_newLinkedList();
    LinkedList* nuevaLista;
    LinkedList* nuevaLista2;

    do
    {
        system("cls");
        printf("\n");
        printf(" 1- Cargar archivo modo texto\n");
        printf(" 2- Listar\n");
        printf(" 3- Calcular comision\n");
        printf(" 4- Elegir nivel\n");
        printf(" 5- Listar nivel elegido\n");
        printf(" 6- Guardar archivo modo texto\n");
        printf(" 7. Salir\n");
        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("DATA.csv",listaVendedores);
            system("pause");
            break;
        case 2:
            controller_ListEmployee(listaVendedores);
            break;
        case 3:
            nuevaLista = ll_map1(listaVendedores,calcularComision2);
            system("pause");
            break;
        case 4:
            system("cls");
            printf("\n");
            printf(" 1- Nivel 0\n");
            printf(" 2- Nivel 1\n");
            printf(" 3. Nivel 2\n");
            printf(" Ingrese una opcion: ");
            scanf("%d",&opcion2);

            switch(opcion2)
            {
            case 1:
                nuevaLista2 = ll_filter(nuevaLista,filtrarNivelCero);

                if(nuevaLista2 !=NULL)
                {
                    printf(" El nivel 0 se ha filtrado con exito\n");
                }
                else
                {
                    printf(" Hubo un problema al filtrar\n");
                }
                break;
            case 2:
                nuevaLista2 = ll_filter(nuevaLista,filtrarNivelUno);

                if(nuevaLista2 !=NULL)
                {
                    printf(" El nivel 1 se ha filtrado con exito\n");
                }
                else
                {
                    printf(" Hubo un problema al filtrar\n");
                }
                break;
            case 3:
                nuevaLista2 = ll_filter(nuevaLista,filtrarNivelDos);

                if(nuevaLista2 !=NULL)
                {
                    printf(" El nivel 2 se ha filtrado con exito\n");
                }
                else
                {
                    printf(" Hubo un problema al filtrar\n");
                }
                break;
            default:
                printf("Esta opcion no existe\n");
                break;
            }
            system("pause");
            break;
        case 5:
            controller_ListEmployee2(nuevaLista2);
            break;
        case 6:
            if(controller_saveAsText("pepin.csv",nuevaLista2)==-1)
            {
                printf("Hubo un error al guardar el archivo\n");
            }
            else
            {
                printf("Se guardo con exito!!\n");
            }
            system("pause");
            break;
        case 7:
             seguir = 'n';
            printf(" Bay\n");
            break;
        default:
            printf("Ingrese una opcion valida \n");
            system("pause");
        }
    }
    while(seguir == 's');

    return 0;
}
