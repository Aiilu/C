#include <stdio.h>
#include <stdlib.h>

/*
typedef
int id;
char nombre;
char apellido;
float sueldo;
*/
int main()
{
    /*char cad[30];
    char cad2[30];
    char auxCad3[30];
    char auxCad4[30];*/

    //struct * malloc
    //*aux

    char buffer[4][30];

    //int cont = 0;

    int cant;

    FILE* f;

    f = fopen("./numeros.txt","r");

    if(f == NULL)
    {
        printf("No se puede abrir el archivo\n");
        system("pause");
        exit(1);
    }

    //1.ACA VA EL FSCANF
    //2. el printf sin los atoi y atof, que me quede como encabezado, todo puro %s

    while(!feof(f))
    {
       // cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n],\n",cad,cad2,auxCad3,auxCad4);

       //ULT. Cada que  lea, lo cargo aca, y la prox te hago un reallox de uno, y agrando el array y cargo, asi sucesiamente
       cant = fscanf(f,"%[^,],%[^,],%[^,],%[^\n],\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        //para el espacio en blanco, %[^ ];
        //esto tamb se puede usar en el scanf, y se levanta como cadena

        //el simbolo raro era por que desbordaba, por eso cambia el tam 20 a 30

        //este se va
        printf("%d %s %s %.2f\n",atoi(buffer[0]), buffer[1], buffer[2], atof(buffer[3]));

        //https://mockaroo.com/
        if(cant <4)
        {
             if(feof(f))
           {
               break;
           }
           else
           {
               printf("Archivo corrupto\n");
               break;
           }
        }

    }

    //ACA VA EL PRIIINTTTF con el atoi y  atof

    fclose(f);

    return 0;
}
