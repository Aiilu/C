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
    eEmpleado emp1 = {1234, "Juan", 34000, 'm',{21,5,2019}};

    printf("%s\n",emp1.nombre);

    eEmpleado* pEmp;

    pEmp = &emp1;
    //Le paso la dir. mem. de la struct al puntero

    printf("%d %s %.2f %c %02d/%02d/%d\n",pEmp->legajo,pEmp->nombre,pEmp->sueldo,pEmp->sexo,pEmp->fecha.dia,pEmp->fecha.mes,pEmp->fecha.anio);
    //Al dia accedo con el '.' debido a que eso ya esta accediendo a algo de la struct, por eso con punto
    //De estar accediendo al puntero, '->'

    printf("\n\n");

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(pEmp->nombre);

    printf("%s\n",pEmp->nombre);

    printf("Ingrese sueldo: ");
    scanf("%f",&pEmp->sueldo);

    //La dir. mem tengo la de la struct, no el de sueldo, el & afecta al sueldo, no al puntero, se lo paso para identificarlo

    printf("%.2f",pEmp->sueldo);

    return 0;
}
