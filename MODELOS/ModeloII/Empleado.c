#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Validaciones.h"

/** \brief Set del ID del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(eCliente* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->id = id;
        retorno = 1;
    }

    return retorno;

}

int employee_setProducto(eVentas* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->codProd = id;
        retorno = 1;
    }

    return retorno;

}

int employee_setCantidad(eVentas* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->cant = id;
        retorno = 1;
    }

    return retorno;

}

int employee_getProducto(eVentas* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->codProd;
        retorno = 1;
    }
    return retorno;
}

int employee_getCantidad(eVentas* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->cant;
        retorno = 1;
    }
    return retorno;
}


int employee_getId(eCliente* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->id;
        retorno = 1;
    }
    return retorno;
}

int employee_setIdVenta(eVentas* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->idVenta = id;
        retorno = 1;
    }

    return retorno;

}

int employee_setCliente(eVentas* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->idCliente = id;
        retorno = 1;
    }

    return retorno;

}


int employee_setPrecio(eVentas* this,float id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->total = id;
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
int employee_getCliente(eVentas* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->idCliente;
        retorno = 1;
    }
    return retorno;
}

int employee_getIdVenta(eVentas* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->idVenta;
        retorno = 1;
    }
    return retorno;
}

int employee_getPrecio(eVentas* this,float* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->total;
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
int employee_setNombre(eCliente* this,char* nombre)
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
int employee_getNombre(eCliente* this,char* nombre)
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
int employee_setApellido(eCliente* this,char* apellido)
{
    int retorno = 0;

    if(this != NULL && apellido !=NULL)
    {
        strcpy(this->apellido,apellido);
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
int employee_getApellido(eCliente* this,char* apellido)
{
    int retorno = 0;

    if( this != NULL && apellido != NULL )
    {

        strcpy(apellido,this->apellido);
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
int employee_setDni(eCliente* this,char* dni)
{
    int retorno = 0;

    if( this != NULL && dni !=NULL)
    {
        strcpy(this->dni,dni);
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
int employee_getDni(eCliente* this,char* dni)
{
    int retorno = 0;

    if( this != NULL && dni != NULL )
    {

        strcpy(dni,this->dni);
        retorno = 1;
    }
    return retorno;
}

/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */
eCliente* employee_new()
{

    eCliente* this = (eCliente*) malloc(sizeof(eCliente));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        strcpy(this->apellido, "");
        strcpy(this->dni, "");
    }

    return this;
}


eVentas* employee_new2()
{

    eVentas* this = (eVentas*) malloc(sizeof(eVentas));

    if( this != NULL)
    {
        this->idVenta = 0;
        this->idCliente = 0;
        this->codProd = 0;
        this->cant = 0;
    }

    return this;
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
eCliente* employee_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* dniStr)
{
    eCliente* this;

    if (idStr != NULL && nombreStr != NULL && apellidoStr != NULL && dniStr !=NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))|| !employee_setNombre(this, nombreStr) || !employee_setApellido(this, apellidoStr) || !employee_setDni(this, dniStr))

            {
                employee_delete(this);
                this = NULL;
            }
        }
    }

    return this;
}


