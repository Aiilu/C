#include <stdio.h>
#include <stdlib.h>
#define T 5
int main()
{
    int edad[T]= {10,20,30,40,50};
    int leg[T]= {1,2,3,4,5};
    char sex[T]= {'f','m','f','m','m'};
    int i;
    int j;
    int auxInt;
    char auxChar;
    int flag = 0;
    char sexos;
    int legajos;

    printf("Ingrese el legajo a buscar: ");
    scanf("%d",&legajos);

    for(i=0; i<T; i++)
    {

        if(leg[i]==legajos)
        {
            sexos = sex[i];
            printf("El legajo %d es %c\n",legajos,sexos);
            printf("\n\n");
            flag = 1;
        }
        else
        {
            printf("Este legajo no existe\n");
        }
    }

    /*if(flag == 0)
    {
        printf("Este legajo no existe\n");
        printf("\n\n");
    }*/

    for( i=0; i < T - 1; i++)
    {
        for(j= i+1; j < T; j++ )
        {
            if( sex[i] > sex[j])
            {

                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxChar = sex[i];
                sex[i] = sex[j];
                sex[j] = auxChar;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

            }

            else if(sex[i] == sex[j] && leg[i] < leg[j])
            {
                auxInt = leg[i];
                leg[i] = leg[j];
                leg[j] = auxInt;

                auxInt = edad[i];
                edad[i] = edad[j];
                edad[j] = auxInt;

            }


        }
    }

    for(i=0; i < T;  i++)
    {


        printf("%d      %c      %d\n", leg[i], sex[i], edad[i]);


    }

    return 0;
}

/*int main()
{
    int legajos[TAM] = {123, 543, 679, 432, 567, 111, 323, 145, 674, 543};
    int edades[TAM] = {23, 24, 21, 23, 22, 22, 44, 36, 29, 38};
    char sexos[TAM] = {'f', 'f', 'm', 'f', 'm', 'm', 'f', 'f', 'm', 'f'};
    int auxInt;
    char auxChar;


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
            }
            else if( sexos[i] == sexos[j] && edades[i] < edades[j])
                {
                        auxInt = legajos[i];
                        legajos[i] = legajos[j];
                        legajos[j] = auxInt;

                        auxInt = edades[i];
                        edades[i] = edades[j];
                        edades[j] = auxInt;



                }
            }



        }



        for(int i=0; i < TAM;  i++)
        {


            printf("%d      %c      %d\n", legajos[i], sexos[i], edades[i]);


        }
        return 0;
    }*/
