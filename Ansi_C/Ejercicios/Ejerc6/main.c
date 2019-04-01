#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int contMayor=0;
    int contMenor=0;
    int i=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);

        if(num>0)
        {
            contMayor ++;
        }
        else
        {
             contMenor ++;
        }
    }

    printf("Hay %d Mayores a Cero.\nHay %d Menores a Cero",contMayor,contMenor);

    return 0;
}

/*De 10 números ingresadas indicar cuantos son mayores a cero y cuantos son menores a cero*/
