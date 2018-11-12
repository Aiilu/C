#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define TAM 10
#define ALQ 15

typedef struct
{
    int id;
    char descripcion[20];

} eCategoria;

typedef struct
{
    int codigo;
    char descripcion[51];
    int importe;
    int idCategoria;

} eJuego;

void obtenerDescJuegos(eJuego j[], int tamj, int idCateg, char* cadena);
void obtenerDescCategorias(eCategoria c[], int tamc, int idC, char* cadena);
void cargarJuegos(eJuego j[], int tamj, eCategoria c[], int tamc);
void listarJuegos(eJuego j[], int tam);
void cargarCategoria(eCategoria c[], int tamc);
void listarCategorias(eCategoria c[], int tam);
int buscarIdCategoria(eCategoria x[], int tamc, int idCategoria);
void mostrarJuego(eJuego j[], eCategoria c[], int tamc);

#endif // JUEGOS_H_INCLUDED
