#include "validaciones.h"
#include "clientes.h"
#include "alquileres.h"

int menu()
{
    int opcion;

    system("cls");
        printf("              **********************************************\n");
        printf("              *            MENU  OPCIONES                  *\n");
        printf("              **********************************************\n");
        printf("              *                                             \n");
        printf("              *              1)ALTAS                       *\n");
        printf("              *              2)MODIFICAR                   *\n");
        printf("              *              3)BAJA                        *\n");
        printf("              *              4)LISTAR X NOMBRE/SEXO         \n");
        printf("              *              5)DAR DE ALTA ALQUILER        *\n");
        printf("              *              6)INFORMAR ALQUILERES         *\n");
        printf("              *              7)LISTAR ALQUILERES           *\n");
        printf("              *              8)INFORMES                    *\n");
        printf("              *              9)SALIR                       *\n");
        printf("              *                                             \n");
        printf("              **********************************************\n");

    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void inicializarClientes(eCliente x[], int tam)
{
     int i;
    for(i=0; i < tam; i++)
    {

        x[i].isEmpty = 1;
    }
}

void mostrarCliente(eCliente unCliente)
{
    if(unCliente.isEmpty == 0)
    {
    printf("%4d %10s   %2c   %5s %10s\n", unCliente.codigo, unCliente.nombre, unCliente.sexo, unCliente.telefono,unCliente.domicilio);
    }
}

void mostrarClientes(eCliente x[], int tam)
{
    int i;

    system("cls");
    printf(("idCliente  Nombre  Sexo  Telefono  Domicilio\n\n"));
    for(i=0; i< tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
            mostrarCliente(x[i]);
        }
    }
}


