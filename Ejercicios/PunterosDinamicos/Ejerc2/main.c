#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int menu();
int cargarVector(int* pNum, int tam);
int ordenarVector(int* pNum, int tam);
int mostrarVector(int* pNum, int tam);

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
            if(cargarVector(vec,TAM)!=1)
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
             if(ordenarVector(vec,TAM)!=1)
            {
                printf("No hay nada que ordenar\n");
                system("pause");
            }
            else
            {
                printf("Se logro ordenar correctamente\n");
                system("pause");
            }
            break;
        case 3:
            if(mostrarVector(vec,TAM)!=1)
            {
                printf("No hay nada que mostrar\n");
                system("pause");
            }
            else
            {
                printf("Se logro mostrar correctamente\n");
                system("pause");
            }
            break;
        case 4:
            seguir = 'n';
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
    }
    while(seguir == 's');


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

    if(pNum != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",pNum+i);
            todoOk = 1;
        }
    }

    return todoOk;
}

int ordenarVector(int* pNum, int tam)
{
    int todoOk = 0;
    int aux;

    if(pNum !=NULL)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((pNum+i)>(pNum+j))
                {
                    aux = *(pNum+i);
                    *(pNum+i) = *(pNum+j);
                    *(pNum+j) = aux;

                    todoOk = 1;

                }
            }
    }
    }

    return todoOk;

}

int mostrarVector(int* pNum, int tam)
{
    int todoOk = 0;

    if(pNum !=NULL)
    {
      for(int i=0; i<tam; i++)
      {
              printf("%d\n",*(pNum+i));
              todoOk = 1;
      }
    }

    return todoOk;
}
