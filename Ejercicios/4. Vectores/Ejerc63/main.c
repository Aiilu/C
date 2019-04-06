#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define T 5

//void cargarEmpleados(int[],int[], float[], int);
void calcularEdad(int legajo[], int edad[], int tam);

int main()
{
    int legajos[T]={1,2,3,4,5};
    int edad[T]={21,50,35,41,54};

    calcularEdad(legajos,edad,T);

    return 0;
}

/*void cargarEmpleados(int legajos[],int edad[], float salario[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        system("cls");

        printf("Ingrese el legajo: ");
        scanf("%d",&legajos[i]);

        printf("Ingrese la edad: ");
        scanf("%d",&edad[i]);

        printf("Ingrese el salario: ");
        scanf("%f",&salario[i]);

    }
}*/


void calcularEdad(int legajo[], int edad[], int tam)
{
    int acum=0;
    float prom=0;
    int i;

    for(i=0;i<tam;i++)
    {
        acum+=edad[i];
    }

    prom = acum/tam;

    printf("El promedio es: %.2f\n",prom);

    for(i=0;i<tam;i++)
    {

    if(edad[i] > prom)
    {
        printf("EMPLEADOS %d QUE SUPERA LA EDAD PROMEDIO con %d AÑOS:\n",legajo[i],edad[i]);
    }
    }
}

/*De los 100 empleados de una fábrica se registra: número de legajo (coincide con el número de índice),
edad y salario. Se pide: Ingresar los datos correlativamente, Calcular la edad promedio informando número
de legajo de los empleados cuya edad supere el promedio*/
