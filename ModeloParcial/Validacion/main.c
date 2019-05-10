#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

int main()
{

    /*char email[20];

    printf("Ingrese un email: ");
    fflush(stdin);
    gets(email);

    validarEmail(email);

    printf("Email: %s",email);*/

    /*char tel[50];

    printf("Ingrese un telefono: ");
    fflush(stdin);
    gets(tel);

    validarTel(tel);

    printf("Telefono: %s ",tel);*/

    /*char nombre[5];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);

    validarStringTam(nombre,5);

    printf("Nombre: %s",nombre);*/

    /*char edad[4];
    int edadEdad;

    printf("Ingrese su hermosa edad: ");
    fflush(stdin);
    gets(edad);

    edadEdad = validarEnteroTam(edad,4);

    printf("Tu edad es: %d",edadEdad);*/

    eFecha fech;
    char dia[3];
    char mes[3];
    char anio[4];
    int fechaCorrecta = -1;

    printf("Ingrese dia: ");
    fflush(stdin);
    gets(dia);

    fech.dia = validarEnteroFecha(dia,1,31);

    printf("Ingrese mes: ");
    fflush(stdin);
    gets(mes);

    fech.mes = validarEnteroFecha(mes,1,12);

    printf("Ingrese anio: ");
    fflush(stdin);
    gets(anio);

    fech.anio = validarEnteroTam(anio,4);

    printf("FECHA: %d %d %d",fech.dia,fech.mes,fech.anio);

    /*char direccion[5];

    printf("Ingrese una direccion: ");
    fflush(stdin);
    gets(direccion);

    validarAlfaNum(direccion,5);

    printf("Direccion: %s",direccion);*/

    return 0;
}

//VALIDAR FECHA



//VALIDAR TELEFONO

int funcion_ValidarTelefono(char str[])
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

void validarTel(char x[])
{
    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_ValidarTelefono(x))
        {
            printf("     Reingrese un telefono en formato xxxx-xxxx: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR EMAIL

int funcion_validarEmail(char str[])
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

void validarEmail(char x[])
{
    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(!funcion_validarEmail(x))
        {
            printf("     Reingrese un Email valido: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR NOMBRE

void validarString(char x[])
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0 || strlen(x)>51 || x[0] == '\0')
        {
            printf("     Reingrese solo caracteres alfabeticos <51: ");
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR NOMBRE CON MIN/MAX

void validarStringTam(char x[], int largo)
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(isalpha(x[i]) == 0 || strlen(x)>largo || x[0] == '\0')
        {
            printf("     Reingrese solo caracteres alfabeticos >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR INT CONT MIN

int validarEnteroTam(char entero[], int largo)
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || strlen(entero)>largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d: ",largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}

//VALIDAR INT
int validarEntero(char entero[])
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1)
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}

//VALIDAR FLOAT

float validarFloat(char sueldo[])
{
    float sueldoK;

    while(strlen(sueldo)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(sueldo);
    }

    for(int i=0; i<strlen(sueldo); i++)
    {

        sueldoK = atof(sueldo);

        while(isalpha(sueldo[i]) != 0 || sueldoK <= 0 || sueldo[i] == ' ')
        {
            printf("     Reingrese un valor numerico y positivo: ");
            fflush(stdin);
            gets(sueldo);
            i=0;
            comapunto(sueldo);
            sueldoK = atof(sueldo);
        }

    }

    return sueldoK;
}

//VALIDAR SEXO

char validarSexo()
{
    char sexos;

    printf("     Ingrese sexo f/m: ");
    fflush(stdin);
    sexos = getchar();
    sexos = toupper(sexos);

    while(sexos != 'F'  && sexos !='M' && sexos !='f' && sexos !='m')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Ingrese f/m: ");
        fflush(stdin);
        sexos = getchar();
        sexos = toupper(sexos);
    }

    return sexos;
}

//VALIDAR SEGUIR

char validarSeguir()
{
    char seguir;

    printf("     Desea continuar? s/n: ");
    fflush(stdin);
    seguir = getchar();
    seguir = toupper(seguir);

    while(seguir != 'S'  && seguir !='N' && seguir !='n' && seguir !='s')
    {
        printf("     ERROR. Esta opcion no es valida\n");
        printf("     Desea continuar? s/n: ");
        fflush(stdin);
        seguir = getchar();
        seguir = toupper(seguir);
    }

    return seguir;
}

//FUNCION COMA_PUNTO

void comapunto(char sueldo[])
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
}

//COMPARAR FECHAS

int compararFechas(eFecha fech, eFecha fecha)
{
    int igual = 0;

    if(fech.dia == fecha.dia && fech.mes == fecha.mes && fech.anio == fecha.anio)
    {
        igual = 1;
    }
    return igual;
}

//VALIDAR DIRECCION

void validarAlfaNum(char x[], int largo)
{

    while(strlen(x)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(x);
    }

    for(int i=0; i<strlen(x); i++)
    {
        while(strlen(x)>largo || (x[i] < 'a' || x[i] > 'z') && (x[i] < 'A' || x[i] > 'Z') && (x[i] < '0' || x[i] > '9') && x[i] != ' ')
        {
            printf("     Reingrese solo caracteres alfanum >%d: ",largo);
            fflush(stdin);
            gets(x);
            i=0;
        }
    }
}

//VALIDAR INT CONT MIN/MAX

/*int validarEnteroFecha(char entero[], int corto, int largo)
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}*/

int validarEnteroFecha(char entero[], int corto, int largo)
{
    int entero1;

        while(strlen(entero)<=0)
    {
        printf("     El campo no puede estar vacio: ");
        fflush(stdin);
        gets(entero);
    }

    for(int i=0; i<strlen(entero); i++)
    {

        entero1 = atoi(entero);

        while(isalpha(entero[i]) != 0 || entero1 <= 0 || entero[i] == ' ' || entero[i] == ',' || entero[i] == '.' || entero1 < corto || entero1 > largo)
        {
            printf("     Reingrese un valor numerico y positivo >%d <%d: ",corto,largo);
            fflush(stdin);
            gets(entero);
            i=0;
            entero1 = atoi(entero);
        }

    }

    return entero1;
}

/*int funcion_ValidarFecha(eFecha fechas)
{
    int ret=0;

    if ( ((fechas.mes >= 1) && (fechas.mes <= 12)) )
    {
        switch ( fechas.mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( fechas.dia >= 1 && fechas.dia <= 31 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;

            }
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( fechas.dia >= 1 && fechas.dia <= 30 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;

        case  2 :
            if ( ((fechas.anio % 4 == 0) && (fechas.anio % 100 != 0)) || (fechas.anio % 400 == 0 ))
            {
                if ( fechas.dia >= 1 && fechas.dia <= 29 )
                {
                    ret=1;
                }
                else
                {
                    printf("Dia incorrecto\n\n");
                    system("pause");
                    ret=0;
                }

            }
            else if ( fechas.dia >= 1 && fechas.dia <= 28 )
            {
                ret=1;
            }
            else
            {
                printf("Dia incorrecto\n\n");
                system("pause");
                ret=0;
            }

            break;



        }

    }
    else
    {
        printf("Mes Ingresado es incorrecto\n\n");
        system("pause");
    }

    return ret;
}*/
