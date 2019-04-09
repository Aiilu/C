#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validLegajo();
char validString();

typedef struct
{
int legajo;
char nombre[20];
char sexo;
float sueldo;
}Eempleado;

int main()
{
    Eempleado emp;
    char auxCad[100];

    printf("Ingrese legajo: ");
    scanf("%d",&emp.legajo);

      while(emp.legajo<1000 || emp.legajo>9999)
    {
        printf("ERROR. Ingrese legajo de 4 cifras: ");
        scanf("%d",&emp.legajo);
    }


     printf("Ingrese nombre: ");
     fflush(stdin);
     gets(auxCad);

    while(strlen(auxCad)>19)
    {
        printf("ERROR. Ingrese nombre menor a 19 caracteres: ");
        fflush(stdin);
        gets(auxCad);
    }

    strcpy(emp.nombre,auxCad);

    printf("Ingrese el sexo, F/M: ");
    fflush(stdin);
    scanf("%c",&emp.sexo);

    while(emp.sexo != 'f' && emp.sexo != 'm' && emp.sexo !='F' && emp.sexo !='M')
    {
        printf("ERROR. Ingrese F o M: ");
        fflush(stdin);
        scanf("%c",&emp.sexo);
    }

    printf("Ingrese el sueldo: ");
    scanf("%f",&emp.sueldo);
    while(emp.sueldo < 0)
    {
        printf("ERROR. Ingrese un sueldo positivo: ");
        scanf("%f",&emp.sueldo);
    }

    printf("Legajo Nombre Sexo Sueldo\n");
    printf("%5d %6s %3c %.2f",emp.legajo,emp.nombre,emp.sexo,emp.sueldo);

    return 0;
}


