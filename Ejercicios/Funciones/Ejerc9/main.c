#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 3
int main()
{
    char nombre[T][20]={"Fulanito","Pepe","Camilo"};
    int peso[T]={65,70,40};
    float altura[T]={3.50,7.80,2.30};
    int acum = 0;
    int i;
    int cont = 0;
    float producto;
    float porcentaje;

    for(i=0;i<T;i++)
    {
          producto = peso[i]*altura[i];

          if(producto>50.3 || producto<80.5)
          {
              cont++;
              acum+=cont;
          }
    }

    porcentaje = acum/cont;

    printf("porcentaje: %f",porcentaje);

    return 0;
}

/*9- Se toman de 20 personas el nombre, peso y altura.
Se pide calcular el porcentaje de personas cuyo producto peso por altura se encuentra entre 50.3 y 80.5.
El peso y la altura deben ser validados por una función.*/
