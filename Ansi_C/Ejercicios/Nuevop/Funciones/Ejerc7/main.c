#include <stdio.h>
#include <stdlib.h>
#define T 3

int main()
{
    char apellido[];
    int notas[];
    float promedio;

    return 0;
}

float promed(int notas[], int tam)
{
    float prom;
    int i;
    int acum = 0;
    int cont = 0;

    for(i=0;i<tam;i++)
    {
        if(notas[i]>6)
        {
            acum+=notas[i];
            cont ++;
        }
    }

    prom = (float)acum/cont;

    return prom;
}

void mostrarAprobados(char nombres[][21],char apellidos[][21],int notas[], int tam)
{
    int i;

    printf("%35s \n","Alumnos Aprobados");

    for(i=0; i<tam; i++)
    {
        if(notas[i]>6)
        {
        printf("%11s %11s %13d \n", nombres[i], apellidos[i], notas[i]);
        }
    }
}

/*7- Realizar un programa que permita calcular el promedio de las 30 notas de un alumno
y las muestre en pantalla con el siguiente formato
Apellido Promedio
XXXX ##,##
Los datos a ingresar son, el nombre y apellido y las 30 notas.
No se sabe la cantidad de alumnos a ingresar, por ello se deberá mostrar en pantalla el mensaje Continúa S/N?
Para resolver el problema usar alguna de las funciones desarrolladas en problemas anteriores.*/
