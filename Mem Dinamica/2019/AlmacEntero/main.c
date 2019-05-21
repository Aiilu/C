#include <stdio.h>
#include <stdlib.h>

void pedirNumero(int *pNumero);

int main()
{
    int* pNum;

    pNum = (int*)malloc(sizeof(int));

    if(pNum == NULL)
    {
       printf("No se consiguio espacio\n");
       system("pause");
       exit(1);
    }
    else
    {
       pedirNumero(pNum);

       printf("%d",*pNum);
    }

    free(pNum);

    return 0;
}

void pedirNumero(int *pNumero)
{
    printf("Ingrese un numero: ");
    scanf("%d",pNumero);
}
