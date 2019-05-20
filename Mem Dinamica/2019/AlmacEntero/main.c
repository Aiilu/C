#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}

void pedirNumero(int *pNumero)
{
    printf("Ingrese un numero: ");
    scanf("%d",pNumero);
}
