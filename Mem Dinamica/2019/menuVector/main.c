#include <stdio.h>
#include <stdlib.h>

int menu();

int main()
{
    char seguir = 's';
    int* vec;

    vec = (int*)malloc(sizeof(int)*5);

    do
    {
        switch(menu())
    {
        case 1:
            if(cargarVector(vec,5)==1)
            {
                printf("No se consiguio lugar\n");
                system("pause");
                exit(1);
            }
            else
            {
                printf("El vector se cargo correctamente\n");
                system("pause");
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }
    }while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;

        system("cls");
        printf("MENU DE OPCIONES\n");
        printf("1. Cargar el vector\n");
        printf("2. Ordenar el vector\n");
        printf("3. Mostrar el vector\n");
        printf("4. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        return opcion;
}

int cargarVector(int* pNum, int tam)
{
    int todoOk = 0;

    if(pNum == NULL)
    {
       todoOk = 1;
    }
    else
    {
        for(int i=0; i<tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",pNum+i);
        }
    }

    return todoOk;
}
