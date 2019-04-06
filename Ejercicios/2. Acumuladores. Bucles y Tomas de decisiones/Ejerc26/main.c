#include <stdio.h>
#include <stdlib.h>

int main()
{
    char seguir;

    printf("Desea continuar?");
    fflush(stdin);
    scanf("%c",&seguir);

    while(seguir !='S' && seguir != 'N')
    {
        printf("ERROR. Ingrese 'S' o 'N'\n");
        printf("Desea continuar?");
        fflush(stdin);
        scanf("%c",&seguir);
    }

    return 0;
}

/*Hacer el programa ante la pregunta desea continuar sólo nos permita introducir como respuesta 'S' o'N'*/
