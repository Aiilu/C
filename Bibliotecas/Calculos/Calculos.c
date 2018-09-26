#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

void ingresarOpcion(float* pNumero)
{
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%f", pNumero);
}

float sumar(float sumaUno, float sumaDos)
{
	float suma;
	suma = sumaUno + sumaDos;
	return suma;
}

float restar(float restaUno, float restaDos)
{
	float resta;
	resta = restaUno - restaDos;
	return resta;
}

float multiplicar(float multiplicarUno, float multiplicarDos)
{
	float multiplicar;
	multiplicar = multiplicarUno*multiplicarDos;
	return multiplicar;
}
float dividir(float dividirUno, float dividirDos)
{
	float division;
	if (dividirDos != 0)
	{
		division = dividirUno / dividirDos;

		printf("\n El resultado de A/B es: %.2f \n", division);

		return division;
	}
	else
	{
		printf("\n No es posible dividir por cero. \n");
	}

	return 0;
}

float factorial(float primerFactor, float segundoFactor)
{
	int factorUno = 1, factorDos = 1, i;

	if (primerFactor>0)
	{
		for (i = (int)primerFactor; i >= 1; i--)
		{
			factorUno = factorUno * i;
		}
		printf("El factorial de A! es: %.2i\n", factorUno);
	}
	else {
		printf("No se puede calcular A!, no se factoriza un numero negativo o el numero 0\n");
	}

	if (segundoFactor>0)
	{

		for (i = 1; i <= (int)segundoFactor; i++) {

			factorDos = factorDos * i;
		}
		printf("El factorial de B! es: %.2i\n", factorDos);
	}
	else {
		printf("No se puede calcular B!, no se factoriza por un numero negativo o el numero 0\n");
	}

	return 0;
}
