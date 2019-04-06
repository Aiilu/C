#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int menu();
void cargarArray(int array[], int tam);
void buscarIndice(int x[], int tam);
void buscarValor(int x[], int tam);

int main()
{

    char seguir = 's';
    int vec[TAM];

    do
    {
        switch(menu())
        {
         case 1:
         cargarArray(vec,TAM);
         break;
         case 2:
         buscarIndice(vec,TAM);
         break;
         case 3:
         buscarValor(vec,TAM);
         break;
         case 4:
         seguir = 'n';
         break;
         default:
         printf("Esta opcion no es valida\n");
        }

        system("pause");
    }while(seguir !='n');

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    system("COLOR F0");
    printf("1. Cargar el array\n");
    printf("2. Encontrar indice x valor\n");
    printf("3. Encontrar valor x indice\n");
    printf("Ingrese una opcion del menu: ");
    scanf("%d",&opcion);

    return opcion;
}

void cargarArray(int x[], int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese  un valor para el indice %d\n",i);
        scanf("%d",&x[i]);
    }
}

void buscarIndice(int x[], int tam)
{
    int i;
    int y;
    int flag = 0;

    printf("Ingrese el valor a buscar: ");
    scanf("%d",&y);

    for(i=0;i<tam;i++)
    {
        if(x[i]==y)
        {
            printf("El valor pertenece al indice %d\n",i);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El valor no existe en ningun indice\n");
    }
}

void buscarValor(int x[], int tam)
{
    int y;

    printf("Ingrese el indice a buscar: ");
    scanf("%d",&y);

    printf("%d\n", x[y]);

}
