#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    int edad;
    char sexo;
} eEmpleado;

int calcularPromedio(eEmpleado*, int tam);
int mayorEdad(eEmpleado* pEmp, int tam);
int mujeresNacidas(eEmpleado* emp, int tam);

int main()
{

    eEmpleado lista[] =
    {
        {1,22,'f'},
        {2,40,'m'},
        {3,10,'m'},
        {4,75,'f'},
        {5,15,'m'},
        {6,65,'f'},
        {7,32,'f'},
        {8,12,'f'},
        {9,16,'m'},
        {10,17,'m'}

    };

    eEmpleado* pEmp=(eEmpleado*)malloc(sizeof(int)*10);

    pEmp = lista;

    calcularPromedio(pEmp,10);

    if(mayorEdad(pEmp,10)!=0)
    {
        printf("Se logro encontrar al empleado mayor de edad\n");
    }
    else
    {
        printf("Hubo un error en esta busqueda\n");
    }

    if(mujeresNacidas(pEmp,10)!=0)
    {
        printf("Se logro contar a todas las mujeres\n");
    }
    else
    {
        printf("Hubo un error en esta busqueda\n");
    }

    free(pEmp);

    return 0;
}


int calcularPromedio(eEmpleado* pEmp, int tam)
{
    int acum=0;
    float prom=0;
    int todoOk = 0;

        for(int i=0; i<tam; i++)
    {
        acum+=(pEmp+i)->edad;
    }

    prom = acum/tam;

    printf("Edad promedio de los empleados: %.2f\n",prom);
    printf("\n\n");


    return prom;

}

int mayorEdad(eEmpleado* pEmp, int tam)
{
    int todoOk = 0;
    int legajo;
    int mayorEdad;
    int flag = 0;

    if(pEmp!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if((pEmp+i)->edad > mayorEdad  || flag == 0)
            {
                mayorEdad = (pEmp+i)->edad;
                legajo = (pEmp+i)->legajo;
                flag = 1;
                todoOk = 1;
            }
        }

        printf("Edad: %d Legajo: %d\n",mayorEdad,legajo);
    }

    return todoOk;

}


int mujeresNacidas(eEmpleado* emp, int tam)
{
    int i;
    int cont=0;
    int todoOk = 0;

    if(emp !=NULL)
    {
        for(i=0; i<tam; i++)
        {
            if((emp+i)->sexo =='f')
            {
                cont++;
                todoOk = 1;
            }
        }

        printf("\n\n");
        printf("En total hay %d mujeres\n",cont);
    }

    return todoOk;

}

/*De los 30 empleados de una fábrica se registra la edad, el sexo y el legajo. Terminado el ingreso se pide
conocer:
? La edad promedio de los empleados de la fábrica.
? El legajo y sexo de la persona de mayor edad.
? Cuántas mujeres nacieron en el año 1978.*/
