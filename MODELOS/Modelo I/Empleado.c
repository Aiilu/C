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
int employee_setId(eVendedor* this,int id)
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
int employee_getId(eVendedor* this,int* id)
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
int employee_setNombre(eVendedor* this,char* nombre)
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
int employee_getNombre(eVendedor* this,char* nombre)
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
int employee_setNivel(eVendedor* this,int nivel)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->nivel = nivel;
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
int employee_getNivel(eVendedor* this,int* nivel)
{
    int retorno = 0;

    if( this != NULL && nivel != NULL )
    {

        *nivel = this->nivel;
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
int employee_setCantProd(eVendedor* this,int cant)
{
    int retorno = 0;

    if( this != NULL && cant > 0)
    {
        this->cantProdVend = cant;
        retorno = 1;
    }

    return retorno;

}


int employee_setMonto(eVendedor* this,float monto)
{
    int retorno = 0;

    if( this != NULL && monto > 0)
    {
        this->montoVendido = monto;
        retorno = 1;
    }

    return retorno;

}

int employee_setComision(eVendedor* this,float com)
{
    int retorno = 0;

    if( this != NULL && com > 0)
    {
        this->comision = com;
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
int employee_getCantProd(eVendedor* this,int* cant)
{
    int retorno = 0;

    if( this != NULL && cant != NULL )
    {

        *cant = this->cantProdVend;
        retorno = 1;
    }
    return retorno;
}

int employee_getMonto(eVendedor* this,float* monto)
{
    int retorno = 0;

    if( this != NULL && monto != NULL )
    {

        *monto = this->montoVendido;
        retorno = 1;
    }
    return retorno;
}

int employee_getComision(eVendedor* this,float* com)
{
    int retorno = 0;

    if( this != NULL && com != NULL )
    {

        *com = this->comision;
        retorno = 1;
    }
    return retorno;
}
/** \brief Crea espacio en memoria para un empleado
 *
 * \return Employee*
 *
 */
eVendedor* employee_new()
{

    eVendedor* this = (eVendedor*) malloc(sizeof(eVendedor));

    if( this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre, "");
        this->nivel = 0;
        this->cantProdVend = 0;
        this->montoVendido = 0;
        this->comision = 0;
    }

    return this;
}

eVendedor2* employee_new2()
{

    eVendedor2* this = (eVendedor2*) malloc(sizeof(eVendedor2));

    if( this != NULL)
    {
        this->id2 = 0;
        strcpy(this->nombre2, "");
        this->nivel2 = 0;
        this->cantProdVend2 = 0;
        this->montoVendido2 = 0;
        this->comision2 = 0;
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
eVendedor* employee_newParametros(char* idStr,char* nombreStr,char* nivelStr, char* cantProdStr, char* montoStr)
{
    eVendedor* this;

    if (idStr != NULL && nombreStr != NULL && nivelStr != NULL && cantProdStr !=NULL && montoStr !=NULL)
    {
        this  = employee_new();

        if( this != NULL)
        {

            if( !employee_setId(this, atoi(idStr))|| !employee_setNombre(this, nombreStr) || !employee_setNivel(this, atoi(nivelStr)) || !employee_setCantProd(this, atoi(cantProdStr)) || !employee_setMonto(this,atof(montoStr)))

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
void employee_delete(eVendedor* emp)
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
void mostrarEmpleado(eVendedor* pEmp)
{
    int id;
    char nombre[128];
    int nivel;
    int cant;
    float monto;

    if(pEmp !=NULL)
    {
        if(employee_getId(pEmp,&id) && employee_getNombre(pEmp,nombre) && employee_getNivel(pEmp,&nivel) && employee_getCantProd(pEmp,&cant) && employee_getMonto(pEmp,&monto))
        {
            printf("%5d %8s %6d %8d %.2f\n",id,nombre,nivel,cant,monto);
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
    eVendedor* empleado;

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

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   Nombre   Nivel   CantProd   MontoVend\n");
                printf("   --   ------   -----   --------   ---------\n");
                empleado = (eVendedor*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado(empleado);
            }
            else
            {
                empleado = (eVendedor*)ll_get(pArrayListEmployee,i);
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
                   retorno = 1;
                   pEmp->horasTrabajadas = horas;
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
                   retorno = 1;
                   pEmp->sueldo = sueldo;
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
        employee_getCantProd2((eVendedor2*)pp, &cant);
        employee_getMonto2((eVendedor2*)pp, &monto);
        employee_getNivel2((eVendedor2*)pp, &nivel);

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

        employee_setComision2((eVendedor2*)pp, comision);

        retorno = 1;

    }

    return retorno;
}

//--------------------------------------------------------------------------------//

int employee_setId2(eVendedor2* this,int id)
{

    int retorno = 0;

    if( this != NULL && id > 0)
    {

        this->id2 = id;
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
int employee_getId2(eVendedor2* this,int* id)
{

    int retorno = 0;

    if( this != NULL && id != NULL)
    {

        *id = this->id2;
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
int employee_setNombre2(eVendedor2* this,char* nombre)
{

    int retorno = 0;

    if(this != NULL && nombre != NULL && validarStringTam(nombre,128))
    {
        strcpy(this->nombre2, nombre);
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
int employee_getNombre2(eVendedor2* this,char* nombre)
{

    int retorno = 0;

    if( this != NULL && nombre != NULL )
    {

        strcpy(nombre, this->nombre2);
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
int employee_setNivel2(eVendedor2* this,int nivel)
{
    int retorno = 0;

    if(this != NULL)
    {
        this->nivel2 = nivel;
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
int employee_getNivel2(eVendedor2* this,int* nivel)
{
    int retorno = 0;

    if( this != NULL && nivel != NULL )
    {

        *nivel = this->nivel2;
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
int employee_setCantProd2(eVendedor2* this,int cant)
{
    int retorno = 0;

    if( this != NULL && cant > 0)
    {
        this->cantProdVend2 = cant;
        retorno = 1;
    }

    return retorno;

}


int employee_setMonto2(eVendedor2* this,float monto)
{
    int retorno = 0;

    if( this != NULL && monto > 0)
    {
        this->montoVendido2 = monto;
        retorno = 1;
    }

    return retorno;

}

int employee_setComision2(eVendedor2* this,float com)
{
    int retorno = 0;

    if( this != NULL && com > 0)
    {
        this->comision2 = com;
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
int employee_getCantProd2(eVendedor2* this,int* cant)
{
    int retorno = 0;

    if( this != NULL && cant != NULL )
    {

        *cant = this->cantProdVend2;
        retorno = 1;
    }
    return retorno;
}

int employee_getMonto2(eVendedor2* this,float* monto)
{
    int retorno = 0;

    if( this != NULL && monto != NULL )
    {

        *monto = this->montoVendido2;
        retorno = 1;
    }
    return retorno;
}

int employee_getComision2(eVendedor2* this,float* com)
{
    int retorno = 0;

    if( this != NULL && com != NULL )
    {

        *com = this->comision2;
        retorno = 1;
    }
    return retorno;
}


void mostrarEmpleado2(eVendedor* pEmp)
{
    int id;
    char nombre[128];
    int nivel;
    int cant;
    float monto;
    float com;

    if(pEmp !=NULL)
    {
        if(employee_getId(pEmp,&id) && employee_getNombre(pEmp,nombre) && employee_getNivel(pEmp,&nivel) && employee_getCantProd(pEmp,&cant) && employee_getMonto(pEmp,&monto) && employee_getComision(pEmp,&com))
        {
            printf("%5d %8s %6d %8d %.2f %.2f\n",id,nombre,nivel,cant,monto,com);
        }
    }
}

int listarEmpleados2(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int i=0;
    eVendedor* empleado;

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

        retorno = 1;

        for( i=0; i < ll_len(pArrayListEmployee); i++)
        {
            if(i%255==0)
            {
                system("pause");
                system("cls");
                printf("   Id   Nombre   Nivel   CantProd   MontoVend   Comision\n");
                printf("   --   ------   -----   --------   ---------   --------\n");
                empleado = (eVendedor*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }
            else
            {
                empleado = (eVendedor*)ll_get(pArrayListEmployee,i);
                mostrarEmpleado2(empleado);
            }

        }
    }

    system("pause");
    return retorno;
}
