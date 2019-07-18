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

int employee_setIdEnvio(eEnvio* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->idEnvio = id;
        retorno = 1;
    }

    return retorno;

}

int employee_setProducto(eEnvio* this,char* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {
        strcpy(this->producto,id);
        retorno = 1;
    }

    return retorno;

}

int employee_setIdCamion(eEnvio* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->idCamion = id;
        retorno = 1;
    }

    return retorno;

}

int employee_setDestino(eEnvio* this,char* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {
        strcpy(this->destino,id);
        retorno = 1;
    }

    return retorno;

}


int employee_setKm(eEnvio* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->kmRecorridos = id;
        retorno = 1;
    }

    return retorno;

}


int employee_setEntrega(eEnvio* this,int id)
{

    int retorno = 0;

    if( this != NULL)
    {

        this->tipoEntrega = id;
        retorno = 1;
    }

    return retorno;

}


int employee_setCosto(eEnvio* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->costo = id;
        retorno = 1;
    }

    return retorno;

}

int employee_getIdEnvio(eEnvio* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->idEnvio;
        retorno = 1;
    }
    return retorno;
}

int employee_getProducto(eEnvio* this,char* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        strcpy(id,this->producto);
        retorno = 1;
    }
    return retorno;
}


int employee_getIdCamion(eEnvio* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->idCamion;
        retorno = 1;
    }
    return retorno;
}

int employee_getDestino(eEnvio* this,char* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {

        strcpy(id,this->destino);
        retorno = 1;
    }

    return retorno;

}

int employee_getKm(eEnvio* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {

        *id = this->kmRecorridos;
        retorno = 1;
    }

    return retorno;

}


int employee_getEntrega(eEnvio* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {

        *id = this->tipoEntrega;
        retorno = 1;
    }

    return retorno;

}

int employee_getCosto(eEnvio* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id !=NULL)
    {

        *id = this->costo;
        retorno = 1;
    }

    return retorno;

}

/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */

eEnvio* employee_new()
{

    eEnvio* this = (eEnvio*) malloc(sizeof(eEnvio));

    if( this != NULL)
    {
        this->idEnvio = 0;
        strcpy(this->producto, "");
        this->idCamion = 0;
        strcpy(this->destino, "");
        this->kmRecorridos = 0;
        this->tipoEntrega = 0;
        this->costo = 0;
    }

    return this;
}

/*
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
*/
/** \brief Lllama a los set del empleado
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
eEnvio* employee_newParametros(char* idEnvStr,char* prodStr,char* idCamStr, char* destinoStr, char* kmStr, char* entregaStr)
{
    eEnvio* this;

    if (idEnvStr != NULL && prodStr != NULL && idCamStr != NULL && destinoStr !=NULL && kmStr !=NULL && entregaStr !=NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setIdEnvio(this, atoi(idEnvStr))|| !employee_setProducto(this, prodStr) || !employee_setIdCamion(this, atoi(idCamStr)) || !employee_setDestino(this, destinoStr) || !employee_setKm(this, atoi(kmStr)) || !employee_setEntrega(this, atoi(entregaStr)))

            {
                employee_delete(this);
                this = NULL;
            }
        }
    }

    return this;
}

/*
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
*/
/** \brief Libera memoria
 *
 * \param emp Employee*
 * \return void
 *
 */
void employee_delete(eEnvio* emp)
{
    if(emp !=NULL)
    {
        free(emp);
    }
}

/*
void employee_delete2(eVentas* emp)
{
    if(emp !=NULL)
    {
        free(emp);
    }
}
*/
/** \brief Obtiene a los empleados y lo muestra
 *
 * \param pEmp Employee*
 * \return void
 *
 */
