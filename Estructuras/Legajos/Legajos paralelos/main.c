#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 2

void cargarAlumnos(int[], char[][21], int[], float[], int);
void mostrarAlumnos(int[], char[][21], int[], float[], int);
void ordenarAlfabeticamente(int[], char [][21], int[],float[],int);
int alumnosAprobados(int,int[],int);
void mostrarNombreJuan(char[][21],int);
void alumnoLlamadoJuan(char[][21],int);
void validarNombreConP(char[]);
void notasMaximas(int[],char[][21],int);
void alumnoMasMediocre(int[], char[][21], int[], float[], int);

/*FALTA EL ALUMNO CON MAS NOTA(MAS DE 1).
EL MAS MEDIOCRE, LEGAJO=100, NOTA=5, SE LLAMA PEPE Y MIDE 1.75.
INGRESAR UN LEGAJO Y PERMITIR LA MODIFICACION DE LA NOTA.
Y TRANSFORMAR LA CARGA DE DATOS Y PERMITIR LA MODIFICIACION DE LA NOTA.*/

int main()
{
    int contador=0;
    int legajos[T];
    char nombres[T][21];
    int notas[T];
    float alturas[T];

    cargarAlumnos(legajos,nombres,notas,alturas,T);
    mostrarAlumnos(legajos,nombres,notas,alturas,T);
  //  ordenarAlfabeticamente(legajos,nombres,notas,alturas,T);
     printf("Ordenar: \n");
    ordenarAlfabeticamente(legajos,nombres,notas,alturas,T);
   contador = alumnosAprobados(contador,notas,T);
    alumnoLlamadoJuan(nombres,T);    //SALE DOS VECES EL ELSE
    validarNombreConP(nombres);
  notasMaximas(notas,nombres,T);    //DA A INTRODUCIR EL NOMBRE, MAS DE UN MAXIMO
    alumnoMasMediocre(legajos,nombres,notas,alturas,T);

    return 0;
}

void cargarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese el legajo: ");
        scanf("%d",&legajos[i]);

        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(nombres[i]);

        printf("Ingrese la nota: ");
        scanf("%d",&notas[i]);

        printf("Ingrese la altura: ");
        scanf("%f",&alturas[i]);
    }
}

void mostrarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tam)
{
    int i;

    printf("%4s %20s %2s %5s\n","Legajo","Nombre","Nota","Altura");

    for(i=0; i<tam; i++)
    {
        printf("%4d %20s %2d %5f\n", legajos[i], nombres[i], notas[i],alturas[i]);
    }
}

void ordenarAlfabeticamente(int legajos[], char nombres [][21], int notas[],float alturas[],int tam)
{
    int auxInt;
    float auxFloat;//escalar, solo guarda un valor
    char auxString[100];

    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(nombres[i], nombres[j])>0)//criterio ordenamiento
            {
                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);

                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxFloat = alturas[i];
                alturas[i] = alturas[j];
               alturas[j] = auxFloat;



            }
                for(i=0; i<tam; i++)
    {
        printf("%4d %20s %2d %5f\n", legajos[i], nombres[i], notas[i],alturas[i]);
    }
  }
}

}




int alumnosAprobados(int contador, int notas[],int tam)
{

    int i;

    for(i=0; i<tam; i++)
    {
        if(notas[i]>6)
        {
            contador ++;

        }
    }
            printf("Hay %d alumno/s aprobado/s",contador); //mostrar nombres

    return contador;
}

void alumnoLlamadoJuan(char nombres[][21],int tam)
{
    int contador=0;

    int i;
    char alumno[]="juan";
    //printf("%s",alumno);

   // printf("tam: %d\n",tam);
    for(i=0; i<tam; i++)
    {
        printf("%s \n",nombres[i]);
        gets(nombres[i]);
        printf("%s \n",nombres[i]);

       if(stricmp(nombres[i],alumno)==0)
        {
            //printf("i: %d\n",i);
            contador ++;
            printf("\n Hay %d alumno/s llamado/s %s",contador,nombres[i]);
        }

        else {

            printf("No hay ningun Juan registrado");
        }
    }

}

void validarNombreConP(char nombre[])
 {
     if(nombre[0] == 112 || nombre[0] == 80)
        {
        //puts(nombre);
        printf("Alumnos que su nombre empieza con P: %s",nombre);
        }
        else {
            printf("Ningun nombre empieza con P");
        }
 }

void notasMaximas(int notas[],char nombre[][21],int tam)
 {
     int i;
     int mayor=0;

     for(i=1;i<tam;i++)
     {
      //   scanf("%d",&notas[i]);
        // gets(nombre[i]);

         if(notas[i]>notas[mayor])
         {
             mayor=i;
         }
     }

     printf("Nota Maxima: %s %d",nombre[mayor],notas[mayor]);

}


void alumnoMasMediocre(int legajo[], char nombres[][21], int nota[], float altura[], int tam)
 {
     int i;
     char alumno[]="pepe";

     for(i=0;i<tam;i++)
     {//legajo=100 nota=5 se llame pepe medir 1.75"
         if(stricmp(nombres[i],alumno)==0)
         {
             if(legajo[i]=="100" && nota[i]=="5" && altura[i]=="1.75")
             {

         printf("El alumno mas mediocre es: %s",nombres[i]);
 }
             }

             else {
                printf("No existe el alumno mas mediocre");
             }
         }

     }
