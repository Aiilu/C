#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int contA=0;
    int contE=0;
    int contI=0;
    int contO=0;
    int contU=0;
    int i=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese una letra: ");
        scanf("%c",&letra);
        fflush(stdin);

        switch(letra)
        {
            case 'a':
                contA++;
                break;
            case 'e':
                contE++;
                break;
            case 'i':
                contI++;
                break;
            case 'o':
                contO++;
                break;
            case 'u':
                contU++;
                break;
            default:
                printf("Opcion Incorrecta\n");
        }
    }

    printf("Cant de A: %d",contA);
    printf("Cant de E: %d",contE);
    printf("Cant de I: %d",contI);
    printf("Cant de O: %d",contO);
    printf("Cant de U: %d",contU);

    return 0;
}

/*Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se
ingresaron, cuantas "e, i, o, u"*/

