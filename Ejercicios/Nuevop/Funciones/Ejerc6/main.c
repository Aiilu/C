#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 8

void mostrarAlumnos(char nombres[][21],char apellidos[][21],int notas[], int legajos[], int tam);
float promed(int notas[], int tam);
void mostrarAprobados(char nombres[][21],char apellidos[][21],int notas[], int tam);

int main()
{
    char nombre[T][21]={"Ailen","Caro","Mauro","Agus","Lucas","Chris","Fede","Brian"};
    char apellido[T][21]={"Torrez","Lopez","Campos","Ferrero","Braziulis","Brizuela","Bertoglio","Villan"};
    int nota[T]={10,9,10,5,6,7,8,4};
    int legajo[T]={1,2,3,4,5,6,7,8};
    float promedio;

   /* for(i=0;i<T;i++)
    {
        printf("Ingrese el nombre del alumno: ");
        gets(nombre[i]);

        printf("Ingrese el apellido del alumno: ");
        gets(apellido[i]);

        printf("Ingrese la nota del alumno: ");
        scanf("%d",&nota);

        printf("Ingrese el legajo del alumno: ");
        scanf("%f",&legajo);
    }*/

    mostrarAlumnos(nombre,apellido,nota,legajo,T);

    promedio = promed(nota,T);
    printf("Promedio: %.2f",promedio);

    mostrarAprobados(nombre,apellido,nota,T);

    return 0;
}

void mostrarAlumnos(char nombres[][21],char apellidos[][21],int notas[], int legajos[], int tam)
{
    int i;

    printf("%4s %10s %13s %5s\n","Legajo","Nombre","Apellido","Nota");

    for(i=0; i<tam; i++)
    {
        printf("%4d %11s %13s %5d\n", legajos[i], nombres[i], apellidos[i],notas[i]);
    }
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

/*6- Se desean obtener determinados datos de un examen.
Para ello se carga el nombre y apellido, la nota y el legajo de 25 alumnos. Se pide:
 Calcular el porcentaje de aprobados usando una función.
 Por medio de una función mostrar el nombre y apellido y la nota de los que aprobaron*/