int buscarLibre(eCliente x[], int tam)
{
    int indice = -1;
int i;
    for( i=0; i < tam; i++)
    {

        if( x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarCliente(eCliente x[], int tam, int codigo)
{
    int indice = -1;
int i;
    for( i=0; i < tam; i++)
    {

        if( x[i].codigo == codigo && x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

void altaCliente(eCliente* x , int tam, int* pId)
{
    int indice;
	int idCodigo = *pId;
	char auxName[51];
    char auxChar[10];
    char auxTel[30];
    char auxDomicilio[30];

    eCliente nuevoCliente;

    indice = buscarLibre(x, tam);

    system("cls");
    printf("*** Alta Cliente ***\n\n");

    if( indice == -1)
    {

        printf("No hay lugar en el sistema\n\n");
        system("pause");
    }
        else
        {
            nuevoCliente.codigo = idCodigo;


            while(!function_getStringLetras("Ingrese el nombre del cliente: \n",auxName))
            {
                printf("Recuerde, el nombre solo debe tener letras.\n");
            }

            while(!function_ValidaSexo("Ingrese el sexo del cliente: \n",auxChar))
            {
                printf("Recuerde, ingresar el sexo como m o f\n");
            }

            while(!function_esTelefono("Ingrese el telefono del cliente: \n",auxTel))
            {
                printf("Recuerde, el telefono solo debe tener letras.\n");
            }

            while(!function_getStringLetras("Ingrese el sexo del cliente: \n",auxDomicilio))
            {
                printf("Recuerde, ingresar el sexo como m o f\n");
            }

            /*printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoCliente.nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoCliente.sexo);

            printf("Ingrese Telefono: ");
            fflush(stdin);
            gets(nuevoCliente.telefono);

            printf("Ingrese Domicilio: ");
            gets(nuevoCliente.domicilio);*/

            fflush(stdin);
            strcpy(nuevoCliente.telefono,auxTel);
            strcpy(nuevoCliente.nombre,auxName);
            strcpy(nuevoCliente.sexo,auxChar);
            strcpy(nuevoCliente.domicilio,auxDomicilio);

            *pId = idCodigo + 1;
            nuevoCliente.isEmpty = 0;
            x[indice] = nuevoCliente;

            printf("Cliente cargado con exito!!\n");
            system("pause");

        }
}

void bajaCliente(eCliente x[], int tam)
{

    int codigo;
    char auxId[10];
    int indice;
    char seguir;

    system("cls");
    printf("  *** Baja Cliente ***\n\n");

    printf(("idCliente   apellido  Nombre  Domicilio  Telefono\n\n"));
    mostrarClientes(x,tam);

    while(!function_getStringNumeros("Ingrese idCliente: ",auxId))
    {
        printf("Error. Ingrese un Id numerico");
        break;
    }

    codigo =atoi(auxId);

    //printf("Ingrese idCliente: ");
    //scanf("%d", &codigo);

     indice = buscarClientexidCliente(x,tam,codigo);

     if( indice == -1)
    {
        //printf("No hay ningun Cliente con el codigo %d\n", codigo);
        printf("No hay ningun Cliente con este codigo");
        system("pause");
    }
    else
    {
        mostrarCliente(x[indice]);

        printf("\nConfima borrado s/n: ");
        fflush(stdin);
        scanf("%c", &seguir);

        if(seguir == 'n')
        {
            printf("Baja cancelada\n\n");

        }
        else

        {

            x[indice].isEmpty = 1;
            printf("Borrado exitoso\n\n");
        }
        system("pause");
    }

}

int buscarClientexidCliente(eCliente x[], int tam, int codigo)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {

        if( x[i].codigo == codigo && x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarCliente(eCliente x[], int tam)
{
    int indice;
    int codigo;
    char modificar;
    int opcion;
    char auxName[21];
    char auxId[10];
    char auxSex[2];
    char auxTel[21];
    char auxDomicilio[21];
    char auxOpcion[10];

    mostrarClientes(x,tam);

    while(!function_getStringNumeros("Ingrese idCliente: ", auxId))
    {
        printf("Error. Ingrese un ID numerico");
        break;
    }

    codigo = atoi(auxId);

    //printf("Ingrese idCliente: ");
    //scanf("%d", &codigo);

    indice = buscarClientexidCliente(x, tam,codigo);

    if( indice == -1)
    {
        printf("No hay ningun Cliente con el idCliente %d\n", codigo);
    }
    else
    {
        mostrarCliente(x[indice]);
        fflush(stdin);

        while(!function_getStringNumeros("Que desea modificar? \t 1-Nombre. \t 2-Domicilio. \t 3-Telefono. ", auxOpcion))
        {
            printf("Error. Ingrese una opcion numerica del 1 al 3\n");
            system("pause");
            fflush(stdin);
        }

        opcion = atoi(auxOpcion);

        if(opcion<=1 || opcion >=3)
        {
            printf("Error. Ingrese una opcion del 1 al 3\n");
            fflush(stdin);
        }
        //printf("Que desea modificar? \t 1-Nombre. \t 2-Domicilio. \t 3-Telefono. ");
        //fflush(stdin);
        //scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:

            printf("\nModifica nombre?: ");
            fflush(stdin);

            scanf("%c", &modificar);
            modificar=tolower(modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                while(!function_getStringLetras("Ingrese el nombre: \n",auxName))
                {
                    printf("Error. El nombre debe tener letras\n");
                }
                fflush(stdin);
                strcpy(x[indice].nombre,auxName);
                printf("Nombre modificado con exito");

            }
            system("pause");
            break;
        case 2:
            printf("\nModifica domicilio?: ");
            fflush(stdin);
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                while(!function_getStringLetras("Ingrese el domicilio: \n",auxDomicilio))
                {
                    printf("Error. El domicilio debe tener letras\n");
                }
                fflush(stdin);
                strcpy(x[indice].domicilio,auxDomicilio);
                printf("Domicilio modificado con exito");
            }
                system("pause");
                break;
        case 3:
            printf("\nModifica telefono?: ");
            fflush(stdin);
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }
            else
            {
                while(!function_getStringNumeros("Ingrese el telefono: \n",auxTel))
                {
                    printf("Error. El telefono debe tener numeros\n");
                }
                fflush(stdin);
                strcpy(x[indice].telefono,auxTel);
                printf("Telefono modificado con exito");
            }
                system("pause");
                break;

        default:
            printf("No ha ingresado una opcion valida");
            break;
        }

        system("pause");
    }
}

void ordenarXNombreYsexo(eCliente x[],int tam)
{
    int i, j;
    eCliente auxCliente;

    printf(("idCliente  Nombre  Sexo  Telefono  Domicilio\n\n"));

    for(i=0; i<tam -1; i++)
    {
        for(j = i +1; j < tam; j++)
        {
            if(strcmp(x[i].nombre, x[j].nombre)==0)
            {
                if(x[i].sexo-x[j].sexo==0)
                {
                    auxCliente=x[i];
                    x[i]=x[j];
                    x[j]=auxCliente;
                }
            }
		else if (strcmp(x[i].nombre, x[j].nombre)>0)
            {
                auxCliente=x[i];
                x[i]=x[j];
                x[j]=auxCliente;
            }
    }
        }


    for (i=0; i<tam; i++)
    {
        if(x[i].isEmpty == 0)
        {
        mostrarCliente(x[i]);
        }
    }
}