eVentas* employee_newParametrosDos(char* idStr,char* idClienteStr,char* codProdStr, char* cantStr, char* precioStr)
{
    eVentas* this;

    if (idStr != NULL && idClienteStr != NULL && codProdStr != NULL && cantStr !=NULL)
    {
        this  = employee_new2();

        if( this != NULL)
        {

            if( !employee_setIdVenta(this, atoi(idStr))|| !employee_setCliente(this, atoi(idClienteStr)) || !employee_setProducto(this, atoi(codProdStr)) || !employee_setCantidad(this, atoi(cantStr)) || !employee_setPrecio(this, atof(precioStr)))

            {
                employee_delete2(this);
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
void employee_delete(eCliente* emp)
{
    if(emp !=NULL)
    {
        free(emp);
    }
}

void employee_delete2(eVentas* emp)
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
void mostrarEmpleado(eCliente* pEmp)
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[128];

    if(pEmp !=NULL)
    {
        if(employee_getId(pEmp,&id) && employee_getNombre(pEmp,nombre) && employee_getApellido(pEmp,apellido) && employee_getDni(pEmp,dni))
        {
            printf("%5d %8s %6s %8s\n",id,nombre,apellido,dni);
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
/*
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
*/
/** \brief Ordena a los empleados por nombre en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */

int ordenarXapellido(void* numA, void* numB)
{
    int retorno = -1;
    eCliente* pUno;
    eCliente* pDos;

    if(numA !=NULL && numB !=NULL)
    {
        pUno = (eCliente*)numA;
        pDos = (eCliente*)numB;

        if(stricmp(pUno->apellido,pDos->apellido)>0)
        {
            retorno = 1;
        }
        else if(stricmp(pUno->apellido,pDos->apellido)<0)
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
/*
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
*/
/** \brief Ordena a los empleados por sueldo en forma ascendente
 *
 * \param numA void*
 * \param numB void*
 * \return int
 *
 */
/*
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
*/
/** \brief Ingresa los datos del empleado a dar de alta
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int darAlta(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eCliente* nuevoEmpleado;
    char nombre[128];
    char apellido[128];
    char dni[128];

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

        printf(" Ingrese Apellido: ");
        fflush(stdin);
        gets(apellido);

        employee_setApellido(nuevoEmpleado,apellido);

        printf("\n");

        printf(" Ingrese DNI: ");
        fflush(stdin);
        gets(dni);

        employee_setDni(nuevoEmpleado,dni);

        if(nuevoEmpleado !=NULL)
        {
            nuevoEmpleado->id = generadorId(pArrayListEmployee);
            ll_add(pArrayListEmployee,nuevoEmpleado);

            retorno = 1;
        }
    }

    return retorno;
}


int darAltaDos(LinkedList* pArrayListEmployee, LinkedList* alo)
{
    int retorno = 0;
    eVentas* nuevoEmpleado;
    int idCliente;
    int cant;
    int prod;
    char valProd[5];

    nuevoEmpleado = employee_new2();

    if(pArrayListEmployee !=NULL && nuevoEmpleado !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                          >>>> Alta Empleado <<<<                           #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        controller_ListEmployee(alo);

        printf(" Ingrese idCliente: ");
        fflush(stdin);
        scanf("%d",&idCliente);

        if(searchId(idCliente,alo)==-1)
        {
            printf("Este empleado no existe\n");
            system("pause");
        }
        else
        {
            employee_setCliente(nuevoEmpleado,idCliente);

            printf("\n");

            printf(" Codigo  Descripcion  Precio\n");
            printf(" ------  -----------  ------\n");
            printf("  1000    TV_LG_32    8999.99\n");
            printf("  1001      PS4       12999.99\n");
            printf("  1002     IPHONE     19480.99\n");
            printf(" Ingrese Cod. Producto: ");
            fflush(stdin);
            gets(valProd);

            prod = validarEnteroRango(valProd,1000,1002);

            if(prod == 1000)
            {
                nuevoEmpleado->total = 8999.99;
                employee_setPrecio(nuevoEmpleado,8999.99);
            }
            else if(prod == 1001)
            {
                nuevoEmpleado->total = 12999.99;
                employee_setPrecio(nuevoEmpleado,12999.99);
            }
            else
            {
                nuevoEmpleado->total = 19480.99;
                employee_setPrecio(nuevoEmpleado,19480.99);
            }

            employee_setProducto(nuevoEmpleado,prod);

            printf("\n");

            printf(" Ingrese Cantidad Prod.: ");
            fflush(stdin);
            scanf("%d",&cant);

            employee_setCantidad(nuevoEmpleado,cant);

            if(nuevoEmpleado !=NULL)
            {
                nuevoEmpleado->idVenta = generadorId2(pArrayListEmployee);
                ll_add(pArrayListEmployee,nuevoEmpleado);

                retorno = 1;
            }

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
        printf(" #                        >>>> Ordenar x Apellido <<<<                        #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");

        printf("\n");
        printf(" AVISO: Debido a la enorme cantidad de empleados,\n");
        printf(" va a demorar un poco el ordenarlos.\n");
        printf(" Por favor, espere. Gracias!!!\n");

        printf("\n");

        if(ll_sort(pArrayListEmployee, ordenarXapellido, 1)==-1)
        {
            retorno = 0;
        }
        else
        {
            retorno = 1;
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
    eCliente* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Clientes     *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 200.\n");

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   Nombre   Apellido    DNI\n");
                printf("   --   ------   --------   -----\n");
                empleado = (eCliente*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }
            else
            {
                empleado = (eCliente*)ll_get(pArrayListEmployee,i);
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

            printf("   Id   Nombre   Apellido  DNI\n");
            printf("   --   ------   --------  ----\n");
            mostrarEmpleado((eCliente*)ll_get(pArrayListEmployee,indice));

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


int darBajaDos(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int id;
    char valId[5];
    int indice;
    char seguir;
    eVentas* pAux;

    if(pArrayListEmployee !=NULL)
    {
        system("cls");
        printf(" ==============================================================================\n");
        printf(" #                                                                            #\n");
        printf(" #                             >>>> Baja Venta <<<<                           #\n");
        printf(" #                                                                            #\n");
        printf(" ==============================================================================\n");
        system("pause");

        listarEmpleados2(pArrayListEmployee);

        printf(" Ingrese Cod.Venta: ");
        fflush(stdin);
        gets(valId);

        id = validarEntero(valId);

        printf("\n");

        indice = searchId2(id,pArrayListEmployee);

        if(indice == -1)
        {
            printf(" El ID %d no existe\n",id);
        }
        else
        {
            system("cls");
            printf(" ***********************************************************************\n");
            printf(" *                                                                     *\n");
            printf(" *************************       Venta          ************************\n");
            printf(" *                                                                     *\n");
            printf(" ***********************************************************************\n");

            printf("   Id   idCliente   CodProd   CantProd   Precio\n");
            printf("   --   ---------   -------   --------   ------\n");
            pAux = (eVentas*)ll_get(pArrayListEmployee,indice);
            mostrarEmpleado2(pAux);

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
    eCliente* pEmp;
    int id;
    char valId[5];
    int indice;
    int opcion;
    char valOpcion[2];
    char seguir;
    char nuevoNombre[128];
    char nuevoApellido[128];
    char nuevoDni[128];

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

            printf("   Id   Nombre   Apellido   DNI\n");
            printf("   --   ------   --------   ---\n");
            mostrarEmpleado((eCliente*)ll_get(pArrayListEmployee,indice));
            pEmp = (eCliente*)ll_get(pArrayListEmployee,indice);

            printf("\n");

            printf(" Que desea modificar?\n");
            printf(" 1. Nombre\n 2. Apellido\n 3. DNI\n");
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
                printf(" *                        Modificar Apellido                           *\n");
                printf(" *                                                                     *\n");
                printf(" ***********************************************************************\n");

                printf("\n");

                printf(" Ingrese apellido: ");
                fflush(stdin);
                gets(nuevoApellido);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    retorno = 1;
                    strcpy(pEmp->apellido,nuevoApellido);
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
                printf(" *                        Modificar DNI                                *\n");
                printf(" *                                                                     *\n");
                printf(" ***********************************************************************\n");
                printf("\n");

                printf(" Ingrese DNI: ");
                fflush(stdin);
                gets(nuevoDni);

                printf("\n");

                seguir = validarSeguir();

                if(seguir == 'S'  || seguir == 's')
                {
                    retorno = 1;
                    strcpy(pEmp->dni,nuevoDni);
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
    eCliente* pAux;

    if(pArrayEmp !=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pAux = (eCliente*)ll_get(pArrayEmp,i);

            if(pAux !=NULL && pAux->id == id)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}

int searchId2(int id, LinkedList* pArrayEmp)
{
    int indice = -1;
    eVentas* pAux;

    if(pArrayEmp !=NULL)
    {
        for(int i=0; i<ll_len(pArrayEmp); i++)
        {
            pAux = (eVentas*)ll_get(pArrayEmp,i);

            if(pAux !=NULL && pAux->idVenta == id)
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
    eCliente* aux;
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

int generadorId2(LinkedList* pArrayListEmployee)
{
    eVentas* aux;
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
                employee_getIdVenta(aux, &id);

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

/*
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

        retorno = 0;

    }

    return retorno;
}
*/
/*
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
*/
/*
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
*/
/*
void em_calcularSueldo(void* p)
{
    int sueldo;
    int horasTrabajadas;
    Employee* aux = (Employee*)p;
    if(p != NULL)
    {
        horasTrabajadas = aux->horasTrabajadas;
        sueldo = horasTrabajadas;
        if(horasTrabajadas<=120)
        {
            sueldo *= 180;
        }else if(horasTrabajadas<=160)
            {
                sueldo *= 240;
            }else if(horasTrabajadas<=240)
                {
                    sueldo *= 350;
                }
       aux->sueldo=sueldo;
    }
}
*/
/*
void calcularSueldo(void* pp)
{
    int sueldo;
    int horas;
    Employee* aux;

    aux = (Employee*)pp;

    if(pp !=NULL)
    {
        horas = aux->horasTrabajadas;

        if(horas <=120)
        {
            sueldo = horas*180;
        }
        else if(horas <=160)
        {
            sueldo = horas*240;
        }
        else
        {
            sueldo = horas*350;
        }

    }

    aux->sueldo = sueldo;

}
*/

/*
int filtrarNivelCero(void* x)
{
    int retorno = 0;
    eVendedor* vend1;
    int nivel;

    if(x !=NULL)
    {
        vend1 = (eVendedor*)x;

        if(employee_getNivel(vend1,&nivel))
        {
            if(nivel == 0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int filtrarNivelUno(void* x)
{
    int retorno = 0;
    eVendedor* vend1;
    int nivel;

    if(x !=NULL)
    {
        vend1 = (eVendedor*)x;

        if(employee_getNivel(vend1,&nivel))
        {
            if(nivel == 1)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int filtrarNivelDos(void* x)
{
    int retorno = 0;
    eVendedor* vend1;
    int nivel;

    if(x !=NULL)
    {
        vend1 = (eVendedor*)x;

        if(employee_getNivel(vend1,&nivel))
        {
            if(nivel == 2)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}
*/
/*
void calcularComision(void* pp)
{
    float comision;
    float monto;
    int cant;
    eVendedor* vend1;

    if(pp !=NULL)
    {
        vend1 = (eVendedor*)pp;

        monto = vend1->montoVendido;

        cant = vend1->cantProdVend;

        if(vend1->nivel == 0)
        {
            comision = monto * 0.2;
        }
        else
        {
            if(cant < 100)
            {
                comision = monto * 0.035;
            }
            else
            {
                comision = monto * 0.05;
            }
        }

        vend1->comision = comision;

    }
}

void* calcularComision2(void* pp)
{
    float comision;
    float monto;
    int cant;
    int nivel;
    void* retorno = 0;

    if(pp !=NULL)
    {
        employee_getCantProd((eVendedor*)pp, &cant);
        employee_getMonto((eVendedor*)pp, &monto);
        employee_getNivel((eVendedor*)pp, &nivel);

        if(nivel == 0)
        {
            comision = monto * 0.2;
        }
        else
        {
            if(cant < 100)
            {
                comision = monto * 0.035;
            }
            else
            {
                comision = monto * 0.05;
            }
        }

        employee_setComision((eVendedor*)pp, comision);

        retorno = 1;

    }

    return retorno;
}
*/

void mostrarEmpleado2(eVentas* pEmp)
{
    int id;
    int cliente;
    int prod;
    int cant;
    int acum = 0;
    float precio;

    if(pEmp !=NULL)
    {

        if(employee_getIdVenta(pEmp,&id) && employee_getCliente(pEmp,&cliente) && employee_getCantidad(pEmp,&cant) && employee_getPrecio(pEmp,&precio))
        {
            printf("%8d %6d %d %.2f\n",id,cliente,cant,precio);
        }
    }
}

void mostrarEmpleado5(eVentas* pEmp, eCliente* cli)
{
    int id;
    int cliente;
    int prod;
    int cant;
    int acum = 0;
    float precio;
    char nombre[20];

    if(pEmp !=NULL)
    {
        if(employee_getCantidad(pEmp,&cant) && employee_getPrecio(pEmp,&precio) && employee_getNombre(cli,nombre))
        {
            acum = acum+cant;
            printf("%8s %6d %.2f\n",nombre,acum,precio);
        }
    }
}

void mostrarEmpleado4(eVentas* pEmp, eCliente* cli)
{
    int id;
    int cliente;
    int prod;
    int cant;
    float precio;
    char nombre[20];
    char apellido[20];
    char dni[20];

    if(pEmp !=NULL)
    {
        if(employee_getIdVenta(pEmp,&id) && employee_getProducto(pEmp,&prod) && employee_getPrecio(pEmp,&precio) && employee_getNombre(cli,nombre) && employee_getApellido(cli,apellido) && employee_getDni(cli,dni))
        {
            printf("%5d %8s %6s %8s %d %.2f\n",id,nombre,apellido,dni,prod,precio);
        }
    }
}

void mostrarEmpleado3(eVentas* pEmp)
{
    int cliente;
    int prod;
    int cant;
    float precio;

    if(pEmp !=NULL)
    {

        if(employee_getCliente(pEmp,&cliente) && employee_getProducto(pEmp,&prod) && employee_getCantidad(pEmp,&cant) && employee_getPrecio(pEmp,&precio))
        {
            printf("%8d %6d %8d %.2f\n",cliente,prod,cant,precio);
        }
    }
}


int listarEmpleados2(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eVentas* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Vendedores   *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 200.\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   idCliente   CodProd   CantProd   Precio\n");
                printf("   --   ---------   -------   --------   ------\n");
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }
            else
            {
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }
        }

        retorno = 1;
    }

    system("pause");
    return retorno;
}


int listarEmpleados5(LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = 0;
    eVentas* empleado;
    eCliente* cli;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Vendedores   *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 200.\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   idCliente   CodProd   CantProd   Precio\n");
                printf("   --   ---------   -------   --------   ------\n");
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                cli = (eCliente*)ll_get(pp,i);
                mostrarEmpleado5(empleado,cli);
            }
            else
            {
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                cli = (eCliente*)ll_get(pp,i);
                mostrarEmpleado5(empleado,cli);
            }
        }

        retorno = 1;
    }

    system("pause");
    return retorno;
}

int listarEmpleados4(LinkedList* pArrayListEmployee, LinkedList* pp)
{
    int retorno = 0;
    eVentas* empleado;
    eCliente* clientes;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Vendedores   *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 200.\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   idCliente   CodProd   CantProd   Precio\n");
                printf("   --   ---------   -------   --------   ------\n");
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                clientes = (eCliente*)ll_get(pp,i);
                mostrarEmpleado4(empleado,clientes);
            }
            else
            {
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                clientes = (eCliente*)ll_get(pp,i);
                mostrarEmpleado4(empleado,clientes);
            }
        }

        retorno = 1;
    }

    system("pause");
    return retorno;
}

