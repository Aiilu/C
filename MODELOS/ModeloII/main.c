#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Validaciones.h"

int main()
{
    int opcion;
    char seguir = 's';
    LinkedList* listaClientes = ll_newLinkedList();
    LinkedList* listaVentas = ll_newLinkedList();
    LinkedList* listaNueva;

    do
    {
        system("cls");
        printf(" 1- Cargar clientes\n");
        printf(" 2- Alta\n");
        printf(" 3- Modificar\n");
        printf(" 4- Baja\n");
        printf(" 5- Listar\n");
        printf(" 6- Cargar ventas\n");
        printf(" 7- Alta venta\n");
        printf(" 8- Baja Venta\n");
        printf(" 9- Listar Ventas\n");
        printf(" 10- Ventas x Prod\n");
        printf(" 11- Generar informe .txt\n");
        printf(" 12- Cant de ventas x cliente\n");
        printf(" 13- Salir\n");
        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("clientes.csv",listaClientes);
            system("pause");
            break;
        case 2:
            if(controller_addEmployee(listaClientes)==1)
            {
                controller_saveAsText("clientes.csv",listaClientes);
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 3:
            if(controller_editEmployee(listaClientes)==1)
            {
                controller_saveAsText("clientes.csv",listaClientes);
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 4:
            if(controller_removeEmployee(listaClientes)==1)
            {
                controller_saveAsText("clientes.csv",listaClientes);
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 5:
            if(controller_sortEmployee(listaClientes)==1)
            {
                controller_ListEmployee(listaClientes);
            }
            else
            {
               printf("Error\n");
            }
            break;
        case 6:
            controller_loadFromTextDos("ventas.csv",listaVentas);
            system("pause");
            break;
        case 7:
            if(controller_addEmployeeDos(listaVentas,listaClientes)==1)
            {
               controller_saveAsTextTres("ventas.csv",listaVentas);
               printf("putp");
            }
            else
            {
                printf("Error\n");
            }
            system("pause");
            break;
        case 8:
            if(controller_removeEmployeeDos(listaVentas)==1)
            {
                controller_saveAsTextTres("ventas.csv",listaVentas);
            }
            else
            {
                printf("Error\n");
            }
            system("pause");
            break;
        case 9:
            listaNueva = ll_map1(listaVentas,calcularMonto);

            if(listaNueva !=NULL)
            {
                controller_ListEmployeeCuatro(listaNueva,listaClientes);
            }
            else
            {
                printf("Error\n");
            }
            break;
        case 10:
            //buscarProducto(listaVentas);
            system("pause");
            break;
        case 11:
            controller_saveAsTextDos("informe.txt",listaNueva,listaClientes);
            system("pause");
            break;
        case 12:
            if(controller_ListEmployee5(listaNueva,listaClientes) ==1)
            {
                printf("Todo ok\n");
            }
            else
            {
                printf("kaka\n");
            }
            break;
        case 13:
            seguir = 'n';
            break;
        default:
            printf("Esta opcion no existe\n");
        }
    }while(seguir == 's');

    return 0;
}
