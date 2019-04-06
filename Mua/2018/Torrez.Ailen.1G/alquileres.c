#include "alquileres.h"
#include "validaciones.h"
#include "clientes.h"
#include "juegos.h"

/*
---------------------------------------------------------------------------------------------------------------------------------

                                              ALQUILERES

--------------------------------------------------------------------------------------------------------------------------------
*/

int buscarLibreAlquiler(eAlquileres x[], int tam)
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

void inicializarAlquiler(eAlquileres x[], int tam)
{
    int i;
    for( i=0; i < tam; i++)
    {
       x[i].isEmpty = 1;
    }
}

void mostrarAlquiler(eAlquileres unAlquiler, eJuego j[], int tamj, eCliente e[], int tame)
{
    char descJuego[20];
    int indice;
    eCliente client;
    obtenerDescJuegos(j,tamj,unAlquiler.codJuego,descJuego);
    indice = buscarCliente(e,tame,unAlquiler.codCliente);
    client = e[indice];
    printf("%4d %02d/%02d/%d %d %10s %10s\n", unAlquiler.codAlquiler, unAlquiler.fecha.dia, unAlquiler.fecha.mes, unAlquiler.fecha.anio, client.codigo, client.nombre, descJuego);
}

void mostrarAlquileres(eAlquileres a[], int tam, eJuego j[], int tamj, eCliente e[], int tame)
{

int flag = 0;
    int i;

    system("cls");
    printf("ID Alquiler  Fecha  ID Cliente  Nombre  Juego  Importe\n\n");


    for(i=0; i < tam; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlquiler(a[i],j,tamj,e,tame);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay nada que listar");
    }
    printf("\n\n");
}

void altaAlquiler(eAlquileres* a, int tama, eJuego j[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca, int* pId, int idCodigo)
{
    int idAlquiler = *pId;
    int idCliente;
    int idCategoria;
    char auxId[10];
    int auxCateg;
    //char auxDia[2];
    //char auxMes[2];
    //char auxAnio[4];
    eFecha fecha;
    eAlquileres nuevoAlquiler;
    int indice;

    indice = buscarLibreAlquiler(a, tama);

    if(indice == -1)
    {
        printf("No se pueden cargar mas alquileres\n\n");
    }
    else
    {
        nuevoAlquiler.codAlquiler = idAlquiler;

        mostrarClientes(c,tamc);


        while(!function_getStringNumeros("Ingrese idCliente: ",auxId))
    {
        printf("Error. Ingrese un Id numerico");
        break;
    }

    idCliente = atoi(auxId);

        //printf("Ingrese el cliente: ");
        //fflush(stdin);
        //scanf("%d", &idCliente);

        while(idCliente>idCodigo)
        {
        printf("Ingrese nuevamente solo el IdCliente: ");
        fflush(stdin);
        scanf("%d", &idCliente);
        }

        nuevoAlquiler.codCliente = idCliente;

        listarCategorias(ca,tamca);
        auxCateg =  function_getInt("Ingrese numero de Categoria: ");
        //printf("Ingrese numero de categoria: ");
        //scanf("%d", &idCategoria);

        nuevoAlquiler.codJuego = auxCateg;

        mostrarJuego(j,ca,tamc);

        printf("\nIngrese dia: ");
        scanf("%d", &fecha.dia);

        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);

        printf("Ingrese anio: ");
        scanf("%d", &fecha.anio);

        nuevoAlquiler.fecha = fecha;

        nuevoAlquiler.isEmpty = 0;

        a[indice] = nuevoAlquiler;

        *pId = idAlquiler + 1;
    }
}

