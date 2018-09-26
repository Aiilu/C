#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "legajo.h"

sAlumno cargarUnAlumno()
{
    sAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d",&miAlumno.legajos);
    if(miAlumno.legajos>9999 || miAlumno.legajos<0)
    {
        printf("Reingrese un legajo valido: ");
        scanf("%d",&miAlumno.legajos);
    }
    fflush(stdin);

    printf("Ingrese nombre: ");
    scanf("%s",miAlumno.nombres);
    if((miAlumno.nombres < 'a' || miAlumno.nombres > 'z' ) && (miAlumno.nombres > 'A' || miAlumno.nombres<'Z'))
    {
        printf("Reingese un nombre valido: ");
        scanf("%s",miAlumno.nombres);
    }
    fflush(stdin);

    printf("Ingrese la nota: ");
    scanf("%d",&miAlumno.notas);
    if(miAlumno.notas>10 || miAlumno.notas<0)
    {
        printf("Reingrese una nota valida: ");
        scanf("%d",&miAlumno.notas);
    }

    printf("Ingrese la altura: "); //validar solo numeros
    scanf("%f",&miAlumno.alturas);
    miAlumno.alturas=isdigit(miAlumno.alturas);  //GUARDA DOS VECES
    if(miAlumno.alturas==0)
    {
        printf("Ingrese una altura valida: ");
        scanf("%f",&miAlumno.alturas);
        miAlumno.alturas=isdigit(miAlumno.alturas);
    }
    fflush(stdin);

     printf("Ingrese sexo. F o M");
    scanf("%c",&miAlumno.sexo);
    miAlumno.sexo=toupper(miAlumno.sexo);
    while(miAlumno.sexo!='F' && miAlumno.sexo!='M')
    {
        printf("Reingrese un sexo valido: ");
        scanf("%c",&miAlumno.sexo);
        miAlumno.sexo=toupper(miAlumno.sexo);
        }
        fflush(stdin);

    return miAlumno;
}

void mostrarUnAlumno(sAlumno unAlumno)
{
    printf("%4d %20s %2f %5d %5c\n",unAlumno.legajos,unAlumno.nombres,unAlumno.alturas,unAlumno.notas,unAlumno.sexo);
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

    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");

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

    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");

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
    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");
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

    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");

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

    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");
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
    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");
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
    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");
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
    printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");

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
    int cargo=0;
    int legajo;
    char opcion;
    int auxnota;
    mostrarAlumnos(listas,tam);
    printf("Ingrese legajo a buscar: ");
    scanf("%d",&legajo);
    for(i=0; i<tam; i++)
    {
        if(listas[i].estado != VACIO &&legajo == listas[i].legajos)
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
                cargo =1;
            }
        }
    }
  if(cargo == 0)
    {
        printf("Legajo inexistente");
    }
}

void darDeBaja(sAlumno listas[],int tam)
{
    int i;
    int cargo=0;
    int legajo;
    char opcion;
    mostrarAlumnos(listas,tam);
    printf("Ingrese legajo a buscar: ");
    scanf("%d",&legajo);
    for(i=0; i<tam; i++)
    {
        if(listas[i].estado != LLENO &&legajo == listas[i].legajos)
        {

            mostrarUnAlumno(listas[i]);

            printf("Esta seguro de querer borrar este legajo?");
            opcion=getch();
            if(opcion == 's')
            {
                listas[i].estado= BAJA;
                printf("\n\nAlumno borrado!");
                cargo =1;
            }
        }
    }
  if(cargo == 0)
    {
        printf("Se ha cancelado la operacion");
    }
}

int buscarLibre(sAlumno listas[],int tam)
 {
 int index = -1;
 int i;
    for(i=0; i<tam; i++)
    {
        if(listas[i].estado==VACIO)
        {
            index = i;
            break;
        }
    }
    return index;
}

int cargarLibre(sAlumno listas[],int tam)
{
    int bandera;
    int retorno=0;

    bandera = buscarLibre(listas,tam); //buscra lib me dice donde, lo guard en bamde
    if(bandera!=VACIO)
    {
        listas[bandera] = cargarUnAlumno();
        listas[bandera].estado = LLENO;

     return 1;
    }

    else
    {
        printf("No hay espacio");
    }
    return retorno;
}

void ordenarPorSexo(sAlumno listas[],int tam)
 {
     int i;
     int j;
     sAlumno auxSexo;

      printf("%4s %20s %2s %5s %5s\n","Legajo","Nombre","Altura","Nota","Sexo");

     for(i=0;i<tam-1;i++)
     {
         for(j=i+1;j<tam;j++)
         {
             if(listas[i].sexo,listas[j].sexo>0)
             {
               auxSexo = listas[i];
               listas[i] = listas[j];
               listas[j] = auxSexo;
             }
         }
     }
     for(i=0; i<tam; i++)
            {
        mostrarUnAlumno(listas[i]);
            }
 }
