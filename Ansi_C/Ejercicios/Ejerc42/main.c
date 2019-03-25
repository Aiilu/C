#include <stdio.h>
#include <stdlib.h>
#define A 2

typedef struct
{
    char nombre[30];
    char apellido[50];
    float altura;
}eAlumno;
eAlumno ingresoAlumno();
void cargarListadoAlumnos();
void buscoAlumno();
void imprimoAlumno(int,int,int);


int main()
{
    eAlumno alumno[A];
    float alturaMayor;
    int posicion;

    cargarListadoAlumnos(alumno,A);
    buscoAlumno(alumno,A,posicion,alturaMayor);
    imprimoAlumno(alumno);

    return 0;
}

eAlumno ingresoAlumno()
{
    eAlumno alum;

    printf("Ingrese nombre del alumno: ");
    scanf("%s",alum.nombre);

    printf("Ingrese apellido del alumno: ");
    scanf("%s",alum.apellido);

    printf("Ingrese altura del alumno: ");
    scanf("%f",&alum.altura);

    return alum;
}

void cargarListadoAlumnos(eAlumno list[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        list[i]=ingresoAlumno();
    }
}

void buscoAlumno(eAlumno list[],int tam, int pos, int alturaMayor)
{
    int i;
    for ( i = 0; i < tam; i++){
        if ( list.altura[i] > 0){
            if (list.altura[i] > list.altura[i-1]){
                alturaMayor = list.altura[i];
                pos = i;
            }
        }
    }
}

void imprimoAlumno(eAlumno list[])
{
    printf("\nEl alumno con mayor altura es:%s %s.\nCon una altura de: %2.f ",list.nombre, list.apellido, list.altura);
}
/*De los alumnos de una escuela se registra su apellido y nombre y su altura. Diseñar en un programa que
indique el nombre del alumno más alto y su altura (sólo uno es el más alto)*/
