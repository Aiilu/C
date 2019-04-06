#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char seguir;
    int i=0;
    int numeros;
    float prom;
    int acum=0;
    int acumPares=0;
    int flag=0;
    int max;
    int min;

    do{

       printf("Ingrese un numero: ");
       scanf("%d",&numeros);

       while(numeros < 0)
       {
           printf("El numero es NEGATIVO. Ingrese un numero POSITIVO\n");
           printf("Ingrese un numero: ");
           scanf("%d",&numeros);
           fflush(stdin);
       }

       acum+=numeros;
       i++;

       if(numeros%2==0)
       {
           acumPares++;
       }

       if(numeros > max || flag == 0)
        {
            max=numeros;
        }

        if(numeros < min || flag == 0)
        {
            min=numeros;
            flag = 1;
        }

       printf("Desea continuar?");
       fflush(stdin);
       //scanf("%c",&seguir);
       seguir=getchar();

    }while(seguir=='s');

    prom = acum/i;

    printf("Cantidad de numeros pares: %d", acumPares);
    printf("El promedio es: %f", prom);
    printf("La suma de los numeros es: %d", acum);
    printf("El maximo es: %d Y el minimo es: %d", max,min);

    return 0;
}
