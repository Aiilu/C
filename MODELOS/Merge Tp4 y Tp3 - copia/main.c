#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    char valOpcion[3];
    char seguir = 's';
    int flagText = 0;
    int flagBin = 0;
    int flagUno = 0;
    int flagDos = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosDos;
    LinkedList* listaEmpleadosTres;
    LinkedList* listaEmpleadosCuatro;
    LinkedList* listaEmpleadosCinco = NULL;

    int from;
    int to;
    void* pAux;
    int indice;
    int indice2;

    do
    {
        system ("COLOR F4");
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                         Trabajo Practico Nro. 3                            #\n");
        printf(" #                                                                            #\n");
        printf(" #                         >>>> MENU DE OPCIONES <<<<                         #\n");
        printf(" ==============================================================================\n");
        printf("   1- Cargar datos de los empleados desde el archivo data.csv (modo texto)     \n");
        printf("   2- Cargar datos de los empleados desde el archivo data.bin (modo binario)   \n");
        printf("   3- Alta de empleado                                                         \n");
        printf("   4- Modificar datos de empleado                                              \n");
        printf("   5- Baja de empleado                                                         \n");
        printf("   6- Listar empleados                                                         \n");
        printf("   7- Ordenar Empleados                                                        \n");
        printf("   8- Guardar datos de los empleados en el archivo data.csv (modo texto)       \n");
        printf("   9- Guardar datos de los empleados en el archivo data.bin (modo binario)     \n");
        printf("   10- Clonar LinkedList                                                       \n");
        printf("   11- Verificar si los datos de la lista2 estan en la lista1                  \n");
        printf("   12- Borrar LinkedList clonada                                               \n");
        printf("   13- Listar empleados de la lista2                                           \n");
        printf("   14- Ordenar empleados lista2                                                \n");
        printf("   15- Alta lista 2 con ll_push                                                \n");
        printf("   16- Crear lista3 con ll_subList                                             \n");
        printf("   17- Verificar si un empleado existe                                         \n");
        printf("   18- Baja de empleado con ll_pop                                             \n");
        printf("   19- Listar empleados lista3                                                 \n");
        printf("   20- ll_map                                                                  \n");
        printf("   21- ll_filter                                                               \n");
        printf("   22- Salir                                                                   \n");
        printf(" ==============================================================================\n");
        printf("                                                                               \n");
        printf(" Ingrese una opcion del menu: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            printf("\n");
            if(flagBin == 0 && flagUno == 0)
            {
                controller_loadFromText("empleados.csv",listaEmpleados);
                flagText =  1;
                flagUno = 1;
            }
            else
            {
                printf(" Solo se puede cargar un archivo\n");
            }
            break;
        case 2:
            printf("\n");
            if(flagText == 0 && flagUno == 0)
            {
                controller_loadFromBinary("empleados.bin",listaEmpleados);
                flagBin = 1;
                flagUno = 1;
            }
            else
            {
                printf(" Solo se puede cargar un archivo\n");
            }
            break;
        case 3:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 4:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_editEmployee(listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 5:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_removeEmployee(listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 6:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 7:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_sortEmployee(listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 8:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_saveAsText("empleados.csv",listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado que guardar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 9:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    controller_saveAsBinary("empleados.bin",listaEmpleados);
                }
                else
                {
                    printf(" No hay ningun empleado que guardar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 10:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    listaEmpleadosDos = ll_clone(listaEmpleados);

                    if(listaEmpleadosDos !=NULL)
                    {
                        printf(" La lista ha sido clonada correctamente\n");
                    }
                    else
                    {
                        printf(" Hubo un error al clonar la lista\n");
                    }
                }
                else
                {
                    printf(" No hay nada que clonar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 11:
            if(flagDos == 0 && (flagText == 1 || flagBin == 1))
            {
                if(ll_isEmpty(listaEmpleados)==0)
                {
                    if(ll_containsAll(listaEmpleados,listaEmpleadosDos)==1)
                    {
                        printf(" Todos los elementos de lista2 estan en lista1\n");
                    }
                    else
                    {
                        printf(" Los elementos de lista2 no estan en lista1\n");
                    }
                }
                else
                {
                    printf(" No hay nada que verificar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 12:
            printf("\n");
            if(flagDos == 0 && (flagText == 1 || flagBin == 1))
            {
                if(ll_isEmpty(listaEmpleadosDos)==0)
                {
                    if(ll_deleteLinkedList(listaEmpleadosDos)==0)
                    {
                        printf(" Borrado exitoso!!\n");
                        flagDos = 1;
                    }
                    else
                    {
                        printf("Hubo un error al eliminar la lista2\n");
                    }
                }
                else
                {
                    printf(" No hay nada que verificar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
            break;
        case 13:
            printf("\n");
            if(flagDos == 0 && (flagText == 1 || flagBin == 1))
            {
                if(ll_isEmpty(listaEmpleadosDos)==0)
                {
                    controller_ListEmployee(listaEmpleadosDos);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 14:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleadosDos)==0)
                {
                    controller_sortEmployee(listaEmpleadosDos);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 15:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_addEmployeeDos(listaEmpleadosDos);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 16:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                printf(" Ingrese desde donde quiere la lista: ");
                scanf("%d",&from);

                printf(" Ingrese hasta donde quiere la lista: ");
                scanf("%d",&to);

                listaEmpleadosTres = ll_subList(listaEmpleadosDos,from,to);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 17:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                printf(" Ingrese indice: ");
                scanf("%d",&indice);

                pAux = ll_get(listaEmpleadosTres,indice);

                mostrarEmpleado(pAux);

                indice2 = ll_indexOf(listaEmpleadosTres,pAux);

                if(indice == -1)
                {
                    printf(" No existe\n");
                }
                else
                {
                    printf(" Este empleado se encuentra en la lista.\n");
                    printf(" Su indice es: %d\n",indice2);
                }

            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 18:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                if(ll_isEmpty(listaEmpleadosTres)==0)
                {
                    controller_removeEmployeeDos(listaEmpleadosTres);
                }
                else
                {
                    printf(" No hay ningun empleado que mostrar\n");
                }
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 19:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_ListEmployee(listaEmpleadosTres);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        case 20:

            /*listaEmpleadosCuatro = ll_clone(listaEmpleadosDos);

            if(listaEmpleadosCuatro !=NULL)
            {

                ll_map2(listaEmpleadosCuatro,modificarSueldo2);

                controller_ListEmployee(listaEmpleadosCuatro);
                printf("Aumento de sueldo exitoso\n");
            }
            else
            {
                printf("Hubo un error al clonar la lista\n");
            }*/
                listaEmpleadosCuatro = ll_map1(listaEmpleados,modificarSueldo1);

                if(listaEmpleadosCuatro !=NULL)
                {
                    controller_ListEmployee(listaEmpleadosCuatro);
                    printf("Todo ok\n");
                }
                else
                {
                    printf("Hubo un error al modificar los valores\n");
                }

            break;
        case 21:

            listaEmpleadosCinco = ll_filter(listaEmpleadosDos,filtrarSueldo);

            if(listaEmpleadosCinco !=NULL)
            {
                controller_ListEmployee(listaEmpleadosCinco);
                printf("Todo ok\n");
            }
            else
            {
                printf("Hubo un error al filtrar\n");
            }
            break;
        case 22:
            system("cls");
            seguir = 'n';
            printf(" ==============================================================================\n");
            printf(" #                              Saliendo...                                   #\n");
            printf(" ==============================================================================\n");
            printf(" |                                                                            |\n");
            printf(" |                             Hasta luego!!!                                 |\n");
            printf(" |                                                                            |\n");
            printf(" ==============================================================================\n");
            break;
        case 23:
            printf("\n");
            if(flagText == 1 || flagBin == 1)
            {
                controller_ListEmployee(listaEmpleadosCuatro);
            }
            else
            {
                printf(" Primero debe cargar el archivo\n");
            }
            break;
        default:
            printf("\n\n");
            printf(" ERROR. Esta opcion no es correcta\n");
        }

        fflush(stdin);
        printf(" Presione ENTER para continuar");
        getchar();

    }
    while(seguir == 's');

    return 0;
}
