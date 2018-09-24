#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "legajo.h"
#define T 2

int main()
{
    sAlumno listadoAlumnos[T];

     int opcion;
    int flag=0;

    do
    {
        system("cls");
        printf("1. Cargar alumnos\n2. Mostrar alumnos\n3. Ordenar alumnos alfabeticamente\n4. Mostrar alumnos aprobados\n5. Mostrar alumnos desaprobados\n6. Alumnos llamados Juan\n7. Alumnos con P\n8. Notas maximas\n9. Alumno mas Mediocre\n10. Modificar nota a partir de legajo\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            cargarAlumnos(listadoAlumnos,T);
            flag=1;
            break;
        case 2:
            system("cls");
            if(flag==1)
            {
                mostrarAlumnos(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
            }
        case 3:
            system("cls");
            if(flag==1)
            {
                ordenarAlfabeticamente(listadoAlumnos,T);
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                system("pause");
                break;
            }
        case 4:
            system("cls");
            if(flag==1)
            {
                alumnosAprobados(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case 5:
            system("cls");
            if(flag==1)
            {
                alumnosDesaprobados(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case 6:
            system("cls");
            if(flag==1)
            {
                alumnoLlamadoJuan(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case 7:
            system("cls");
            if(flag==1)
            {
                validarNombreConP(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case 8:
            system("cls");
            if(flag==1)
            {
                notasMaximas(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case  9:
            system("cls");
            if(flag==1)
            {
                alumnoMasMediocre(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        case 10:
            system("cls");
            if(flag==1)
            {
                modificarListado(listadoAlumnos,T);
                system("pause");
                break;
            }
            else
            {
                printf("Primero debe cargar los datos \n");
                break;
            }
        default:
            printf("No existe esta opcion");
        }
    }
    while(opcion!=11);

    return 0;
}

