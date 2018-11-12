#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "clientes.h"
#include "validaciones.h"
#include "juegos.h"
#include "alquileres.h"
#define TAM 10
#define ALQ 15

int main()
{
    char seguir = 's';

   eJuego juegos[5];
   eCategoria categorias[5];
   eCliente clientes[TAM];
   eAlquileres alquiler[ALQ];

   cargarJuegos(juegos,5,categorias,7);
   cargarCategoria(categorias,7);


   int idCodigo = 1;
   int idAlquiler = 1000;
   int flagCliente = 0;
   int flagAlquiler = 0;

   inicializarClientes(clientes,TAM);
   inicializarAlquiler(alquiler,ALQ);

    do
    {
        switch(menu())
        {
        case 1:
            altaCliente(clientes, TAM, &idCodigo);
            flagCliente = 1;
            break;
        case 2:
            if(flagCliente==1)
            {
            modificarCliente(clientes, TAM);
            }
            else
            {
            printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 3:
            if(flagCliente==1)
            {
            bajaCliente(clientes,TAM);
            }
            else
            {
            printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 4:
            if(flagCliente==1)
            {
            ordenarXNombreYsexo(clientes,TAM);
            }
            else
            {
            printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 5:
            if(flagAlquiler==1)
            {
            altaAlquiler(alquiler,ALQ,juegos,7,clientes,TAM,categorias,5,&idAlquiler,idCodigo);
            }
            else{
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 6:
            if(flagAlquiler==1)
            {
                mostrarAlquileres(alquiler,ALQ,juegos,7,clientes,TAM);
            }
            else
            {
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 7:
            if(flagAlquiler==1)
            {
              listarAlquileres(alquiler,ALQ,juegos,7,clientes,TAM);
            }
            else
            {
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 8:
            if(flagAlquiler==1)
            {
                subMenuInformar(alquiler,ALQ,juegos,7,clientes,TAM,categorias,5);
            }
            else
            {
                printf("Primero debe ingresar los datos");
            }
            system("pause");
            break;
        case 9:
            seguir='n';
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
