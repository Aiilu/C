#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

    char nombre[20];
    char apellido[20];
    char nombreCompleto[41]="";//ahi se inicializa a nada
    char buffer[1024];//variab que va a guardar cosas, para que pueda entrar todo lo que va a guardar
    int i;
    printf("Ingrese su nombre: ");
  fflush(stdin);
  //gets(nombre);
 gets(buffer);
  while(strlen(buffer)>19)
  {
      printf("Reingrese nombre:");
      fflush(stdin);
      gets(buffer);
  }
  strcpy(nombre,buffer);

   printf("Ingrese su apellido: ");
  fflush(stdin);
  //gets(nombre);
 gets(buffer);

  while(strlen(buffer)>19)
  {
      printf("Reingrese apellido:");
      fflush(stdin);
      gets(buffer);
  }
  strcpy(apellido,buffer);

  strcat(nombreCompleto, apellido);
  //tamb se puede usar el strcpy(nombreCompleto, apellido);
 // puts(nombreCompleto); para comprobar, hay basura
  strcat(nombreCompleto, ", ");
  strcat(nombreCompleto, nombre);

  strlwr(nombreCompleto); //paso todo a minuscula

  //1 opcion.
  nombreCompleto[0]=toupper(nombreCompleto[0]); //caracter, toma el valor ascii,lo devuelve y lo guarda.
                                //le estoy pasando solo un elemento, por valor

 for(i=0;i<strlen(nombreCompleto);i++)
 {
     if(nombreCompleto[i]==' ')//me devuelve un caracter,le mando el espacio
     { //isspace(nombreCompleto[i]));
         nombreCompleto[i+1]=toupper(nombreCompleto[i+1]); //dsp del espcio convierto a mayusucula
 }
 //2 opcion, en cada opcion preg por otra iteracion el if, no conviene
 }
  puts(nombreCompleto);





    return 0;
}
