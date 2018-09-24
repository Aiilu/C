#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "legajo.h"

sAlumno cargarUnAlumno()
{
    sAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.legajos);
    fflush(stdin);

    printf("Ingrese nombre: ");
    scanf("%s",miAlumno.nombres);
    fflush(stdin);

    printf("Ingrese la nota: ");
    scanf("%d",&miAlumno.notas);
    if(miAlumno.notas>10 || miAlumno.notas<0)
    {
        printf("Reingrese una nota valida: ");
        scanf("%d",&miAlumno.notas);
    }
    fflush(stdin);

    printf("Ingrese la altura: ");
    scanf("%f",&miAlumno.alturas);
    fflush(stdin);

    return miAlumno;
}

void mostrarUnAlumno(sAlumno unAlumno)
{
    printf("%4d %20s %2f %5d\n",unAlumno.legajos,unAlumno.nombres,unAlumno.alturas,unAlumno.notas);
}

void cargarAlumnos(sAlumno listado[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {

        listado[i] = cargarUnAlumno();
    }
}

void mostrarAlumnos(sAlumno listado[],int tam)
{
    int i;

    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");

    for(i=0; i<tam; i++)
    {
        mostrarUnAlumno(listado[i]);
    }
}

void ordenarAlfabeticamente(sAlumno listado[],int tam)
{

    int i;
    int j;

    sAlumno auxAlumno;

    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombres,listado[j].nombres)>0)//criterio ordenamiento
            {
                auxAlumno=listado[i];
                listado[i]=listado[j];
                listado[j]=auxAlumno;
            }
            for(i=0; i<tam; i++)
            {
                mostrarUnAlumno(listado[i]);
            }
        }
    }

}

void alumnosAprobados (sAlumno listas[],int tam)
{
    int i;
    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");
    for (i=0; i<tam; i++)
    {
        if(listas[i].notas>=6)
        {
            mostrarUnAlumno(listas[i]);

        }
    }
}

void alumnosDesaprobados(sAlumno listas[],int tam)
{
    int i;

    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");

    for(i=0; i<tam; i++)
    {
        if(listas[i].notas<6)
        {
            mostrarUnAlumno(listas[i]);
        }
    }

}


void alumnoLlamadoJuan(sAlumno listas[],int tam)
{

    int i;
    int contadorJuan=0;

    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");
    for (i=0; i<tam; i++)
    {
        //scanf("%s",listas[i].nombres);
        if(strcmp(listas[i].nombres,"Juan")==0)
        {
            mostrarUnAlumno(listas[i]);
            contadorJuan++;
        }
    }
    if (contadorJuan==0)
    {
        printf("No hay ningun Juan registrado");
    }
}

void validarNombreConP(sAlumno listas[],int tam)
{
    int alumnosConP=0;
    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");
    for(int i=0; i<tam; i++)
    {
        if(listas[i].nombres[0]=='p' || listas[i].nombres[0]=='P' )
        {
            mostrarUnAlumno(listas[i]);
        }
        if(alumnosConP==0)
        {
            printf("No hay ningun nombre con P registrado");
        }
    }
}

void notasMaximas(sAlumno listas[], int tam)
{
    int maxNota=0;
    int i;
    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");
    for(i = 0; i < tam; i++)
    {
        if (i==0)
        {
            maxNota=listas[i].notas;
        }
        if (listas[i].notas > maxNota)
        {
            maxNota = listas[i].notas;
        }
    }

    for(i = 0; i < tam; i++)
    {
        if(listas[i].notas == maxNota)
        {
            mostrarUnAlumno(listas[i]);
        }
    }
}

void alumnoMasMediocre(sAlumno listas[], int tam)
{
    int i;
    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Altura","Nota");

    for(i=0; i<tam; i++)
    {
        if( listas[i].legajos==100 && strcmp(listas[i].nombres, "Pepe")==0 && listas[i].notas==5 && listas[i].alturas==1.75)
        {
            mostrarUnAlumno(listas[i]);
        }
    }
}
void modificarListado(sAlumno listas[],int tam)
{
    int i;
    int legajo;
    char opcion;
    int auxnota;
    mostrarAlumnos(listas,tam);
    printf("Ingrese legajo a buscar: ");
    scanf("%d",&legajo);
    for(i=0; i<tam; i++)
    {
        if(legajo == listas[i].legajos)
        {
            //mostrar un alumno
            mostrarUnAlumno(listas[i]);

            //pedir nueva nota
            printf("Nueva nota:");
            scanf("%d", &auxnota);
            //    scanf("%d",&(listas[i].notas));

            printf("Esta seguro de querer cambiar");
            opcion=getch();
            if(opcion == 's')
            {
                listas[i].notas=auxnota;
                printf("\n\nDatos actualizados exitosamente!");
            }
            else
            {
                printf("No se ha completado la operacion");
            }
        }
    }
}

void alumnosMinimoPromedio(sAlumno listas[],int tam)
{
    int i;
    float prom;
    int cont=0;
    int acum=0;
    for(i=0; i<tam; i++)
    {
        cont ++;
        acum+=listas[i].notas;

    }
    prom = acum/cont;
    if(prom<6)
    {
        mostrarUnAlumno(listas[i]);
    }
}
void alumnosMaximoPromedio(sAlumno listas[],int tam)
{
    int i;
    float prom;
    int cont=0;
    int acum=0;
    for (i=0; i<tam; i++)
    {
        cont ++;
        acum+=listas[i].notas;
    }
    prom = acum/cont;

    if(prom>6)
    {
        mostrarUnAlumno(listas[i]);
    }
}
void alumnosPromSeis(sAlumno listas[],int tam)
{
    int i;
    float prom;
    int acum=0;
    int cont=0;
    for (i=0; i<tam; i++)
    {
        cont ++;
        acum+=listas[i].notas;
    }
    prom = acum/cont;
    if(prom == 6)
    {
        mostrarUnAlumno(listas[i]);
    }
}

/*porcentAlumAprobDesap(sAlumno listas[], int tam)
{
int i;
int aprobados =0;
int desaprobados =0;
int cont=0;
float aprobados, desaprobados;
for(i=0;i<tam;i++)
{
if(listas[i].notas<=)
{
aprobados ++
}
else
{
desaprobados ++;
}
}
}*/
