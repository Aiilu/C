#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

int main()
{
    char nombres[][20]= {"Juan", "Jose", "Ana", "Maria", "Mia", "Jaime", "Esteban", "Julio", "Lara", "Sofia"};
    int legajos[TAM] = {123, 543, 679, 432, 567, 111, 323, 145, 674, 543};
    int edades[TAM] = {23, 24, 21, 23, 22, 22, 44, 36, 29, 38};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm', 'm', 'f', 'f', 'm', 'f'};
    int auxInt;
    char auxChar;
    char  auxString[20];

    for(int i=0; i < TAM - 1;  i++)
    {
        for(int j = i +1; j < TAM;  j++)
        {
            if( sexos[i] > sexos[j])
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);
            }
            else if( (sexos[i] == sexos[j]) && (strcmp(nombres[i],nombres[j])>0))
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);

            }

            /*if( strcmp(nombres[i],nombres[j]) > 0)
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                auxChar = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxChar;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);
            }
            else if( (sexos[i] == sexos[j]) && (strcmp(nombres[i],nombres[j])>0))
            {
                auxInt = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxInt;

                auxInt = edades[i];
                edades[i] = edades[j];
                edades[j] = auxInt;

                strcpy(auxString,nombres[i]);
                strcpy(nombres[i],nombres[j]);
                strcpy(nombres[j],auxString);

            }*/

        }

    }


    for(int i=0; i < TAM;  i++)
    {


        printf("%15s   %d      %c      %d\n", nombres[i], legajos[i], sexos[i], edades[i]);


    }

    return 0;
}