int buscarAlquiler(eAlquileres x[], int tam, int idAlquiler)
{
    int indice = -1;
    int i;
    for(i=0; i < tam; i++)
    {
        if( x[i].codAlquiler == idAlquiler && x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void listarAlquileres(eAlquileres a[], int tam, eJuego j[], int tamj, eCliente e[], int tame)
{
    int flag = 0;
    int i;

    system("cls");
    printf("ID Alquiler  Fecha  ID Cliente  Nombre  Juego  Importe\n\n");


    for(i=0; i < tam; i++)
    {
        if( a[i].isEmpty == 0)
        {
            mostrarAlquiler(a[i],j,tamj,e,tame);
            flag = 1;
        }

   }

    if(flag == 0)
    {
        printf("No hay nada que listar");
    }
    printf("\n\n");
}

/*
---------------------------------------------------------------------------------------------------------------------------------

                                              INFORMES

--------------------------------------------------------------------------------------------------------------------------------
*/

void subMenuInformar(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca)
{
    int opcion;

    do
    {
       int flagInf = 0;

        system("cls");
        printf("              ******************************************************************\n");
        printf("              *                         INFORMES                               *\n");
        printf("              ******************************************************************\n");
        printf("              *                                                                *\n");
        printf("              *       1) JUEGOS CATEGORIA MESA                                 *\n");
        printf("              *       2)ALQUILERES EFECTUADOS DE UN CLIENTE                    *\n");
        printf("              *       3)IMPORTES PAGADOS POR UN CLIENTE                        *\n");
        printf("              *       4)CLIENTES QUE NO ALQUILARON JUEGOS                      *\n");
        printf("              *       5)JUEGOS NO ALQUILADOS                                   *\n");
        printf("              *       6)TELEFONOS DE CLIENTES QUE ALQUILARON EN UNA FECHA      *\n");
        printf("              *       7)JUEGOS ALQUILADOS POR MUJERES                          *\n");
        printf("              *       8)JUEGOS MAS ALQUILADOS POR HOMBRES                      *\n");
        printf("              *       9)CLIENTES QUE ALQUILARON UN DETERMINADO JUEGO           *\n");
        printf("              *       10)RECAUDACION DE UNA FECHA EN PARTICULAR                *\n");
        printf("              *                                                                *\n");
        printf("              ******************************************************************\n");

    printf(" Ingrese opcion: ");
    scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            informe1(ju,tamj,ca,tamca);
            flagInf = 1;
            break;
        case 2:
            system("cls");
            if(flagInf == 1)
            {
                informe2(a,tama,c,tamc,ju,tamj);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(flagInf == 0)
            {
                informe3(a,tama,ju,tamj,c,tamc);
            }
            else
            {
                printf("Primero se deben cargar los datos");
            }
            system("pause");
            break;
        case 4:
            system("cls");
              if(flagInf == 1)
            {
                informe4(c,tamc,a,tama);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(flagInf == 1)
            {
                informe5(a,tama,ju,tamj,ca,tamca);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(flagInf == 1)
            {
                informe6(a,tama,c,tamc);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(flagInf == 1)
            {
                informe7(a,tama,ju,tamj,c,tamc,ca,tamca);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 8:
            system("cls");
            if(flagInf == 1)
            {
                informe8(a,tama,ju,tamj,c,tamc,ca,tamca);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            if(flagInf == 1)
            {
                informe9(ju,tamj,c,tamc,a,tama);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            if(flagInf == 1)
            {
                informe10(a,tama,ju,tamj);
            }
            else
            {
                printf("Primero deben cargar los datos");
            }
            system("pause");
            break;
        case 11:
            break;
        default:
            printf("No es una opcion valida");
        }
    }
    while(opcion!=11);
}

//MOSTRAR JUEGOS DE CATEGORIA MESA
void informe1(eJuego ju[], int tamj, eCategoria c[], int tamc)
{
  int i;
  int j;

  for(i=0;i<tamc;i++)
  {
      for(j=0;j<tamj;j++)
      {
          if(ju[j].idCategoria == c[i].id)
          {
              mostrarJuegoMesa(ju[j]);
          }
      }
  }
}

void mostrarJuegoMesa(eJuego juegosMesa)
{
    printf("Juegos categoria mesa: %d, descripcion: %s, importe: %d, de la categoria: %d",juegosMesa.codigo,juegosMesa.descripcion,juegosMesa.importe,juegosMesa.idCategoria);
}

//MOSTRAR ALQUILERES EFECTUADOS X ALGUN CLIENTE
void informe2(eAlquileres a[],int tama, eCliente c[], int tamc, eJuego ju[], int tamj)
{
    int i;
    int j;
    int codigo;
    char auxId[10];

    for(i=0;i<tamc;i++)
    {
        mostrarCliente(c[i]);
    }

    //printf("Ingrese el codigo del empleado a buscar: ");
    //scanf("%d",&codigo);

    while(!function_getStringNumeros("Ingrese idCliente a buscar: ",auxId))
    {
        printf("Error. Ingrese un Id numerico");
        break;
    }

    codigo = atoi(auxId);

    for(j=0;j<tama;j++)
    {
        if(c[i].codigo == a[j].codCliente)
        {
            mostrarAlquiler(a[j],ju,tamj,c,tamc);
        }
    }
}

//MOSTRAR EL TOTAL DE TODOS LOS IMPORTES PAGADOS POR UN CLIENTE
void informe3(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc)
{
    int total = 0;
    int i;
    int j;
    int codigo;
    char auxId[10];

    for(i=0;i<tamc;i++)
    {
        mostrarCliente(c[i]);
    }

    //printf("Ingrese el codigo del cliente: ");
    //scanf("%d",&codigo);

    while(!function_getStringNumeros("Ingrese idCliente a buscar: ",auxId))
    {
        printf("Error. Ingrese un Id numerico");
        break;
    }

    codigo = atoi(auxId);

    for(i=0;i<tama;i++)
    {
        if(a[i].codCliente == codigo)
        {
            for(j=0;j<tamj;j++)
            {
                if(ju[j].codigo == a[i].codJuego)
                {
                  total+= ju[j].importe;
                  break;
                }
            }

        }
    }

    printf("Importe total: %d", total);
    system("pause");
}

//LISTAR LOS CLIENTES QUE NO ALQUILARON
void informe4(eCliente c[], int tamc, eAlquileres a[], int tama)
{
    int i;
    int j;
    int flag = 0;
    int flag2 = 0;

    for(i=0;i<tamc;i++)
    {
        flag = 0;

        for(j=0;j<tama;j++)
        {
            if(c[i].codigo == a[j].codCliente)
            {
                flag = 1;
                break;
            }
        }

        if(flag==0)
        {
            mostrarCliente(c[i]);
            flag2 = 1;
        }

        if(flag2 == 0)
        {
            printf("Todos los clientes alquilaron");
        }
    }

}

//LISTAR LOS JUEGOS NO ALQUILADOS
void informe5(eAlquileres a[],int tama, eJuego ju[], int tamj, eCategoria c[], int tamc)
{
    int i;
    int j;
    int flag=0;
    int flag2=0;

    for(i=0;i<tamj;i++)
    {
        flag = 0;

        for(j=0;j<tama;j++)
        {
            if(ju[i].codigo == a[j].codJuego)
            {
                flag=1;
                break;
            }
        }

        if(flag == 0)
        {
          mostrarJuego(ju,c,tamc);
          flag2=1;
        }

        if(flag2 == 0)
        {
            printf("Todos los juegos fueron alquilados");
        }

    }
}

//LISTAR TELEFONOS DE UN CLIENTE QUE  ALQUILO EN DETERMINADA FECHA
void informe6(eAlquileres a[], int tama, eCliente c[], int tam)
{
    eFecha fecha;
    int i;
    int j;
    int flag=0;

    printf("Ingrese la fecha a buscar");
    printf("dd/mm/aaaa: ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(i=0;i<tama;i++)
    {
        if(compararFechas(a[i].fecha,fecha))
        {
           for(j=0;j<tam;j++)
           {
               if(a[i].codCliente == c[j].codigo)
               {
                   printf("Telefono: %10s", c[j].telefono);

                   flag = 1;
                   break;
               }
           }
        }
    }

    if(flag==0)
    {
        printf("No tenemos alquileres en esta fecha");
        system("pause");
    }
}

int compararFechas(eFecha fech, eFecha fecha)
{
    int Igual=0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        Igual = 1;
    }

    return Igual;
}

//LISTAR JUEGOS ALQUILADOS  POR MUJERES
void informe7(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca)
{
    int i;
    int j;

  for(i=0;i<tamj;i++)
  {

      for(i=0;i<tama;i++)
      {
          if(esMujer(c,tamc, a[i].codCliente))
          {
               for(j=0;j<tamj;j++)
              {
                   if(a[i].codJuego == ju[j].codigo)
                   {
                     mostrarJuego(ju,ca,tamca);
                   }
              }
          }
      }

  }

}

int esMujer(eCliente c[], int tamc, int codigo)
{
    int mujer = 0;
    int i;

    for(i=0;i<tamc;i++)
    {
        if(c[i].codigo == codigo)
        {
            if(c[i].sexo == 'F' || c[i].sexo  == 'f')
            {
                mujer = 1;
            }
        }
    }
    return mujer;
}

//MOSTRAR LOS JUEGOS MAS ALQUILADOS POR HOMBRES
void informe8(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca)
{
    int cont[tamj];
    int mayor;
    int i;
    int j;

    for(i=0;i<tamj;i++)
    {
        cont[i]=0;
    }

    for(i=0;i<tama;i++)
    {
        if(esHombre(c,tamc, a[i].codCliente))
        {
            for(j=0;j<tamj;j++)
            {
                if(a[i].codJuego == ju[j].codigo)
                {
                    cont[j]++;
                }
            }
        }
    }

    mayor = cont[0];

    for(i=0; i<tamj;i++)
    {
        if(cont[i] > mayor)
        {
            mayor = cont[i];
        }
    }

    printf("Cantidad de alquileres: %d", mayor);

    for(i=1; i<tamj; i++)
    {
        if(cont[i] == mayor)
        {
            mostrarJuego(ju,ca,tamca);
        }
    }

    system("pause");
}

int esHombre(eCliente c[], int tamc, int codigo)
{
    int hombre  = 0;
    int i;

    for(i=0;i<tamc;i++)
    {
        if(c[i].codigo == codigo)
        {
            if(c[i].sexo == 'M' || c[i].sexo  == 'm')
            {
                hombre = 1;
            }
        }
    }
    return hombre;
}

//LISTAR CLIENTES QUE ALQUILARON UN DETERMINADO JUEGO
void informe9(eJuego ju[], int tamj, eCliente c[], int tamc, eAlquileres a[], int tama)
{
    int i;
    int j;
    int id;
    char auxCateg[10];

    listarJuegos(ju,tamj);

    //printf("Ingrese el codigo del juego: ");
    //scanf("%d",&id);

    while(!function_getStringNumeros("Ingrese codigo de la categoria a buscar: ",auxCateg))
    {
        printf("Error. Ingrese un Id numerico");
        break;
    }

    id = atoi(auxCateg);

    printf("Clientes que alquilaron este juego: ");

    for(i=0;i<tama;i++)
    {
        if(id == a[i].codJuego)
        {
            for(j=0;j<tamc;j++)
            {
                if(a[i].codCliente == c[j].codigo)
                {
                    mostrarCliente(c[j]);
                }
            }
        }
    }
}

//MOSTRAR LA RECUDACION DE UNA FECHHA  EN  PARTICULAR
void informe10(eAlquileres a[], int tama, eJuego ju[], int tamj)
{
    eFecha fecha;
    int i;
    int j;
    int flag = 0;
    int importe = 0;

    printf("Ingrese la fecha a buscar");
    printf("dd/mm/aaaa: ");
    scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

    for(i=0;i<tama;i++)
    {
        if(compararFechas(a[i].fecha,fecha))
        {
           for(j=0;j<tamj;j++)
           {
               if(a[i].codJuego == ju[j].codigo)
               {
                   importe+=ju[j].importe;
                   flag = 1;
                   break;
               }
           }
        }
    }

    printf("La recaudacion de esta fecha es: %d ", importe);

    if(flag==0)
    {
        printf("No tenemos ninguna recaudacion en esta fecha");
        system("pause");
    }
}