int listarEmpleados3(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eVentas* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************        Listado Final       *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 200.\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf(" idCliente   CodProd   CantProd   Precio Total\n");
                printf(" ---------   -------   --------   ------------\n");
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado3(empleado);
            }
            else
            {
                empleado = (eVentas*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado3(empleado);
            }
        }

        retorno = 1;
    }

    system("pause");
    return retorno;
}

/*void buscarProducto(LinkedList* pp)
{
    eVentas* venta;
    int cod;

    printf(" Codigo  Descripcion  Precio\n");
    printf(" ------  -----------  ------\n");
    printf("  1000    TV_LG_32    8999.99\n");
    printf("  1001      PS4       12999.99\n");
    printf("  1002     IPHONE     19480.99\n");
    printf(" Ingrese Cod. Producto: ");
    scanf("%d",&cod);

    for(int i=0; i<ll_len(pp); i++)
    {
        printf("mmmm");

        if(venta->codProd == cod)
        {
            mostrarEmpleado2((eVentas*)ll_get(pp,i));
            listarEmpleados2(pp);
            printf("Puto¬¬");
        }
    }

    printf("jje");
}

*/

void* calcularMonto(void* pp)
{
    int cant;
    float precio;
    void* retorno = 0;

    if(pp !=NULL)
    {
        employee_getPrecio((eVentas*)pp,&precio);
        employee_getCantidad((eVentas*)pp,&cant);

        precio = precio*cant;

        employee_setPrecio((eVentas*)pp,precio);

        retorno = 1;

    }

    return retorno;
}
