#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {

            if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
            {
                printf(" Carga en modo texto exitosa!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al cargar el archivo .csv\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pFile);
    }

    return retorno;
}

/*
int controller_loadFromTextDos(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {

            if(!parser_EmployeeFromTextDos(pFile, pArrayListEmployee))
            {
                printf(" Carga en modo texto exitosa!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al cargar el archivo .csv\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pFile);
    }

    return retorno;
}
*/
/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"rb");

        if(pFile !=NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                printf(" Carga en modo binario exitosa!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al cargar el archivo .bin\n");
            }
        }
        else
        {
            printf(" El archivo no se pudo abrir correctamente\n");
        }

        fclose(pFile);
    }

    return retorno;
}
*/
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darAlta(pArrayListEmployee))
        {
            printf("\n");
            printf(" Empleado dado de alta con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}


int controller_addEmployeeDos(LinkedList* pArrayListEmployee, LinkedList* alo)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darAltaDos(pArrayListEmployee,alo)==1)
        {
            printf("\n");
            printf(" Empleado dado de alta con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}
*/
/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darModificacion(pArrayListEmployee))
        {
            printf("\n");
            printf(" Menu ejecutado con exito!!!\n");
            printf(" Espero que hayas modificado algun empleado\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}
*/
/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darBaja(pArrayListEmployee))
        {
            printf("\n");
            printf(" Menu ejecutado con exito!!!\n");
            printf(" Espero que hayas dado de baja algun empleado\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return retorno;
}


int controller_removeEmployeeDos(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(darBajaDos(pArrayListEmployee))
        {
            printf("\n");
            printf(" Menu ejecutado con exito!!!\n");
            printf(" Espero que hayas dado de baja algun empleado\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return retorno;
}
*/
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados(pArrayListEmployee))
        {
            printf(" Dominios listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}

int controller_ListEmployeeDos(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados2(pArrayListEmployee))
        {
            printf(" Dominios listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}

/*
int controller_ListEmployeeCuatro(LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados4(pArrayListEmployee,pp))
        {
            printf(" Empleados listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}


int controller_ListEmployee2(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados2(pArrayListEmployee)==1)
        {
            printf(" Empleados listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}


int controller_ListEmployee5(LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(listarEmpleados5(pArrayListEmployee,pp)==1)
        {
            printf(" Empleados listados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }
    return retorno;
}
*/
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    if(pArrayListEmployee !=NULL)
    {
        if(ordenarEmpleados(pArrayListEmployee))
        {
            printf("\n");
            printf(" Empleados ordenados con exito!!!\n");
            retorno = 1;
        }
        else
        {
            printf(" Hubo un error\n");
        }
    }

    return retorno;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"w");

        if(pFile !=NULL)
        {
            if(parser_EmployeeSaveText(pFile,pArrayListEmployee))
            {
                printf(" Empleados cargados en modo texto con exito!!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al guardar el archivo .csv\n");
            }
        }

        fclose(pFile);
    }

    return retorno;
}


int controller_saveAsTextDos(char* path, LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = -1;
    FILE* pFile;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"w");

        if(pFile !=NULL)
        {
            if(parser_EmployeeSaveTextDos(pFile,pArrayListEmployee,pp))
            {
                printf(" Empleados cargados en modo texto con exito!!!\n");
                retorno = 0;
            }
            else
            {
                printf(" Hubo un error al guardar el archivo .csv\n");
            }
        }

        fclose(pFile);
    }

    return retorno;
}
*/
/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    Employee* nuevoEmpleado;

    if(path !=NULL && pArrayListEmployee !=NULL)
    {
        pFile = fopen(path,"wb");

        if(pFile !=NULL)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                nuevoEmpleado = (Employee*)ll_get(pArrayListEmployee,i);

                if(nuevoEmpleado !=NULL)
                {
                    fwrite(nuevoEmpleado,sizeof(Employee),1,pFile);
                }
            }

            printf(" Empleados cargados en modo binario con exito!!!\n");
            retorno = 0;
        }
        else
        {
            printf(" Hubo un error al guardar el archivo .bin\n");
        }

        fclose(pFile);
    }

    return retorno;
}
*/

/*int controller_map(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {

        if(listaNueva !=NULL)
        {
           ll_map2(pArrayListEmployee,setearDatos);
           retorno = 0;
        }
    }

    return retorno;
}
*/
