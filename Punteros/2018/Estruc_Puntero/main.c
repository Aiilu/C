#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int dia;
int mes;
int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    eFecha fecha;

}eEmpleado;


int main()
{

eEmpleado unEmpleado;

eEmpleado* pUnEmpleado;

pUnEmpleado = &unEmpleado;

cargarUnEmpleado(pUnEmpleado);


    return 0;
}

//Hacerlo hardcodeado y sin hardcodear

void cargarUnEmpleado(eEmpleado *pUnEmpleado)
{
    printf("Ingrese el nombre del empleado: \n");
    scanf("%s",&pUnEmpleado->nombre);

}
