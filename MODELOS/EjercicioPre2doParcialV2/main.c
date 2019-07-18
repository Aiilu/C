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
    /* // Definir lista de empleados
     LinkedList* listaEmpleados;

     // Crear lista empledos
     //...

     // Leer empleados de archivo data.csv
     if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
     {
         // Calcular sueldos
         printf("Calculando sueldos de empleados\n");
    //        al_map(listaEmpleados,em_calcularSueldo);

         // Generar archivo de salida
         if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
         {
             printf("Archivo generado correctamente\n");
         }
         else
         {
             printf("Error generando archivo\n");
         }

     }
     else
     {
         printf("Error leyando empleados\n");
     }*/

    int opcion;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* nueva2;

    do
    {
        system("cls");
        printf("\n");
        printf(" 1- Cargar archivo modo texto\n");
        printf(" 2- Listar\n");
        printf(" 3- Aumentar sueldo x horas\n");
        printf(" 4- Guardar archivo con agregado modo texto\n");
        printf(" 5- Salir\n");
        printf("\n");
        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            system("pause");
            break;
        case 2:
            controller_ListEmployee(listaEmpleados);
            break;
        case 3:
               /* nueva2 = ll_map(listaEmpleados,modificarSueldo);

                if(nueva2 !=NULL)
                {
                    controller_ListEmployee(nueva2);

                    printf("Todo ok\n");
                }
                else
                {
                    printf("Todo mal\n");
                }*/

            nueva2 = ll_clone(listaEmpleados);

            if(nueva2 !=NULL)
            {
                ll_map2(listaEmpleados,calcularSueldo);
                printf("Calculando\n");
                printf("Todo ok\n");
            }
            else
            {
                printf("Todo mal\n");
            }
            system("pause");
            break;
        case 4:
            if(controller_saveAsText("salida.csv",listaEmpleados)==-1)
            {
                printf("Hubo un error al guardar el archivo\n");
            }
            else
            {
                printf("Se guardo con exito!!\n");
            }
            system("pause");
            break;
        case 5:
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

int generarArchivoSueldos(char* fileName,LinkedList* listaEmpleados)
{
    return 1;
}
