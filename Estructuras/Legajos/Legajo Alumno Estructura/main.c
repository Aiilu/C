#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "legajo.h"
#define T 2

int main()
{
    sAlumno listadoAlumnos[T];
    cargarIlogico(listadoAlumnos,T);
    menuOpcion(listadoAlumnos,T);

    return 0;
}

