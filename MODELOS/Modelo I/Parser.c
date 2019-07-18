#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Empleado.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
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
    char buffer[5][128];
    eVendedor* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

            if(cant <5)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Archivo corrupto\n");
                    break;
                }
            }

            //nuevoEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
            nuevoEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* nuevoEmpleado;
    int cant;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
        while(!feof(pFile))
        {
            nuevoEmpleado = employee_new();

            if(nuevoEmpleado !=NULL)
            {
                cant = fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

                if( cant < 1)
                {
                    if(feof(pFile))
                    {

                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo");
                    }
                }
                ll_add(pArrayListEmployee,nuevoEmpleado);
            }
        }

        retorno = 0;
    }

    return retorno;
}
*/


int parser_EmployeeSaveText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eVendedor* nuevoEmpleado;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
            fprintf(pFile,"Id,Nombre,Nivel,CantProd,MontoVend,Comision\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (eVendedor*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%d,%.2f,%.2f\n",nuevoEmpleado->id,nuevoEmpleado->nombre,nuevoEmpleado->nivel,nuevoEmpleado->cantProdVend,nuevoEmpleado->montoVendido,nuevoEmpleado->comision);
                }
            }

            retorno = 1;
    }

    return retorno;
}

