#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Controller.h"
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"

int main()
{
    char seguir = 's';
    int opcion;
    char valArchivo[10];
    char filtro[6];
    char valOpcion[3];

    LinkedList* listaDominio = ll_newLinkedList();
    LinkedList* listaNueva;
    LinkedList* filtrar;
    LinkedList* filtrar2;

    do
    {
        system("cls");
        printf("\n");
        printf(" 1- Cargar archivo DATA\n");
        printf(" 2- Ordenar x Dominio\n");
        printf(" 3- Setear el campo tipo\n");
        printf(" 4- Filtrar x Tipo\n");
        printf(" 5- Salir\n");
        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf(" Ingrese el nombre del archivo (datos): ");
            fflush(stdin);
            gets(filtro);

            if(validarStringTam(filtro,5)==1)
            {
                if(strcmp(filtro,"datos")==0)
                {
                    strcpy(valArchivo,filtro);
                    strcat(valArchivo,".csv");
                    controller_loadFromText(valArchivo,listaDominio);

                }
                else
                {
                    printf(" Este archivo no existe\n");
                }
            }
            else
            {
                printf(" Error\n");
            }
            system("pause");
            break;
        case 2:
            if(ll_isEmpty(listaDominio)==0)
            {
                if(ordenarDominio(listaDominio)==1)
                {
                    controller_ListEmployee(listaDominio);
                }
            }
            else
            {
                printf(" No hay datos. Cargue el archivo\n");
            }
            system("pause");
            break;
        case 3:
            if(ll_isEmpty(listaDominio)==0)
            {
                listaNueva = ll_map1(listaDominio,setearDatos);

                if(listaNueva !=NULL)
                {
                    controller_ListEmployeeDos(listaNueva);
                }
                else
                {
                    printf(" Error\n");
                }
            }
            else
            {
                printf(" No hay datos. Cargue el archivo\n");
            }
            break;
        case 4:
            break;
        case 5:
            printf(" Bay\n");
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');

    return 0;
}
