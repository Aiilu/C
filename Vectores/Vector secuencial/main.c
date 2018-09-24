#include <stdio.h>
#include <stdlib.h>

//Carga secuencial: //los carga a medida de como los ingresaste

int main ()
{
int vector[5];
int i;
for(i=0;i<5;i++)  //en cada subindice carga el numero que ingresas
{
printf("Ingrese un numero");
scanf("%d", &vector[i]); //si ponemos algo, desborda, no le pertenece al vector
}
for(i=0;i<5;i++)
{
printf("%d\n", vector[i]);
}
printf("Numeros pares:");
for(i=0;i<5;i++)
{
    if(vector[i]%2==0)
{
printf("%d\n", vector[i]); //imprime numeros pares
}
}
return 0;
}
/*Ej:
Muestra de pares
printf("Numeros pares:");
for(i=0;i<5;i++)
{if(vector[i]%2==0)
{
printf("%d\n", vector[i]);
}
*/
