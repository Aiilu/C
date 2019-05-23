#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int menu();

int main()
{

    char seguir = 's';

    int* pNum;

    pNum = (int*)malloc(sizeof(int)*5);

    do
    {
        switch(menu())
        {
        case 1:
            if(cargarVector(pNum,TAM)==0)
            {
                printf("Malloc no logro encontrar lugar\n");
                system("pause");
                exit(1);
            }
            else
            {
                printf("Se logro cargar correctamente\n");
                system("pause");
            }
            break;
        case 2:
            if(buscarIndice(pNum,TAM)==0)
            {
                printf("Alo, soy NULL\n");
                system("pause");
            }
            else
            {
                printf("Efectuo la busqueda correctamente\n");
                system("pause");
            }
            break;
        case 3:
            if(buscarValor(pNum,TAM)==0)
            {
                printf("Alo, soy NULL\n");
                system("pause");
            }
            else
            {
                printf("Efectuo la busqueda correctamente\n");
                system("pause");
            }
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Esta opcion no es valida\n");
        }

        system("pause");
    }
    while(seguir !='n');

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

int cargarVector(int* pNum, int tam)
{
    int todoOk = 0;

    if(pNum != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            printf("Ingrese un numero en la posicion %d: ",i);
            scanf("%d",pNum+i);
            todoOk = 1;
        }
    }

    return todoOk;
}


void buscarIndice(int* pNum, int tam)
{
    int i;
    int y;
    int flag = 0;
    int todoOk = 0;

    if(pNum !=NULL)
    {
        printf("Ingrese el valor a buscar: ");
        scanf("%d",&y);

        for(i=0; i<tam; i++)
        {
            if(*(pNum+i)==y)
            {
                printf("El valor pertenece al indice %d\n",i);
                flag = 1;
                todoOk = 1;
            }
        }

        if(flag == 0)
        {
            printf("El valor no existe en ningun indice\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int buscarValor(int* x, int tam)
{
    int todoOk = 0;
    int y;

    if(x!=NULL)
    {
        printf("Ingrese el indice a buscar: ");
        scanf("%d",&y);

        printf("%d\n", *(x+y));

        todoOk = 1;
    }

    return todoOk;

}
