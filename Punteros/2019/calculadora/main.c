#include <stdio.h>
#include <stdlib.h>

/** \brief obtiene datos y los calcula
 *
 * \param float pide un valor
 * \return float valor del numero ingresado
 *
 */
float ingresarNumero();

/** \brief obtiene datos y los calcula
 *
 * \param float valores a sumar
 * \return float resultado de la suma
 *
 */
float sumar(float*, float*);

/** \brief obtiene datos y los calcula
 *
 * \param float valores a restar
 * \return float resultado de la resta
 *
 */
float restar(float*,float*);

/** \brief obtiene datos y los calcula
 *
 * \param float valores a multiplicar
 * \return float resultado de la multiplicacion
 *
 */
float multiplicar(float*,float*);

/** \brief obtiene datos y los calcula
 *
 * \param float valores a dividir
 * \return float resultado de la division
 *
 */
float dividir(float*,float*);

/** \brief obtiene datos y los calcula
 *
 * \param float valores a factorizar
 * \return float resultado de la factorizacion
 *
 */
float factorial(float*,float*);


int main()
{
    int opcion;
    char seguir = 's';
    float numA;
    float numB;
    int flagA = 0;
    int flagB = 0;
    int flag = 0;

    do{
      system ("COLOR F0");
      system("cls");
      printf("     =================================================\n");
      printf("     #            Trabajo Practico Nro. 1            #\n");
      printf("     #                                               #\n");
      printf("     #           >>>> MENU DE OPCIONES <<<<          #\n");
      printf("     =================================================\n");
      printf("     |                                               |\n");
      if(flagA == 1)
      {
          printf("          1- Ingresar 1er Operando (A=%.2f)            \n",numA);
      }
      else
      {
          printf("          1- Ingresar 1er Operando (A=x)              \n");
      }
      printf("     |                                               |\n");
      if(flagB == 1)
      {
          printf("          2- Ingresar 2do Operando (B=%.2f)           \n",numB);
      }
      else
      {
          printf("          2- Ingresar 2do Operando (B=y)              \n");
      }
      printf("     |                                               |\n");
      printf("          3- Calcular todas las Operaciones           \n");
      printf("     |                                               |\n");
      printf("          4- Informar resultados                      \n");
      printf("     |                                               |\n");
      printf("          5- Salir                                    \n");
      printf("     |                                               |\n");
      printf("     =================================================\n");
      printf("                                                     \n");
      printf("     Ingrese una opcion del menu: ");

      fflush(stdin);
      scanf("%d",&opcion);

      switch(opcion)
      {
      case 1:
          numA=ingresarNumero();
          flagA=1;
        break;
      case 2:
          numB=ingresarNumero();
          flagB=1;
        break;
      case 3:
          if (flagA == 1 && flagB == 1)
            {
                flag = 1;
                system("cls");
                printf("     ================================================\n");
                printf("     #                  Calculando...               #\n");
                printf("     ================================================\n");
                printf("     |                                              |\n");
                printf("           La suma de %.2f + %.2f                     \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La resta de %.2f - %.2f                    \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La multiplicacion de %.2f * %.2f           \n",numA,numB);
                printf("     |                                              |\n");
                printf("           La division de %.2f / %.2f                 \n",numA,numB);
                printf("     |                                              |\n");
                printf("           El factorial de %.2f! y %.2f!              \n",numA,numB);
                printf("     |                                              |\n");
                printf("     ================================================\n");

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe ingresar los numeros!\n");
            }
        break;
      case 4:
          if(flagA == 1 && flagB == 1 && flag == 1)
          {
                system("cls");
                printf("     ================================================\n");
                printf("     #                  Resultados                  #\n");
                printf("     ================================================\n");
                printf("     |                                              |\n");
                printf("           El resultado de A+B es: %.2f        \n",sumar(&numA,&numB));
                printf("     |                                              |\n");
                printf("           El resultado de A-B es: %.2f        \n",restar(&numA,&numB));
                printf("     |                                              |\n");
                printf("           El resultado de A*B es: %.2f        \n",multiplicar(&numA,&numB));
                printf("     |                                              |\n");
                dividir(&numA,&numB);
                printf("     |                                              |\n");
                factorial(&numA,&numB);
                printf("     |                                              |\n");
                printf("     ================================================\n");

            }
            else
            {
                printf("\n\n");
                printf("     Primero debe calcular las operaciones!\n");
            }
        break;
      case 5:
                system("cls");

                seguir = 'n';
                printf("     ==========================================\n");
                printf("     #               Saliendo...              #\n");
                printf("     ==========================================\n");
                printf("     |                                        |\n");
                printf("     |              Hasta luego!!!            |\n");
                printf("     |                                        |\n");
                printf("     ==========================================\n");

        break;
      default:
               printf("\n\n");
               printf("     ERROR. Esta opcion no es valida\n");

        break;
      }

      fflush(stdin);
      printf("     Presione ENTER para continuar");
      getchar();

    }while(seguir == 's');

    return 0;
}

float ingresarNumero()
{
    float valor;

    printf("\n\n");
    printf("     Ingrese un numero: ");
    fflush(stdin);
    scanf("%f",&valor);

    return valor;
}

float sumar(float* sumaUno, float* sumaDos)
{
    float suma;

    suma = *sumaUno + *sumaDos;

    return suma;
}

float restar(float* restaUno, float* restaDos)
{
    float resta;

    resta = *restaUno - *restaDos;

    return resta;
}


float multiplicar(float* multUno, float* multDos)
{
    float multiplicacion;

    multiplicacion = *multUno * *multDos;

    return multiplicacion;
}

float dividir(float* dividUno, float* dividDos)
{
    float division;

    if(dividDos !=0)
    {
        division = *dividUno / *dividDos;

        printf("           El resultado de A/B es: %.2f               \n",division);
    }
    else
    {
        printf("           No es posible dividir por cero.            \n");
    }

    return division;
}


float factorial(float* primerFactor, float* segundoFactor)
{
	int factorUno = 1, factorDos = 1, i;

	if (*primerFactor>=0)
	{
		for (i = (int)*primerFactor; i >= 1; i--)
		{
			factorUno = factorUno * i;
		}
		printf("           El factorial de A! es: %.2i             \n",factorUno);
		printf(" \n");
	}
	else
    {
        printf("         No se puede factorizar el 1er operando: A!\n");
		printf("         porque es un numero negativo.\n");
		printf(" \n");
    }

	if (*segundoFactor>=0)
	{

		for (i = 1; i <= (int)*segundoFactor; i++) {

			factorDos = factorDos * i;
		}
		printf("           El factorial de B! es: %.2i             \n",factorDos);
		printf(" \n");
	}
	else {
		printf("         No se puede factorizar el 2do operando: B!\n");
		printf("         porque es un numero negativo.\n");
	}

	return 0;
}
