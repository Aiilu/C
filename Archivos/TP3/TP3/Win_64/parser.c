#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    char buffer[4][128];
    Employee* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant != 4)
            {
                break;
            }

            nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    Employee* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            nuevoEmpleado = employee_new();

            if(nuevoEmpleado != NULL)
            {
                cant = fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

                if(cant < 1)
                {
                    break;
                }
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}
