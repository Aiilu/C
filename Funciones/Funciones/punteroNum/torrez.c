#include "torrez.h"

float ingresarNumero()
{
    float valor;

    printf("\n\n");
    printf("     Ingrese un numero: ");
    fflush(stdin);
    scanf("%f",&valor);

    return valor;
}

float sumar(float sumaUno, float sumaDos)
{
    float suma;

    suma = sumaUno+sumaDos;

    return suma;
}

float restar(float restaUno, float restaDos)
{
    float resta;

    resta = restaUno-restaDos;

    return resta;
}

float multiplicar(float multUno, float multDos)
{
    float multiplicacion;

    multiplicacion = multUno*multDos;

    return multiplicacion;
}

float dividir(float dividUno, float dividDos)
{
    float division;

    if(dividDos !=0)
    {
        division = dividUno/dividDos;

        printf("           El resultado de %.2f / %.2f es: %.2f               \n",dividUno,dividDos,division);
    }
    else
    {
        printf("           No es posible dividir por cero.            \n");
    }

    return division;
}

float factorial(float primerFactor, float segundoFactor)
{
	int factorUno = 1, factorDos = 1, i;

	if (primerFactor>=0)
	{
		for (i = (int)primerFactor; i >= 1; i--)
		{
			factorUno = factorUno * i;
		}
		printf("           El factorial de %.0f! es: %.2i             \n", primerFactor,factorUno);
		printf(" \n");
	}
	else
    {
        printf("         No se puede factorizar el 1er operando: %.0f!\n",primerFactor);
		printf("         porque es un numero negativo.\n");
		printf(" \n");
    }

	if (segundoFactor>=0)
	{

		for (i = 1; i <= (int)segundoFactor; i++) {

			factorDos = factorDos * i;
		}
		printf("           El factorial de %.0f! es: %.2i             \n",segundoFactor,factorDos);
		printf(" \n");
	}
	else {
		printf("         No se puede factorizar el 2do operando: %.0f!\n",segundoFactor);
		printf("         porque es un numero negativo.\n");
	}

	return 0;
}

int getInt(int* y, int intentos, char* mes)
{
    int num;
    int todoOk;
    int contador = 0;

    printf("%s", mes);
    fflush(stdin);
    scanf("%d",&num);

    while(num <=0)
    {
        printf("ERROR. Reingrese un numero positivo: ");
        fflush(stdin);
        scanf("%d",&num);

        contador++;

        if(contador == intentos)
        {
            todoOk = 0;
            break;
        }
    }

    if(contador < 3)
    {
       *y = num;
       todoOk = 1;
    }

    return todoOk;
}

