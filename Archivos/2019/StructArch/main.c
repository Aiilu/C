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
    eAuto auto1 = {1234, "Ford", 1.6};
    eAuto auto2 = {1222, "Renault", 1.8};
    eAuto auto3 = {5555, "Peugeot", 1.2};

    eAuto* lista = (eAuto*)malloc(sizeof(eAuto)*3);

    *lista = auto1;
    *(lista+1) = auto2;
    *(lista+2) = auto3;

    //mostrarAutos(lista,3);

    FILE* f;

    f = fopen("./autos.dat","wb");

    if(f == NULL)
    {
        exit(1);
    }

    //fwrite(lista, sizeof(eAuto), 3, f);

    for(int i=0; i<3; i++)
    {
        fwrite(lista+i, sizeof(eAuto), 1, f);
        //guardo en un variable a ver si es igual al valor 1, si es igula todo ok
        //si no es igual, error
    }

    printf("Logre escribir\n");

    fclose(f);

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
