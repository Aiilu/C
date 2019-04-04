#include <stdio.h>
#include <stdlib.h>

void calcular(int,int,int);

int main()
{
    int numero1;
    int numero2;
    int numero3;

    printf("Ingrese un primer numero: ");
    scanf("%d",&numero1);

    printf("Ingrese un segundo numero: ");
    scanf("%d",&numero2);

    printf("Ingrese un tercer numero: ");
    scanf("%d",&numero3);

    calcular(numero1,numero2,numero3);

    return 0;
}

void calcular(int a,int b,int c)
{
     if (a >= b && a >= c )
    {
        printf("El mayor es el primer num: %d",a);
    }

    else if ( b >= a && b >= c )
    {
            printf("El mayor es el segundo num: %d",b);
    }

    else if ( c >= a && c >= b )
    {
            printf("El mayor es el tercer num: %d",c);
    }
}

/*ordenar de mayor a menor

if (a >= b && a >= c )
    {
        if (b >= c )
        {
         printf("%d , %d , %d .", a , b , c );
        } else if ( c >= b)
        {
         printf("%d , %d , %d .", a , c , b );
        }
    } else if ( b >= a && b >= c )
    {
        if( a >= c )
        {
            printf("%d , %d , %d .", b , a , c );
        }else if ( c >= a)
        {
            printf("%d , %d , %d .", b , c , a );
        }
    }else if ( c  >= a && c >= b )
    {
        if ( a >= b )
        {
            printf("%d , %d , %d .", c , a , b );
        }else if ( b >= a )
        {
            printf("%d , %d , %d .", c , b , a );
        }
    }
    */

/*. De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor*/
