#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void listXCod(int cod[],float precio[],int cantExist[],int tam);
void mostrarList(int cod[], float precio[],  int cantExist[], int tam);
void codPrecioBajo(float precio[], int codigo[], int tam);

int main()
{
    int codigo[TAM]={4,1,5,2,3};
    float precio[TAM]={50.00,65.90,78.00,54.50,100.50};
    int cantExist[TAM]={2,5,8,7,10};

    listXCod(codigo,precio,cantExist,TAM);
    mostrarList(codigo,precio,cantExist,TAM);
    codPrecioBajo(precio,codigo,TAM);

    return 0;
}

void listXCod(int cod[],float precio[],int cantExist[],int tam)
{
    int auxInt;
    float auxFloat;
    int i;
    int j;

  for( i=0; i < tam - 1; i++){
      for(j= i+1; j < tam; j++ ){
          if( cod[i] > cod[j]){

              auxFloat = precio[i];
          precio[i] = precio[j];
          precio[j] = auxFloat;

              auxInt = cantExist[i];
           cantExist[i] = cantExist[j];
           cantExist[j] = auxInt;

            auxInt = cod[i];
           cod[i] = cod[j];
           cod[j] = auxInt;

          }
      }
      }
}

void mostrarList(int cod[], float precio[],  int cantExist[], int tam)
{
    int i;

    printf("Codigo Precio Cant.Exist.\n");

    for(i=0; i<tam; i++)
    {
        printf("  %d    %.2f         %d\n", cod[i], precio[i], cantExist[i]);
    }
}

void codPrecioBajo(float precio[], int codigo[], int tam)
{
  int i;
  float minPrecio;
  int minCodigo;
  int flag = 0;

  for(i=0;i<tam;i++)
  {
      if(precio[i]<minPrecio || flag == 0)
      {
        minPrecio = precio[i];
        minCodigo = codigo[i];
        flag = 1;
      }
  }

  printf("Codigo del medicamente + barato: %d",minCodigo);
}

/*Se registran de los 50 medicamentos que existen en una farmacia el código de producto , el precio y la
cantidad en existencia. Se pide:
a- Listado ordenado por código de producto
b- Código del medicamento de precio más bajo*/
