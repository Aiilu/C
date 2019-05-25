#include <stdio.h>
#include <stdlib.h>

typedef struct
{
   int id;
   char marca[50];
   float cilindrado;
}eAuto;

void mostrarAuto(eAuto* lista);
void mostrarAutos(eAuto* lista, int tam);

int main()
{
    //mostrarAutos(lista,3);

    eAuto* lista =(eAuto*)malloc(sizeof(eAuto)*3);
    int cont = 0;
    int cant;

    FILE* f;

    f = fopen("./autos.dat","rb");

    if(f == NULL)
    {
        exit(1);
    }

    while(!feof(f))
    {
       cant = fread(lista+cont, sizeof(eAuto),1,f);

       if(cant < 1)
       {
           if(feof(f))
           {
               break;
           }
           else
           {
               printf("Se produjo un error al leer el archivo\n");
               break;
           }
       }

       cont++;

    }

    fclose(f);

    mostrarAutos(lista,cont);

    return 0;
}

void mostrarAuto(eAuto* lista)
{
    if(lista !=NULL)
    {
        printf("%d %s %.2f\n",lista->id,lista->marca,lista->cilindrado);
    }
}

void mostrarAutos(eAuto* lista, int tam)
{
     printf(" ID  Marca  Cilindrado\n");

     if(lista !=NULL && tam > 0)
     {
         for(int i=0; i<tam; i++)
         {
             mostrarAuto(lista+i);
             //no le paso *lista+i por que eso seria algo de eauto, y espera un puntero
         }
     }

     printf("\n\n");
}
