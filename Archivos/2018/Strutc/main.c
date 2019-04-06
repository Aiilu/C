#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int id;
char nombre[20];
char apellido[20];
int edad;
}ePersona;

int main()
{
    ePersona* per;
    int cant;
    char buffer[4][100];

    FILE* f;
    f = fopen("numeros.csv","r");

    if(f==NULL)
    {
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f,"%[^,],%[^,],[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        per.id = atoi(buffer[0]);
        strcpy(per.nombre,buffer[1]);
        strcpy(per.apellido,buffer[2]);
        per.edad = atoi(buffer[3]);

        if(cant == 4)
        {
            printf("Los numericos ingresados son %d %s %s %d\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        }

        else
        {
         break;
        }
    }

    fclose(f);

    return 0;
}
