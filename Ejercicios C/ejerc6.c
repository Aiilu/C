#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int cont=0;
    int contMayores=0;
    int contMenores=0;

    while (cont<5) {
        cont ++;

        printf ("Ingrese el N°: ");
        scanf ("%d",&num);

      if (num<=0) {
        contMenores++;
      }
      else {
        contMayores++;
      }
   }
    printf ("Hay %d N° Positivos.\n Hay %d N° Negativos", contMayores, contMenores);

         return 0;
}
