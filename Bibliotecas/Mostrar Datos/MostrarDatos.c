
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MostrarDatos.h"


void mostrarEntero(int entero)

{
    printf("\n %d ", entero);
}

void mostrarflotante(float flotante)

{
    printf("\n %.2f ", flotante);
}

void mostrarCaracter(char character)

{
    printf("\n %c ", character);
}

void mostrarString(char strings[])

{
    printf("\n %s ", strings);
}
