#include <stdio.h>
#include <stdlib.h>
int main()
{
    float radio;
    float area;
    float longitud;

    printf ("Ingrese radio: ");
    scanf ("%f",&radio);

    area = 3.1415926536*radio*radio;

    longitud = (2*3.1415926536)*radio;

   printf ("El area es de %.2f\n La longitud es de %.2f",area,longitud);

      return 0;
}