void mostrarEmpleado(eEnvio* pEmp)
{
    int idEnvio;
    char prod[128];
    int idCamion;
    char destino[128];
    int km;
    int entrega;

    if(pEmp !=NULL)
    {
        if(employee_getIdEnvio(pEmp,&idEnvio) && employee_getProducto(pEmp,prod) && employee_getIdCamion(pEmp,&idCamion) && employee_getDestino(pEmp,destino) && employee_getKm(pEmp,&km) && employee_getEntrega(pEmp,&entrega))
        {
            printf("%5d %8s %6d %8s %5d %5d\n",idEnvio,prod,idCamion,destino,km,entrega);
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
/*
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
*/
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
/*
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
*/
/** \brief Ordena a los empleados segun la opcion seleccionada
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
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
*/
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
    eEnvio* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Envios       *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 100.\n");

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%100==0)
            {
                system("pause");
                system("cls");
                printf("   IdEnvio   Producto   IdCamion    Destino   KmRecorridos   TipoEntrega\n");
                printf("   -------   --------   --------    -------   ------------   ------------\n");
                empleado = (eEnvio*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }
            else
            {
                empleado = (eEnvio*)ll_get(pArrayListEmployee,i);
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
/*
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
            mostrarEmpleado2((eVentas*)ll_get(pArrayListEmployee,indice));

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
*/
/** \brief Modifica los valores a elegir por parte del usuario segun su ID
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
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
*/
/** \brief Busca el ID de un empleado
 *
 * \param pAux Employee*
 * \param id int
 * \param pArrayEmp LinkedList*
 * \return int
 *
 */
/*
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
*/
/** \brief Carga de manera incremental el ID de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*
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
*/
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

void mostrarEmpleado2(eEnvio* pEmp)
{
    int idEnvio;
    char prod[128];
    int idCamion;
    char destino[128];
    int km;
    int entrega;
    int costo;

    if(pEmp !=NULL)
    {

        if(employee_getIdEnvio(pEmp,&idEnvio) && employee_getProducto(pEmp,prod) && employee_getIdCamion(pEmp,&idCamion) && employee_getDestino(pEmp,destino) && employee_getKm(pEmp,&km) && employee_getEntrega(pEmp,&entrega) && employee_getCosto(pEmp,&costo))
        {
            printf("%8d %6s %8d %6s %6d %6d %6d\n",idEnvio,prod,idCamion,destino,km,entrega,costo);
        }
    }
}

/*
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
*/

void mostrarEmpleado3(eEnvio* pEmp)
{
    char lugar[128];
    int ave = 0;
    int ban = 0;
    int lan = 0;
    int cab = 0;
    int quil = 0;

    if(pEmp !=NULL)
    {
        if(employee_getDestino(pEmp,lugar))
        {
            if(strcmp(lugar,"avellaneda")==0 && ave == 0)
            {
                printf(" %s\n",lugar);
                ave = 1;
            }
            else if(strcmp(lugar,"bandfield")==0 && ban == 0)
            {
                printf(" %s\n",lugar);
                ban = 1;
            }
            else if(strcmp(lugar,"lanus")==0 && lan == 0)
            {
                printf(" %s\n",lugar);
                lan = 1;
            }
            else if(strcmp(lugar,"caba")==0 && cab == 0)
            {
                printf( "%s\n",lugar);
                cab = 0;
            }
            else if(strcmp(lugar,"quilmes")==0 && quil == 0)
            {
                printf( "%s\n",lugar);
                quil = 1;
            }
        }
    }
}

int listarEmpleados2(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eEnvio* empleado;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************    Listado de Envios       *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        printf(" A continuacion se le mostrara todos los vendedores\n");
        printf(" en forma encolumnada de a 100.\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%100==0)
            {
                system("pause");
                system("cls");
                printf("   IdEnvio   Producto   IdCamion    Destino   KmRecorridos   TipoEntrega   CostoEnvio\n");
                printf("   -------   --------   --------    -------   ------------   ------------  -----------\n");
                empleado = (eEnvio*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }
            else
            {
                empleado = (eEnvio*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }
        }

        retorno = 1;
    }

    system("pause");
    return retorno;
}

/*
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
*/

/*
int listarEmpleados3(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    eEnvio* empleado;
    char lugar[128];
    int ave = 0;
    int ban = 0;
    int lan = 0;
    int cab = 0;
    int quil = 0;

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***********************************************************************\n");
        printf(" *                                                                     *\n");
        printf(" **********************        Listado Final       *********************\n");
        printf(" *                                                                     *\n");
        printf(" ***********************************************************************\n");

        printf("\n");

        for(int i=0; i < ll_len(pArrayListEmployee); i++)
        {
            system("pause");
            system("cls");
            printf(" Zonas disponibles\n");
            printf(" -----------------\n");
            empleado = (eEnvio*)ll_get(pArrayListEmployee,i);
            employee_getDestino(empleado,lugar);

            if(strcmp(lugar,"avellaneda")==0 && ave == 0)
            {
                printf(" %s\n",lugar);
                ave = 1;
            }
            else if(strcmp(lugar,"bandfield")==0 && ban == 0)
            {
                printf(" %s\n",lugar);
                ban = 1;
            }
            else if(strcmp(lugar,"lanus")==0 && lan == 0)
            {
                printf(" %s\n",lugar);
                lan = 1;
            }
            else if(strcmp(lugar,"caba")==0 && cab == 0)
            {
                printf( "%s\n",lugar);
                cab = 0;
            }
            else if(strcmp(lugar,"quilmes")==0 && quil == 0)
            {
                printf( "%s\n",lugar);
                quil = 1;
            }
        }

        retorno = 1;
    }

    system("pause");
return retorno;
}
*/

int listarEmpleados3(LinkedList* pLinkedListEnvio)
{
    int retorno = 0;
    char destino[128];
    int  cntLanus=0;
    int  cntAvell=0;
    int  cntQuilm=0;
    int  cntCaba=0;
    int  cntBandf=0;
    eEnvio* auxPunteroEnvio;

    if(pLinkedListEnvio != NULL)
    {
        retorno = 1;

        for(int i=0;i < ll_len(pLinkedListEnvio);i++)
        {
            auxPunteroEnvio = (eEnvio*)ll_get(pLinkedListEnvio,i);
            employee_getDestino(auxPunteroEnvio,destino);

            if(strcmp(destino,"lanus")==0 && cntLanus==0)
               {
                    printf("\n Zona de destino: %s \n",destino);
                    cntLanus=1;
               }
            else if(strcmp(destino,"avellaneda")==0 && cntAvell==0)
                    {
                        printf("\n Zona de destino: %s \n",destino);
                        cntAvell=1;
                    }
                 else if(strcmp(destino,"quilmes")==0 && cntQuilm==0)
                        {
                            printf("\n Zona de destino: %s \n",destino);
                            cntQuilm=1;
                        }
                        else if(strcmp(destino,"bandfield")==0 && cntBandf==0)
                                {
                                    printf("\n Zona de destino: %s \n",destino);
                                    cntBandf=1;
                                }
                                else if(strcmp(destino,"caba")==0 && cntCaba==0)
                                        {
                                            printf("\n Zona de destino: %s \n",destino);
                                            cntCaba=1;
                                        }
        }
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
/*
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
*/

int calcularCosto(void* pp)
{
    int retorno = 0;
    eEnvio* pAux;
    int km;
    int entrega;
    int costo;

    if(pp !=NULL)
    {
        pAux = (eEnvio*)pp;

        employee_getKm(pAux,&km);
        employee_getEntrega(pAux,&entrega);

        if(km < 50)
        {
            costo = km*100;
        }
        else
        {
            costo = km*50;
        }

        if(entrega == 0)
        {
            costo = costo+250;
            employee_setCosto(pAux,costo);
            retorno = 1;
        }
        else if(entrega == 1)
        {
            costo = costo+420;
            employee_setCosto(pAux,costo);
            retorno = 1;
        }
        else
        {
            costo = costo+75;
            employee_setCosto(pAux,costo);
            retorno = 1;
        }
    }

    return retorno;
}

int filtrarAvellaneda(void* x)
{
    int retorno = 0;
    eEnvio* vend1;
    char lugar[128];

    if(x !=NULL)
    {
        vend1 = (eEnvio*)x;

        if(employee_getDestino(vend1,lugar))
        {
            if(strcmp(lugar,"avellaneda")==0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}

int filtrarBandfield(void* x)
{
    int retorno = 0;
    eEnvio* vend1;
    char lugar[128];

    if(x !=NULL)
    {
        vend1 = (eEnvio*)x;

        if(employee_getDestino(vend1,lugar))
        {
            if(strcmp(lugar,"bandfield")==0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


int filtrarLanus(void* x)
{
    int retorno = 0;
    eEnvio* vend1;
    char lugar[128];

    if(x !=NULL)
    {
        vend1 = (eEnvio*)x;

        if(employee_getDestino(vend1,lugar))
        {
            if(strcmp(lugar,"lanus")==0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


int filtrarCaba(void* x)
{
    int retorno = 0;
    eEnvio* vend1;
    char lugar[128];

    if(x !=NULL)
    {
        vend1 = (eEnvio*)x;

        if(employee_getDestino(vend1,lugar))
        {
            if(strcmp(lugar,"caba")==0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


int filtrarQuilmes(void* x)
{
    int retorno = 0;
    eEnvio* vend1;
    char lugar[128];

    if(x !=NULL)
    {
        vend1 = (eEnvio*)x;

        if(employee_getDestino(vend1,lugar))
        {
            if(strcmp(lugar,"quilmes")==0)
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}
