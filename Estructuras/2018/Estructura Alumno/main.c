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
 int estado;
 }eAlumno; //c o e y el nombre de la identidad

 void cargarListadoDeAlumnos(eAlumno[],int);
 void mostrarListadoDeAlumnos(eAlumno[],int);
 void mostrarUnAlumno(eAlumno);
 void ordenarAlfabeticamente(eAlumno[],int);
 eAlumno cargarUnAlumno();
 int main()
 {
    eAlumno listadoMain[A];
    int i;

   for(i=0; i<A; i++)
   {
       listadoMain[i].estado=-1; //CARGAR LISTADO BUSCO LIBRE Y SACO EL FOR
       //AGREGAR M
   }
    char opcion;

    do
    {
        printf("a. cargar alumnos\no. ordenar alfabeticamente\nm. mostrar alfabeticamente");
        printf("ingrese una opcion");
        opcion = getche();
        switch(opcion)
        {
        case 'a':
    cargarListadoDeAlumnos(listadoMain,A);
    break;

        case 'o':
    ordenarAlfabeticamente(listadoMain,A);
    break;

        case 'm':
    mostrarListadoDeAlumnos(listadoMain,A);
            break;

        }
    } while(opcion!='s');

     return 0;
 }
 eAlumno cargarUnAlumno()
 {
     eAlumno miAlumno;

     printf("Ingrese legajo:");
     scanf("%d",&miAlumno.legajo);

     printf("Ingrese nombre:");
     scanf("%s",miAlumno.nombre);

     printf("Ingrese la altura:");
     scanf("%f",&miAlumno.altura);

     printf("Ingrese nota:");
     scanf("%d",&miAlumno.nota);


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
