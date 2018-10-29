#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int codigo;
char nombre[20];
float sueldo;
}eEmpleado;

int main()
{
    FILE* f;

    f=fopen("empleados.bin","wb");

    eEmpleado emp = {1234,"Juan",15000};

    eEmpleado* emp2 = (eEmpleado*) malloc(sizeof(eEmpleado));

    emp2->codigo = 1111;
    strcpy(emp2->nombre,"Jose");
    emp2->sueldo = 24500;

    if(f==NULL)
    {
        printf("Problemas al crear el archivo");
        exit(1);
    }

    fwrite(&emp,sizeof(eEmpleado),1,f);
    fwrite(emp2,sizeof(eEmpleado),1,f);

    printf("%d %s %.2f",emp.codigo,emp.nombre,emp.sueldo);
    printf("%d %s %.2f",emp2->codigo,emp2->nombre,emp2->sueldo);

    free(f);
    fclose(f);

    return 0;
}
