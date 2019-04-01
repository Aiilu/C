#include <stdio.h>
#include <stdlib.h>

float calcularPromedio(int edad[], int tam);
void mayorEdad(int legajo[], int edad[], char sexo[], int tam);
int mujeresNacidas(char sexo[], int tam);

int main()
{
    int legajo[]={1,2,3,4,3,5,6,7,8,9,10};
    int edad[]={22,40,10,75,15,65,32,12,46,17};
    char sexo[]={'f','m','m','f','m','f','f','f','m','m'};

    calcularPromedio(edad,10);
    mayorEdad(legajo,edad,sexo,10);
    mujeresNacidas(sexo,10);

    return 0;
}

float calcularPromedio(int edad[], int tam)
{
    int acum=0;
    float prom=0;
    int i;

    for(i=0;i<tam;i++)
    {
        acum+=edad[i];
    }

    prom = acum/tam;

    printf("Edad promedio de los empleados: %.2f\n",prom);
    printf("\n\n");

    return prom;

}

void mayorEdad(int legajo[], int edad[], char sexo[], int tam)
{
        int i;
        int maxEdad;
        int maxLegajo;
        char maxSexo;

        printf("Persona mayor de edad\n");
        for(i=0;i<tam;i++)
        {
            if(edad[i] > maxEdad)
            {
              maxEdad = edad[i];
              maxLegajo = legajo[i];
              maxSexo = sexo[i];
            }
        }

        printf("Legajo : %d , Sexo: %c , Edad: %d\n",maxLegajo,maxSexo,maxEdad);

}

int mujeresNacidas(char sexo[], int tam)
{
    int i;
    int cont=0;

    for(i=0;i<tam;i++)
    {
        if(sexo[i]=='f')
        {
            cont++;
        }
    }

    printf("\n\n");
    printf("En total hay %d mujeres\n",cont);

    return cont;

}

/*De los 30 empleados de una fábrica se registra la edad, el sexo y el legajo. Terminado el ingreso se pide
conocer:
 La edad promedio de los empleados de la fábrica.
 El legajo y sexo de la persona de mayor edad.
 Cuántas mujeres nacieron en el año 1978.*/
