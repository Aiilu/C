#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "ctype.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {

            if( !parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "rb");

        if(pFile != NULL)
        {

            if( !parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                todoOk = 0;
            }

            fclose(pFile);
        }
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    Employee* nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {

        if(pArrayListEmployee != NULL)
        {

            system("cls");
            printf("Alta de Empleado\n\n");

            printf("Ingrese id: ");
            scanf("%d", &id);
            employee_setId(nuevoEmpleado, id);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre);
            employee_setNombre(nuevoEmpleado, nombre);

            printf("Ingrese Horas Trabajadas: ");
            scanf("%d", &horas);
            employee_setHorasTrabajadas(nuevoEmpleado, horas);

            printf("Ingrese sueldo: ");
            scanf("%d", &sueldo);
            employee_setSueldo(nuevoEmpleado, sueldo);

            if(!ll_add(pArrayListEmployee, nuevoEmpleado))
            {
                todoOk = 0;
            }
        }
    }
    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    int id;
    int i;
    int indice = -1;
    char opcion;

    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {

        controller_ListEmployee(pArrayListEmployee);
        printf("\n** Modificacion Empleado **\n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxEmp->id == id)
            {
                indice = i;
                break;
            }
        }

        if(indice == -1)
        {
            printf("\nNo hay resultados\n");
        }
        else
        {
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee, indice));


            printf("Campos a modificar:\n\n");
            printf("a- Nombre\n");
            printf("b- Horas Trabajadas\n");
            printf("c- Sueldo\n\n");
            printf("Ingrese opcion: ");
            fflush(stdin);
            scanf("%c", &opcion);

            switch(opcion)
            {
            case 'a':
                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(auxEmp->nombre);
                break;
            case 'b':
                printf("\nIngrese Horas trabajadas: ");
                scanf("%d", &auxEmp->horasTrabajadas);
                break;
            case 'c':
                printf("\nIngrese nuevo sueldo: ");
                scanf("%d", &auxEmp->sueldo);
                break;
            default:
                printf("Opcion invalida\n\n");
                break;
            }
            todoOk = 1;
        }
    }
        return todoOk;
}









/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int i;
    int indice = -1;
    char confirma;
    Employee* auxEmp;

    if(pArrayListEmployee != NULL)
    {

        controller_ListEmployee(pArrayListEmployee);
        printf("\n** Baja Empleado **\n\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);

        for(i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if( auxEmp->id == id)
            {
                indice = i;
                break;
            }
        }

        if(indice == -1)
        {
            printf("\nNo hay resultados\n");
        }
        else
        {
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee, indice));

            printf("\nConfirma borrado? ");
            fflush(stdin);
            scanf("%c", &confirma);

            if( tolower(confirma) == 's')
            {
                ll_remove(pArrayListEmployee, indice);

                printf("Empleado eliminado con exito!\n\n");
            }
            else
            {
                printf("\nOperacion Cancelada\n\n");
            }
        }



    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int i=0;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("   **Listado de Empleados**\n\n");

        if(ll_len(pArrayListEmployee) == 0)
        {
            printf("  No hay empleados para mostrar\n\n");
        }
        else
        {
            printf(" Id Nombre Horas Sueldo\n");

        }
        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            empleado = (Employee*) ll_get(pArrayListEmployee, i);
            mostrarEmpleado(empleado);
        }

        printf("\n");
        todoOk = 0;
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    char opcion;

    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("    **Ordenamiento Empleados**\n\n");

        printf("Ordenar por:\n\n");
        printf("a- Id\n");
        printf("b- Nombre\n");
        printf("c- Horas Trabajadas\n");
        printf("d- Sueldo\n\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {

        case 'a':
            ll_sort(pArrayListEmployee, employeeSortById, 0);
            break;
        case 'b':
            ll_sort(pArrayListEmployee, employeeSortByName, 0);
            break;
        case 'c':
            ll_sort(pArrayListEmployee, employeeSortByWorkHours, 0);
            break;
        case 'd':
            ll_sort(pArrayListEmployee, employeeSortBySalary, 0);
            break;
        default:
            printf("Opcion invalida\n\n");
            break;
        }
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int i;
    FILE* pFile;
    Employee* empleado;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "w");

        if(pFile != NULL)
        {
            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

            for( i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                empleado = (Employee*) ll_get(pArrayListEmployee, i);

                if(empleado != NULL)
                {
                    printEmpleadoTexto(pFile, empleado);
                }
            }

            fclose(pFile);
            todoOk = 0;
        }
    }
    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int i;
    FILE* pFile;
    Employee* empleado;


    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "wb");

        if(pFile != NULL)
        {
            for( i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                empleado = (Employee*) ll_get(pArrayListEmployee, i);

                if(empleado != NULL)
                {
                    fwrite(empleado, sizeof(Employee), 1, pFile);
                }
            }
            fclose(pFile);
            todoOk = 0;
        }
    }
    return todoOk;
}

