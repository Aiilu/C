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

    LinkedList* listaEnvios = ll_newLinkedList();
    LinkedList* nuevaLista;
    LinkedList* listaZonas;

    char ingresar[128];

    do
    {

        system("cls");
        printf("\n");
        printf(" 1- Cargar archivo envios\n");
        printf(" 2- Listar envios\n");
        printf(" 3- Calcular costo de envio\n");
        printf(" 4- Filtrar x Zonas e imprimir\n");
        printf(" 5- Listar zonas disponibles\n");
        printf(" 6- Salir\n");
        printf(" Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            controller_loadFromText("DATA.csv",listaEnvios);
            system("pause");
            break;
        case 2:
            controller_ListEmployee(listaEnvios);
            system("pause");
            break;
        case 3:
            nuevaLista = ll_map1(listaEnvios,calcularCosto);

            if(nuevaLista !=NULL)
            {
                controller_ListEmployee2(nuevaLista);
            }
            else
            {
                printf(" Error\n");
            }
            break;
        case 4:
            system("cls");
            printf(" Ingrese la zona por la cual quiere filtrar\n");
            printf(" Estas son con las cuales trabajamos\n");
            printf(" Lanus\n");
            printf(" Avellaneda\n");
            printf(" CABA\n");
            printf(" Bandfield\n");
            printf(" Quilmes\n");
            printf(" Ingrese una opcion: ");
            fflush(stdin);
            gets(ingresar);

            if(stricmp(ingresar,"lanus")==0)
            {
                listaZonas = ll_filter(nuevaLista,filtrarLanus);

                if(listaZonas !=NULL)
                {
                    printf(" Filtrado con exito, ahora se imprimira el archivo...\n");
                    controller_saveAsText("lanus.csv",listaZonas);
                }
                else
                {
                    printf(" Error al filtrar\n");
                }
            }
            else if(stricmp(ingresar,"avellaneda")==0)
            {
                listaZonas = ll_filter(nuevaLista,filtrarAvellaneda);

                if(listaZonas !=NULL)
                {
                    printf(" Filtrado con exito, ahora se imprimira el archivo...\n");
                    controller_saveAsText("avellaneda.csv",listaZonas);
                }
                else
                {
                    printf(" Error al filtrar\n");
                }

            }
            else if(stricmp(ingresar,"caba")==0)
            {
                listaZonas = ll_filter(nuevaLista,filtrarCaba);

                if(listaZonas !=NULL)
                {
                    printf(" Filtrado con exito, ahora se imprimira el archivo...\n");
                    controller_saveAsText("caba.csv",listaZonas);
                }
                else
                {
                    printf(" Error al filtrar\n");
                }

            }
            else if(stricmp(ingresar,"bandfield")==0)
            {
                listaZonas = ll_filter(nuevaLista,filtrarBandfield);

                if(listaZonas !=NULL)
                {
                    printf(" Filtrado con exito, ahora se imprimira el archivo...\n");
                    controller_saveAsText("bandfield.csv",listaZonas);
                }
                else
                {
                    printf(" Error al filtrar\n");
                }

            }
            else if(stricmp(ingresar,"quilmes")==0)
            {
                listaZonas = ll_filter(nuevaLista,filtrarQuilmes);

                if(listaZonas !=NULL)
                {
                    printf(" Filtrado con exito, ahora se imprimira el archivo...\n");
                    controller_saveAsText("quilmes.csv",listaZonas);
                }
                else
                {
                    printf(" Error al filtrar\n");
                }

            }
            else
            {
                printf(" Esta zona no se encuentra en nuestros registros\n");
            }
            system("pause");
            break;
        case 5:
            printf("A continuacion se imprimiran las zonas disponibles: \n");
            controller_ListEmployeeTres(listaEnvios);
            break;
        case 6:
            printf(" Bay\n");
            seguir = 'n';
            break;
        default:
            printf(" Esta opcion no existe\n");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
