#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "Employee.h"
#include "LinkedList.h"
#include "validaciones.h"

/** \brief Set del ID del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        retorno = 1;
    }

    return retorno;

}


/** \brief Obtiene el ID del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 1;
    }
    return retorno;
}


/** \brief Set del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = 0;

    if(this != NULL && nombre != NULL && validarStringTam(nombre,128))
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Obtiene el nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

    int retorno = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Set de horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {

        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;

}

/** \brief Set de el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;

    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;

}

/** \brief Obtiene el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;

    if( this != NULL && sueldo != NULL )
    {

        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

int employee_setNombre2(Employee* this,char* nombre)
{

    int retorno = 0;

    if(this != NULL && nombre != NULL && validarStringTam2(nombre,128))
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;

}

/** \brief Lllama a los set del empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))|| !employee_setNombre(this, nombreStr) || !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||   !employee_setSueldo(this, atoi(sueldoStr)))

            {
                employee_delete(this);
                this = NULL;
            }
        }
    }

    return this;
}

Employee* employee_newParametrosDos(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))|| !employee_setNombre2(this, nombreStr) || !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||   !employee_setSueldo(this, atoi(sueldoStr)))

            {
                employee_delete(this);
                this = NULL;
            }
        }
    }

    return this;
}

/** \brief Libera memoria
 *
 * \param emp Employee*
 * \return void
 *
 */
void employee_delete(Employee* emp)
{
    if(emp !=NULL)
    {
        free(emp);
    }
}

/** \brief Obtiene a los empleados y lo muestra
 *
 * \param pEmp Employee*
 * \return void
 *
 */
void mostrarEmpleado(Employee* pEmp)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(pEmp !=NULL)
    {
        if(employee_getId(pEmp,&id) && employee_getNombre(pEmp,nombre) && employee_getHorasTrabajadas(pEmp,&horas) && employee_getSueldo(pEmp,&sueldo))
        {
            printf("%5d %8s %6d %8d\n",id,nombre,horas,sueldo);
        }
    }
}

/** \brief Ordena a los empleados por ID en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */
int ordenarXid(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->id > pDos->id)
        {
            retorno = 1;
        }
        else if(pUno->id < pDos->id)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;

}

