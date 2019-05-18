#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int dia;
  int mes;
  int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    float sueldo;
    char sexo;
    eFecha fecha;
}eEmpleado;
//La struct son como mucho 29 bytes en total de espacio

int main()
{
    eEmpleado lista[] =
    {
    {1234, "Juan", 34000, 'm',{21,5,2019}},
    {1111, "Ana", 40000, 'f',{18,4,2019}},
    {2222, "Amelia", 25650, 'f',{14,6,2019}}
    };

    eEmpleado* pEmp;

    pEmp = &lista;

    mostrarEmpleados(pEmp,3);

    return 0;
}

void mostrarEmpleado(eEmpleado* pEmp)
{
    printf("%d %s %.2f %c %02d/%02d/%d\n",pEmp->legajo,pEmp->nombre,pEmp->sueldo,pEmp->sexo,pEmp->fecha.dia,pEmp->fecha.mes,pEmp->fecha.anio);
}

void mostrarEmpleados(eEmpleado* pEmp, int tam)
{
    printf("Legajo Nombre Sueldo Sexo Fecha\n");

    for(int i=0; i<tam; i++)
    {
        mostrarEmpleado(pEmp+i);
    }
}

/*void mostrarEmpleados(eEmpleado* pEmp, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d %s %.2f %c %02d/%02d/%d\n",pEmp+i->legajo,pEmp+i->nombre,pEmp+i->sueldo,pEmp+i->sexo,pEmp+i->fecha.dia,pEmp+i->fecha.mes,pEmp+i->fecha.anio);
    }
}*/
