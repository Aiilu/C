#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cadena[20]={"Aguante Cobol"};

    char* p;

    p = cadena;

    //p = &cadena[0];  --> es la dir. de mem. en el primer indice

    while( *p != '\0')
    {
       printf("%c", *p);
       p++;
    }

    return 0;
}
