#include "validaciones.h"
#include "juegos.h"

/*
---------------------------------------------------------------------------------------------------------------------------------

                                              CATEGORIAS Y JUEGOS

--------------------------------------------------------------------------------------------------------------------------------
*/

void cargarCategoria(eCategoria c[], int tamc)
{
    int i;

    eCategoria categoria[]=
    {
        {1, "Juego de Mesa"},
        {2, "Juego de Azar"},
        {3, "Juego de Estrategia"},
        {4, "Juego de Salon"},
        {5, "Juego de Magia"}
    };

    for( i=0; i < tamc; i++)
    {
        c[i] = categoria[i];
    }
}

void cargarJuegos(eJuego j[], int tamj, eCategoria c[], int tamc)
{
    int i;

    eJuego juegos[]=
    {
        {1, "Ajedrez", 45,1},
        {2, "Truco", 50,1},
        {3, "Jenga", 130,2},
        {4, "Twister", 200,3},
        {5, "Escondidas", 100,4},
        {6, "TaTeTi",20,5},
        {7, "BuscandoAwally",100,5}

    };

    for( i=0; i < tamj ; i++)
    {
        j[i] = juegos[i];
    }
}

void listarCategorias(eCategoria c[], int tam)
{
    printf("\nLista de Categorias\n\n");

    int i;

    for( i=0; i < tam; i++)
    {
        printf(" %d  %10s\n",c[i].id, c[i].descripcion);
    }
    printf("\n\n");
}

void listarJuegos(eJuego j[], int tam)
{
    printf("\nLista de Juegos\n\n");

    int i;

    for( i=0; i < tam; i++)
    {
        fflush(stdin);
        if(j[i].codigo !=0)
        {
        printf(" %d  %10s  %d  %d\n",j[i].codigo, j[i].descripcion, j[i].importe, j[i].idCategoria);
        }
    }
    printf("\n\n");
}

void obtenerDescCategorias(eCategoria c[], int tamc, int idC, char* cadena)
{
    int i;

    for( i=0; i < tamc; i++)
    {
        if( c[i].id == idC)
        {
            strcpy(cadena, c[i].descripcion);
            break;
        }
    }
}

void obtenerDescJuegos(eJuego j[], int tamj, int idCateg, char* cadena)
{
    int i;
    for(i=0; i < tamj; i++)
    {
        if( j[i].idCategoria == idCateg)
        {
            strcpy(cadena, j[i].descripcion);
        }

    }
}

//NO FUNCA. TIRA EL MISMO JUEGO Y IMPORTE, NO COMPARA SEGUN EL JUEGO
void mostrarJuego(eJuego j[], eCategoria c[], int tamc)
{
  int i;
  char descripcion[20];

  for(i=0;i<tamc;i++)
    {
        if(j[i].idCategoria == c[i].id)
        {
            strcpy(descripcion,c[i].descripcion);
            break;
        }
    }

  printf("%d %s %d %s",j[i].codigo,j[i].descripcion,j[i].importe,descripcion);
}

/*
    FALTA ARREGLAR LA FUNCION MOSTRAR JUEGO, VERIFICAR SI LOS INFORMES ESTAN BIEN, QUE FUNCIONAN Y ARREGLAR LAS VALIDACIONES.
    PUTO CODEBLOCKS.
    REVISAR LISTAR ALQUILERES.

*/
