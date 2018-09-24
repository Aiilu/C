#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define A 2

typedef struct //se define,aca no se guardan datos
{
int legajo;
char nombre[50];//solo los caracteres que ocupan, la matriz no, no son paralelos
float altura;
int nota;
}eAlumno; //c o e y el nombre de la identidad

void cargarListadoDeAlumnos(eAlumno[],int);
void mostrarListadoDeAlumnos(eAlumno[],int);
void mostrarUnAlumno(eAlumno);
void ordenarAlfabeticamente(eAlumno[],int);
eAlumno cargarUnAlumno();
int main()
{
   ////// eAlumno miAlumnoMain;
   eAlumno listadoMain[A];

   cargarListadoDeAlumnos(listadoMain,A);
   mostrarListadoDeAlumnos(listadoMain,A);
   ordenarAlfabeticamente(listadoMain,A);

   /*int i;
   for(i=0;i<A;i++)
   {
       listadoMain[i] = cargarUnAlumno();
   }*/
    //////miAlumnoMain = cargarUnAlumno();

    /*for (i=0;i<A;i++)
    {
        mostrarUnAlumno(listadoMain[i]);
    }*/
   ////// mostrarUnAlumno(miAlumnoMain);
    //crear espacio para ese alumno

   /* eAlumno miAlumno;//={123 , "Juan" , 1.84 , 7}; //declaro mis variables,siempre en el orden que declare

    printf("Ingrese legajo:");
    scanf("%d",&miAlumno.legajo);

    printf("Ingrese nombre:");
    scanf("%s",miAlumno.nombre);

    printf("Ingrese la altura:");
    scanf("%f",&miAlumno.altura);

    printf("Ingrese nota:");
    scanf("%d",&miAlumno.nota);

    ////otroAlumno = miAlumno;

    mostrarUnAlumno(miAlumno);

    //printf("%d\n\n", miAlumno); //muestra primera dirrec de meoria
    //printf("%d\n\n",&miAlumno);

    //printf("%d\n\n",sizeof(eAlumno)); //sumatoria de los datos


    ////printf("%d--%s--%f--%d\n", miAlumno.legajo, miAlumno.nombre, miAlumno.altura, miAlumno.nota);*/

    return 0;
}
eAlumno cargarUnAlumno()
{
    eAlumno miAlumno;//={123 , "Juan" , 1.84 , 7}; //declaro mis variables,siempre en el orden que declare

    printf("Ingrese legajo:");
    scanf("%d",&miAlumno.legajo);

    printf("Ingrese nombre:");
    scanf("%s",miAlumno.nombre);

    printf("Ingrese la altura:");
    scanf("%f",&miAlumno.altura);

    printf("Ingrese nota:");
    scanf("%d",&miAlumno.nota);

    ////otroAlumno = miAlumno;

   return miAlumno;
}
void mostrarUnAlumno(eAlumno unAlumno)
{
    printf("%d--%s--%f--%d\n", unAlumno.legajo, unAlumno.nombre, unAlumno.altura, unAlumno.nota);
}
void cargarListadoDeAlumnos(eAlumno listado[],int tam)
{
    int i;
   for(i=0;i<tam;i++)
   {
       listado[i] = cargarUnAlumno();
   }
}
void mostrarListadoDeAlumnos(eAlumno listado[],int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        mostrarUnAlumno(listado[i]);
    }
}

void ordenarAlfabeticamente(eAlumno listado[],int tam)
{
   //nt auxInt;
   //nt auxIntNota;
    //oat auxFloat;//escalar, solo guarda un valor
    //ar auxString[100];

    int i;
    int j;

    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listado[i].nombre,listado[j].nombre)>0)//criterio ordenamiento
            {
                auxAlumno=listado[i];
                listado[i]=listado[j];
                listado[j]=auxAlumno;

            }
  }

  for(i=0; i<tam; i++)
  {
      mostrarUnAlumno(listado[i]);
  }

}

}
