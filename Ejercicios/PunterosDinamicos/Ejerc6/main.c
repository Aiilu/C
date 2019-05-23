#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    int codigo;
    float precio;
    int cantidad;
}eFarm;

int main()
{
    eFarm lista[] =
    {
        {4,50.00,2},
        {1,65.90,5},
        {5,78.00,8},
        {2,54.50,7},
        {3,100.50,10}
    };

    eFarm* pFarm;

    pFarm = lista;

    listXCod(pFarm,TAM);
    mostrarList(pFarm,TAM);
    codPrecioBajo(pFarm,TAM);

    return 0;
}

void listXCod(eFarm* pFarm, int tam)
{
    eFarm aux;

  for(int i=0; i < tam - 1; i++){
      for(int j= i+1; j < tam; j++ ){
          if( (pFarm+i)->codigo > (pFarm+j)->codigo){

            aux = *(pFarm+i);
            *(pFarm+i) = *(pFarm+j);
            *(pFarm+j) = aux;
          }
      }
      }
}

void mostrarList(eFarm* pFarm, int tam)
{

    printf("Codigo Precio Cant.Exist.\n");

    for(int i=0; i<tam; i++)
    {
        printf("  %d    %.2f         %d\n", (pFarm+i)->codigo,(pFarm+i)->precio,(pFarm+i)->cantidad);
    }
}

void codPrecioBajo(eFarm* pFarm, int tam)
{
  float minPrecio;
  int minCodigo;
  int flag = 0;

  for(int i=0;i<tam;i++)
  {
      if((pFarm+i)->precio < minPrecio || flag == 0)
      {
        minPrecio = (pFarm+i)->precio;
        minCodigo = (pFarm+i)->codigo;
        flag = 1;
      }
  }

  printf("Codigo del medicamente + barato: %d",minCodigo);
}

/*Se registran de los 50 medicamentos que existen en una farmacia el código de producto , el precio y la
cantidad en existencia. Se pide:
a- Listado ordenado por código de producto
b- Código del medicamento de precio más bajo*/
