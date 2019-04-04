#include <stdio.h>
#include <stdlib.h>

int pregPeso();

int main()
{

    int peso;
    int contPeso=0;
    int contPesoMayor=0;
    char seguir;

    do{

       peso = pregPeso();

       if(peso<=80)
       {
        contPeso++;
       }
       else if(peso>80)
       {
        contPesoMayor++;
       }

        printf("Desea continuar?");
        fflush(stdin);
        scanf("%c",&seguir);

     }while(seguir=='s');

     printf("Cantidad de empleados que pesan <=80kg: %d",contPeso);
     printf("Cantidad de empleados que pesan >80kg: %d",contPesoMayor);

    return 0;
}

int pregPeso()
{
    int peso;

    printf("Ingrese el peso del empleado:");
    scanf("%d",&peso);

    while(peso<=0)
    {
        printf("Este peso no es valido\n");
        printf("Ingrese el peso del empleado: ");
        scanf("%d",&peso);
        fflush(stdin);
    }

    return peso;
}

/*Dise�ar en un programa que permita registrar de los empleados de una f�brica (no se sabe cu�ntos) su peso
y saber cu�ntos pesan hasta 80 kg. inclusive y cuantos pesan m�s de 80 kg.*/
