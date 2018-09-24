#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
          int v[TAM];
          int i;
          int resta;

          printf("Introduce los %d elementos a restar: ",TAM);

          for(i = 0; i<TAM; i++){
             scanf("%d",&v[i]); //escaneo mis numeros, y los guardo en cada iteracion en i.
          }
          resta=v[0];           //resta va a valer el primer valor del vector, osea en este caso 5;
          for(i=1;i<TAM;i++){   //con el for vas restandole las posiciones (EN ESTE CASO RESTA 1 VEZ);

             resta= resta-v[i];
		  }
printf("El resultado de la resta es: %d\n",resta);
    return 0;
}
