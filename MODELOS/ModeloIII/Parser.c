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
    char buffer[6][128];
    eEnvio* nuevoEmpleado = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

        while(!feof(pFile))
        {

            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

            if(cant <6)
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

            nuevoEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}

/*
int parser_EmployeeFromTextDos(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int todoOk = -1;
    int cant;
    char buffer[5][128];
    eVentas* nuevoEmpleado = NULL;

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
            nuevoEmpleado = employee_newParametrosDos(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

            if(nuevoEmpleado != NULL)
            {
                ll_add(pArrayListEmployee, nuevoEmpleado);
            }
        }

        todoOk = 0;
    }

    return todoOk;
}

*/
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
    eEnvio* nuevoEmpleado;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
            fprintf(pFile,"idEnvio,nombreProd,idCamion,destino,kmRecorridos,tipoEntrega,costoEnvio\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (eEnvio*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(pFile,"%d,%s,%d,%s,%d,%d,%d\n",nuevoEmpleado->idEnvio,nuevoEmpleado->producto,nuevoEmpleado->idCamion,nuevoEmpleado->destino,nuevoEmpleado->kmRecorridos,nuevoEmpleado->tipoEntrega,nuevoEmpleado->costo);
                }
            }

            retorno = 1;
    }

    return retorno;
}

/*
int parser_EmployeeSaveTextDos(FILE* pFile, LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = 0;
    eVentas* nuevoEmpleado;
    eCliente* nuevoCliente;

    if(pFile !=NULL && pArrayListEmployee !=NULL)
    {
            fprintf(pFile,"id_venta,nombre,apellido,codProducto,montoTotal\n");

            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (eVentas*)ll_get(pArrayListEmployee,i);
                nuevoCliente =(eCliente*)ll_get(pp,i);

                if(nuevoEmpleado !=NULL)
                {
                    fprintf(pFile,"%d,%s,%s,%s,%d,%f\n",nuevoEmpleado->idVenta,nuevoCliente->nombre,nuevoCliente->apellido,nuevoCliente->dni, nuevoEmpleado->codProd, nuevoEmpleado->total);
                }
            }

            retorno = 1;
    }

    return retorno;
}
*/
