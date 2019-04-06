#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 10
#define ALQ 15

typedef struct
{
    int codigo;
    char nombre[51];
    char sexo;
    char telefono[51];
    char domicilio[51];
    int isEmpty;

} eCliente;

int menu();
void inicializarClientes(eCliente x[], int tam);
void mostrarCliente(eCliente);
void mostrarClientes(eCliente[],int);
int buscarLibre(eCliente x[], int tam);
int buscarCliente(eCliente x[], int tam, int codigo);
void altaCliente(eCliente*, int tam,int* pId);
void bajaCliente(eCliente x[], int tam);
int buscarClientexidCliente(eCliente x[], int tam, int codigo);
void modificarCliente(eCliente x[], int tam);
void ordenarXNombreYsexo(eCliente x[],int tam);

#endif // CLIENTES_H_INCLUDED
