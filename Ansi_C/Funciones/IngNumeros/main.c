#include <stdio.h>
#include <stdlib.h>

int pedirIntRango(int,int);

int main()
{
    int x = pedirIntRango(18,65);

    printf("%d\n",x);
    return 0;
}

int pedirIntRango(int min, int sup)
{
    int num;

    printf("Ingrese un numero entre %d y %d: ",min, sup);
    fflush(stdin);
    scanf("%d",&num);

    //while(!(num>=min && num <=sup))
    while(num < min || num > sup)
    {
       printf("ERROR. Ingrese un numero entre %d y %d: ", min, sup);
       scanf("%d",&num);
    }

    return num;
}