/** \brief Ordena a los empleados por nombre en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */
int ordenarXnombre(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(stricmp(pUno->nombre,pDos->nombre)>0)
        {
            retorno = 1;
        }
        else if(stricmp(pUno->nombre,pDos->nombre)<0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Ordena a los empleados por horas en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */
int ordenarXhoras(void* numA, void* numB)
{
    int retorno = 0;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->horasTrabajadas > pDos->horasTrabajadas)
        {
            retorno = 1;
        }
        else if(pUno->horasTrabajadas < pDos->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Ordena a los empleados por sueldo en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */
int ordenarXsueldo(void* numA, void* numB)
{
    int retorno = -1;
    Employee* pUno;
    Employee* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (Employee*)numA;
        pDos = (Employee*)numB;

        if(pUno->sueldo > pDos->sueldo)
        {
            retorno = 1;
        }
        else if(pUno->sueldo < pDos->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Ingresa los datos del empleado a dar de alta
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int darAlta(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* nuevoEmpleado;
    char nombre[128];
    char valHoras[10];
    char valSueldo[10];
    int horas;
    int sueldo;

    nuevoEmpleado = employee_new();

    if(pArrayListEmployee !=NULL && nuevoEmpleado !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                          >>>> Alta Empleado <<<<                           #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf(" Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);

        employee_setNombre(nuevoEmpleado,nombre);

        printf("\n");

        printf(" Ingrese Horas: ");
        fflush(stdin);
        gets(valHoras);

        horas = validarEntero(valHoras);

        employee_setHorasTrabajadas(nuevoEmpleado,horas);

        printf("\n");

        printf(" Ingrese sueldo: ");
        fflush(stdin);
        gets(valSueldo);

        sueldo = validarEntero(valSueldo);

        employee_setSueldo(nuevoEmpleado,sueldo);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = generadorId(pArrayListEmployee);
            ll_add(pArrayListEmployee,nuevoEmpleado);

            retorno = 1;
        }
    }

    return retorno;
}

/** \brief Ordena a los empleados segun la opcion seleccionada
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int ordenarEmpleados(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int opcion;
    char valOpcion[2];

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                         >>>> Ordenar empleados <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf("\n");
        printf(" AVISO: Debido a la enorme cantidad de empleados,\n");
        printf(" va a demorar un poco el ordenarlos.\n");
        printf(" Por favor, espere. Gracias!!!\n");

        printf("\n");

        printf(" Que desea ordenar?\n");
        printf(" 1. ID\n 2. Nombre\n 3. Horas\n 4. Sueldo\n");
        printf(" Ingrese opcion: ");
        fflush(stdin);
        gets(valOpcion);

        opcion = validarEntero(valOpcion);

        switch(opcion)
        {
        case 1:
            if(ll_sort(pArrayListEmployee, ordenarXid, 1)==-1)
            {
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
            break;
        case 2:
            if(ll_sort(pArrayListEmployee, ordenarXnombre, 1)==-1)
            {
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
            break;
        case 3:
            if(ll_sort(pArrayListEmployee, ordenarXhoras, 1)==-1)
            {
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
            break;
        case 4:
            if(ll_sort(pArrayListEmployee, ordenarXsueldo, 1)==-1)
            {
                retorno = 0;
            }
            else
            {
                retorno = 1;
            }
            break;
        default:
            printf("\n");
            retorno = 0;
            printf(" Esta opcion no existe\n");
            break;
        }
    }

    return retorno;
}

/** \brief Muestra los datos de todos los empleados de a 200
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int listarEmpleados(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i=0;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Empleados    *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los empleados\n");
        printf(" en forma encolumnada de a 200.\n");

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   Nombre   Horas   Sueldo\n");
                printf("   --   ------   -----   ------\n");
                empleado = (Employee*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }
            else
            {
                empleado = (Employee*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }

        }
    }

    system("pause");
    return retorno;
}

/** \brief Da de baja a un empleado segun su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int darBaja(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    char valId[5];
    int indice;
    char seguir;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                             >>>> Baja Empleado <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese ID del empleado: ");
        fflush(stdin);
        gets(valId);

        id = validarEntero(valId);

        printf("\n");

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
        }
        else
        {
            system("cls");
            printf(" ***********************************************************************\n");
            printf(" *                                                                     *\n");
            printf(" *************************       Empleado       ************************\n");
            printf(" *                                                                     *\n");
            printf(" ***********************************************************************\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));

            printf("\n");

            seguir = validarSeguir();

            if(seguir == 'S'  || seguir == 's')
            {
                ll_remove(pArrayListEmployee,indice);

                printf("\n");

                printf(" Empleado eliminado con exito\n");
            }
            else
            {
                printf("\n");
                printf(" Baja cancelada\n");
            }
        }

        retorno = 1;

    }

    return retorno;
}

/** \brief Modifica los valores a elegir por parte del usuario segun su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int darModificacion(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* pEmp;
    int id;
    char valId[5];
    int indice;
    int opcion;
    char valOpcion[2];
    char seguir;
    char nuevoNombre[128];
    int horas;
    char valHoras[10];
    int sueldo;
    char valSueldo[10];


    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                     >>>> Modificacion Empleado <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(valId);

        id = validarEntero(valId);

        printf("\n");

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
            printf("\n");
        }
        else
        {
            system("cls");
            printf(" ***********************************************************************\n");
            printf(" *                                                                     *\n");
            printf(" *************************       Empleado       ************************\n");
            printf(" *                                                                     *\n");
            printf(" ***********************************************************************\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));
            pEmp = (Employee*)ll_get(pArrayListEmployee,indice);
            printf("\n");

            printf(" Que desea modificar?\n");
            printf(" 1. Nombre\n 2. Horas\n 3. Sueldo\n");
            printf(" Ingrese opcion: ");
            fflush(stdin);
            gets(valOpcion);

            opcion = validarEntero(valOpcion);

            switch(opcion)
            {
            case 1:
                system("cls");

                printf(" ***********************************************************************\n");
                printf(" *                                                                     *\n");
                printf(" *                        Modificar Nombre                             *\n");
                printf(" *                                                                     *\n");
                printf(" ***********************************************************************\n");

                printf("\n");

                printf(" Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(nuevoNombre);

                validarStringTam(nuevoNombre,128);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    strcpy(pEmp->nombre,nuevoNombre);

                    ll_set(pArrayListEmployee,indice,pEmp);
                    retorno = 1;

                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 2:

                system("cls");

                printf(" ***********************************************************************\n");
                printf(" *                                                                     *\n");
                printf(" *                        Modificar Horas                              *\n");
                printf(" *                                                                     *\n");
                printf(" ***********************************************************************\n");

                printf("\n");

                printf(" Ingrese horas trabajadas: ");
                fflush(stdin);
                gets(valHoras);

                horas = validarEntero(valHoras);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->horasTrabajadas = horas;

                    ll_set(pArrayListEmployee,indice,pEmp);

                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            case 3:

                system("cls");

                printf(" ***********************************************************************\n");
                printf(" *                                                                     *\n");
                printf(" *                        Modificar Sueldo                             *\n");
                printf(" *                                                                     *\n");
                printf(" ***********************************************************************\n");
                printf("\n");

                printf(" Ingrese sueldo: ");
                fflush(stdin);
                gets(valSueldo);

                sueldo = validarEntero(valSueldo);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    pEmp->sueldo = sueldo;

                    ll_set(pArrayListEmployee,indice,pEmp);

                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion exitosa!!!\n");
                }
                else
                {
                    retorno = 1;
                    printf("\n");
                    printf(" Modificacion cancelada\n");
                }
                break;
            default:
                retorno = 0;
                printf("\n");
                printf(" Esta opcion no existe\n");
            }
        }
    }

    return retorno;
}


/** \brief Busca el ID de un empleado
 *
 * \param pAux Employee*
 * \param id int
 * \param pArrayEmp LinkedList*
 * \return int
 *
 */
int searchId(int id, LinkedList* pArrayEmp)
{
    int indice = -1;
    Employee* pAux;

    if(pArrayEmp !=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pAux = (Employee*)ll_get(pArrayEmp,i);

            if(pAux !=NULL && pAux->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


/** \brief Carga de manera incremental el ID de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int generadorId(LinkedList* pArrayListEmployee)
{
    Employee* aux;
    int cant;
    int id;
    int maxID = -1;
    int i;
    if(pArrayListEmployee != NULL)
    {
        cant = ll_len(pArrayListEmployee);

        for(i=0; i<cant; i++)
        {
            if(aux !=NULL)
            {
                aux = ll_get(pArrayListEmployee, i);
                employee_getId(aux, &id);

                if(id > maxID)
                {
                    maxID = id;
                }
            }
        }
    }

    maxID += 1;

    return maxID;
}


/** \brief Ingresa los datos del empleado a dar de alta
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int darAltaDos(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* nuevoEmpleado;
    char nombre[128];
    char valHoras[10];
    char valSueldo[10];
    char valLugar[10];
    int horas;
    int sueldo;
    int lugar;

    nuevoEmpleado = employee_new();

    if(pArrayListEmployee !=NULL && nuevoEmpleado !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                          >>>> Alta Empleado <<<<                           #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf(" Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);

        employee_setNombre(nuevoEmpleado,nombre);

        printf("\n");

        printf(" Ingrese Horas: ");
        fflush(stdin);
        gets(valHoras);

        horas = validarEntero(valHoras);

        employee_setHorasTrabajadas(nuevoEmpleado,horas);

        printf("\n");

        printf(" Ingrese sueldo: ");
        fflush(stdin);
        gets(valSueldo);

        sueldo = validarEntero(valSueldo);

        employee_setSueldo(nuevoEmpleado,sueldo);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = generadorId(pArrayListEmployee);

            printf("\n");
            printf(" Ingrese lugar: ");
            fflush(stdin);
            gets(valLugar);

            lugar = validarEntero(valLugar) - 1;

            ll_push(pArrayListEmployee,lugar,nuevoEmpleado);

            retorno = 1;
        }
    }

    return retorno;
}

int darBajaDos(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    char valId[5];
    int indice;
    char seguir;
    void* pAux;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                             >>>> Baja Empleado <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados(pArrayListEmployee);

        printf(" Ingrese ID del empleado: ");
        fflush(stdin);
        gets(valId);

        id = validarEntero(valId);

        printf("\n");

        indice = searchId(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
        }
        else
        {
            system("cls");
            printf(" ***********************************************************************\n");
            printf(" *                                                                     *\n");
            printf(" *************************       Empleado       ************************\n");
            printf(" *                                                                     *\n");
            printf(" ***********************************************************************\n");

            printf("   Id   Nombre   Horas   Sueldo\n");
            printf("   --   ------   -----   ------\n");
            mostrarEmpleado((Employee*)ll_get(pArrayListEmployee,indice));
            pAux = (void*)ll_get(pArrayListEmployee,indice);

            printf("\n");

            seguir = validarSeguir();

            if(seguir == 'S'  || seguir == 's')
            {
                ll_push(pArrayListEmployee,indice,pAux);

                printf("\n");

                printf(" Empleado eliminado con exito\n");
            }
            else
            {
                printf("\n");
                printf(" Baja cancelada\n");
            }
        }

        retorno = 1;

    }

    return retorno;
}

void darAltaTres(Employee* kk)
{
    char nombre[128];
    char valHoras[10];
    char valSueldo[10];
    char ValId[10];
    int id;
    int horas;
    int sueldo;

        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                          >>>> buscar Empleado <<<<                         #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");


        printf(" Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(ValId);
        id = validarEntero(ValId);
        kk->id = id;

        printf(" Ingrese Nombre: ");
        fflush(stdin);
        gets(nombre);

        strcpy(kk->nombre,nombre);

        printf("\n");

        printf(" Ingrese Horas: ");
        fflush(stdin);
        gets(valHoras);

        horas = validarEntero(valHoras);

        kk->horasTrabajadas = horas;

        printf("\n");

        printf(" Ingrese sueldo: ");
        fflush(stdin);
        gets(valSueldo);

        sueldo = validarEntero(valSueldo);

        kk->sueldo = sueldo;
}

void* modificarSueldo(void* pp)
{
    int sueldo = 0;
    void* retorno = 0;

    if(pp !=NULL)
    {
        //aumento sueldo

        employee_getSueldo(((Employee*)pp),&sueldo);

        sueldo = 2*sueldo;

        employee_setSueldo(((Employee*)pp),sueldo);

        retorno = 1;

    }

    return retorno;
}

void* modificarSueldo1(void* pp)
{
    int sueldo = 0;
    void* retorno = 0;

    if(pp !=NULL)
    {
        //aumento sueldo

        employee_getSueldo(((Employee*)pp),&sueldo);

        sueldo = 2*sueldo;

        employee_setSueldo(((Employee*)pp),sueldo);

        retorno = 1;

    }

    return retorno;
}

void modificarSueldo2(void* pp)
{
    int sueldo = 0;

    if(pp !=NULL)
    {
        //aumento sueldo

        employee_getSueldo(((Employee*)pp),&sueldo);

        sueldo = 2*sueldo;

        employee_setSueldo(((Employee*)pp),sueldo);

    }

}


int filtrarSueldo(void* x)
{
    int retorno = 0;
    Employee* emp1;

    if(x !=NULL)
    {
        emp1 = (Employee*)x;

        if(emp1->sueldo >= 20000 && emp1->sueldo <= 40000)
        {
            retorno = 1;
        }
    }

    return retorno;
}

