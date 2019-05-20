#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* pNum;

    pNum = (int*)malloc(sizeof(int));

    if(pNum == NULL)
    {
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }

    for(int i=0; i<5; i++)
    {
      printf("Ingrese un numero: ");
      scanf("%d",pNum+i);
    }

    for(int i=0; i<5; i++)
    {
        printf("%d\n",*(pNum+i));
    }

    return 0;
}
