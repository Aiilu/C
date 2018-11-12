#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"
#define TAM 10
#define ALQ 15

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int codAlquiler;
    int codJuego;
    int codCliente;
    eFecha fecha;
    int isEmpty;

} eAlquileres;

void inicializarAlquiler(eAlquileres x[], int tam);
int buscarLibreAlquiler(eAlquileres x[], int tam);
void mostrarAlquiler(eAlquileres unAlquiler, eJuego j[], int tamj, eCliente e[], int tame);
void mostrarAlquileres(eAlquileres a[], int tam, eJuego j[], int tamj, eCliente e[], int tame);
int buscarAlquiler(eAlquileres x[], int tam, int idAlquiler);
void altaAlquiler(eAlquileres* a, int tama, eJuego j[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca, int* pId, int idCodigo);
void listarAlquileres(eAlquileres a[], int tam, eJuego j[], int tamj, eCliente e[], int tame);

//INFORMES
void subMenuInformar(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca);
void informe1(eJuego ju[], int tamj, eCategoria c[], int tamc);
void mostrarJuegoMesa(eJuego juegosMesa);
void informe2(eAlquileres a[],int tama, eCliente c[], int tamc, eJuego ju[], int tamj);
void informe3(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc);
void informe4(eCliente c[], int tamc, eAlquileres a[], int tama);
void informe5(eAlquileres a[],int tama, eJuego ju[], int tamj, eCategoria c[], int tamc);
void informe6(eAlquileres a[], int tama, eCliente c[], int tam);
int compararFechas(eFecha fech, eFecha fecha);
void informe7(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca);
int esMujer(eCliente c[], int tamc, int codigo);
void informe8(eAlquileres a[], int tama, eJuego ju[], int tamj, eCliente c[], int tamc, eCategoria ca[], int tamca);
int esHombre(eCliente c[], int tamc, int codigo);
void informe9(eJuego ju[], int tamj, eCliente c[], int tamc, eAlquileres a[], int tama);
void informe10(eAlquileres a[], int tama, eJuego ju[], int tamj);

#endif // ALQUILERES_H_INCLUDED
