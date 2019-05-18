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
       //p = p+1;
       //preg si es diferente de \0, si no, muestra la letra siguiente, y ahi hace p++ y asi hasta
       //encontrar el \0
    }

    return 0;
}
