#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int validaS_N();

int main()
{
    int x;
    int acum = 0;
    char seguir = 'S';

    do{

    printf("Ingrese un numero: ");
    scanf("%d",&x);

    acum+=x;

    seguir=validaS_N();

    }while(seguir!='N');

    printf("La suma es: %d",acum);

    return 0;
}

int validaS_N()
{
    char seguir='S';
    printf("\nD E S E A  C O N T I N U A R ? S/N: ");
    scanf("%s", &seguir);
    seguir=toupper(seguir);

    while(seguir != 'N' && seguir != 'S')
    {
        printf("\nLA OPCION INGRESADA ES INVALIDA.");
        printf("\nI N G R E S E   N U E V A M E N T E: ");
        scanf("%s", &seguir);
        seguir=toupper(seguir);

    }

    return seguir;
}
