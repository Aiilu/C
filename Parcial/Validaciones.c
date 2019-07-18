#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Validaciones.h"

//VALIDAR TELEFONO

/** \brief Recorre la cadena buscando que cada uno de sus chars cumpla las condiciones para ser un telefono
 *
 * \param str char*
 * \return int
 *
 */
int funcion_ValidarTelefono(char* str)
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

/** \brief Valida que el dato no venga vacio y llama a la funcion que valida que sea un telefono
 *
 * \param x char*
 * \return void
 *
 */
void validarTel(char* x)
{
    while(strlen(x)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_ValidarTelefono(x))
        {
            printf(" Reingrese un telefono en formato xxxx-xxxx: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}


/** \brief Recorre la cadena buscando que cada uno de sus chars cumpla las condiciones para ser un email
 *
 * \param str char*
 * \return int
 *
 */
int funcion_validarEmail(char* str)
{
    int i=0;
    int contadorArroba=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9') && (str[i] != '@') && (str[i] != '.')&& (str[i] != '_')&& (str[i] != '-')&& (str[i] != '/'))
            return 0;
        if(str[i] == '@')
            contadorArroba++;

        i++;
    }
    if(contadorArroba==1) // debe tener un guion
        return 1;
    return 0;
}

/** \brief Valida que el dato no venga vacio y llama a la funcion que valida que sea un email
 *
 * \param x char*
 * \return void
 *
 */
void validarEmail(char* x)
{
    while(strlen(x)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_validarEmail(x))
        {
            printf(" Reingrese un Email valido: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo, si no muestra mensaje de error
 *
 * \param x char*
 * \return int
 *
 */
int validarString(char* x)
{
    int retorno = 0;

    if(x !=NULL)
    {
        while(strlen(x)<=0)
        {
            printf(" El campo no puede estar vacio: ");
            fflush(stdin);
            gets(x);
        }

        for(int i=0; i<strlen(x); i++)
        {
            while((isalpha(x[i]) == 0 && x[i] != '-' && x[i] != ' ') || strlen(x)>51 || (x+0) == '\0')
            {
                printf(" Reingrese solo caracteres alfabeticos: ");
                fflush(stdin);
                gets(x);
                i=0;
            }
        }

        retorno = 1;
    }

    return retorno;
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo y que no sobrepase el tamaño indicado, si no muestra mensaje de error
 *
 * \param x char*
 * \param largo int
 * \return void
 *
 */
int validarStringTam(char* x, int largo)
{
    int retorno = 0;

    if(x !=NULL)
    {
        while(strlen(x)<=0)
        {
            printf(" El campo no puede estar vacio: ");
            fflush(stdin);
            gets(x);
        }

        for(int i=0; i<strlen(x); i++)
        {
            while((isalpha(x[i]) == 0 && x[i] != '-' && x[i] != ' ')|| strlen(x)>largo || (x+0) == '\0')
            {
                printf(" Reingrese solo caracteres alfabeticos > %d: ",largo);
                fflush(stdin);
                gets(x);
                i=0;
            }
        }

        retorno = 1;
    }

    return retorno;
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero y que no sobrepase el tamaño indicado
 *
 * \param entero char*
 * \param largo int
 * \return int
 *
 */
int validarEnteroTam(char* entero, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || strlen(entero)>largo)
        {
            printf(" Reingrese un valor numerico y positivo >%d: ",largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero
 *
 * \param entero char*
 * \return int
 *
 */
int validarEntero(char* entero)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.')
        {
            printf(" Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}



/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a cero o positivo, si no muestra mensaje de error
 *
 * \param sueldo char*
 * \return float
 *
 */
float validarFloat(char* sueldo)
{
    float sueldoK;

    while(strlen(sueldo)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(sueldo);
    }

    for(int i=0; i<strlen(sueldo); i++)
    {

        sueldoK = atof(sueldo);

        while(isalpha(sueldo[i]) != 0 || sueldoK <= 0 || sueldo[i] == ' ')
        {
            printf(" Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(sueldo);
            i=0;
            //comapunto(sueldo);
            sueldoK = atof(sueldo);
        }

    }

    return sueldoK;
}


/** \brief  Recorre la cadena buscando una coma, en el caso de encontrarla la reemplaza por un punto, de forma que se permita ingresar un salario con coma
 *
 * \param sueldo[] char
 * \return void
 *
 */
/*void comapunto(char sueldo[])
{
    char coma=',';
    char punto='.';

    for (int i=0; i<strlen(sueldo); i++)
    {
        if (sueldo[i] == coma)
        {
            sueldo[i] = punto;
        }
    }
}*/


/** \brief Valida que el sexo ingresado sea "f" o "m", en caso de ingresar algo diferente, muestra mensaje de error
 *
 * \return char
 *
 */
char validarSexo()
{
    char sexos;

    printf(" Ingrese sexo f/m: ");
    fflush(stdin);
    sexos = getchar();
    sexos = toupper(sexos);

    while(sexos != 'F'  && sexos !='M' && sexos !='f' && sexos !='m')
    {
        printf(" ERROR. Esta opcion no es valida\n");
        printf(" Ingrese f/m: ");
        fflush(stdin);
        sexos = getchar();
        sexos = toupper(sexos);
    }

    return sexos;
}


/** \brief Pregunta si desea continuar, en caso de ingresar algo diferente a "s" o "n", muestra mensaje de error
 *
 * \return char
 *
 */
char validarSeguir()
{
    char seguir;

    printf(" Esta seguro? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf(" ERROR. Esta opcion no es valida\n");
        printf(" Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}

/** \brief Compara fechas ingresadas
 *
 * \param fech eFecha
 * \param fecha eFecha
 * \return int
 *
 */
/*int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}*/


/** \brief Valida que lo ingresado sea alfanumerico, solo letras, numero o un espacio entre ellos
 *
 * \param x char*
 * \param largo int
 * \return void
 *
 */
void validarAlfaNum(char* x, int largo)
{

    while(strlen(x)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(strlen(x)>largo || (x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z') && (x[i] < '0' || x[i] > '9') && x[i] != ' ')
        {
            printf(" Reingrese solo caracteres alfanum >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}


/** \brief Valida que la patente sea alfanumerica
 *
 * \param x char*
 * \return void
 *
 */
void ValidarPatente(char* x)
{

    for(int i=0; i<=2; i++)
    {
        while(strlen(x)!=6)
        {
            printf(" La patente deben ser 3 letras y 3 numeros: ");
            fflush(stdin);
            gets(x);
        }
        for(int j=3; j<strlen(x); j++)
        {
            while((x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z'))
            {
                printf(" Reingrese patente valida, 3 letras y 3 numeros: ");
                fflush(stdin);
                gets(x);
            }
            while(x[j] < '0' || x[j] > '9')
            {
                printf(" Reingrese patente valida: ");
                fflush(stdin);
                gets(x);
            }
        }

    }
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero y que esten entre el maximo y minimo ingresado
 *
 * \param entero char*
 * \param corto int
 * \param largo int
 * \return int
 *
 */
int validarEnteroFecha(char* entero, int corto, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf(" Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


/** \brief Recorre la cadena buscando que cada uno de sus chars sea igual a positivo o cero y que no sobrepase el tamaño indicado
 *
 * \param entero char*
 * \param corto int
 * \param largo int
 * \return int
 *
 */
int validarEnteroRango(char* entero, int corto, int largo)
{
    int entero1;

    while(strlen(entero)<=0)
    {
        printf(" El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf(" Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}


/** \brief Valida una fecha ingresada, segun el mes ingresado, se fija si el dia esta entre los parametros correctos, si no muestra un mensaje de error
 *
 * \param
 * \param
 * \return
 *
 */
/*         printf("Fecha de Inicio\n");

            printf("Ingrese anio: ");
            fflush(stdin);
            gets(valAnio);

            tra[indice].fechaTrabajo.anio = validarEnteroRango(valAnio,2019,2080);

            printf("Ingrese mes: ");
            fflush(stdin);
            gets(valMes);

            tra[indice].fechaTrabajo.mes = validarEnteroRango(valMes,1,12);

            printf("Ingrese dia: ");
            fflush(stdin);
            gets(valDia);

            if (tra[indice].fechaTrabajo.mes == 4 ||tra[indice].fechaTrabajo.mes == 6 || tra[indice].fechaTrabajo.mes == 9 || tra[indice].fechaTrabajo.mes == 11)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,30);
            }
            else if(tra[indice].fechaTrabajo.mes == 2)
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,28);
            }
            else
            {
                tra[indice].fechaTrabajo.dia = validarEnteroRango(valDia,1,31);
            }
*/

int revisarAuto(char* x)
{
    int retorno = 0;
    int cont=0;
    int cont1=0;
    int cont2=0;

    if(x !=NULL)
    {
        for(int i=0; i<=2; i++)
        {
            if(0<strlen(x))
            {
                cont++;
            }
            for(int j=3; j<strlen(x); j++)
            {
                if((x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z'))
                {
                    cont1++;
                }
                if(x[j] < '0' || x[j] > '9')
                {
                    cont2++;
                }
            }

        }

        if(cont == 0 || cont1 == 0 || cont2 == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}


int revisarMoto(char* x)
{
    int retorno = 0;
    int cont=0;
    int cont1=0;
    int cont2=0;

    if(x !=NULL)
    {
        for(int i=0; i<=2; i++)
        {
            if(0<strlen(x))
            {
                cont++;
            }
            for(int j=3; j<strlen(x); j++)
            {
                if(x[j] < '0' || x[j] > '9')
                {
                    cont1++;
                }
                if((x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z'))
                {
                    cont2++;
                }
            }

        }

        if(cont == 0 || cont1 == 0 || cont2 == 0)
        {
            retorno = 1;
        }
    }

    return retorno;
}
