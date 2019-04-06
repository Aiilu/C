#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void cargarMesa(int x[], int tam, int indice);
void descargarMesa(int x[], int tam, int indice);
void verEstMesa(int x[], int tam, int mesaOcupada);
void cargarValorConsumo(int x[], int tam, int indice, float valor, float consumo[]);
void totalizarConsumo(int x[], int tam, float valorTotal, float consumo[]);

int main()
{

    int mesas[TAM]={0};
    float precios[TAM]={0};
    //Inicializo el vector
    int contador = 0;
    float precio;
    int opcion;
    int posicion;

    do{
            system("cls");

    printf("*    Bienvenido al sistema de carga de consumos del restaurante    *\n");
    printf("*    Por favor ingrese una opcion para continuar:                  *\n");
    printf("*    1.Registrar mesa ocupada                                      *\n");
    printf("*    2.Registrar mesa desocupada                                   *\n");
    printf("*    3.Ver estado de las mesas                                     *\n");
    printf("*    4.Cagar valor de consumo de mesa desocupada                   *\n");
    printf("*    5.Totalizar valor total de consumo por mesa                   *\n");
    printf("*    6.Salir                                                       *\n");
    printf("*    ATENCION: Para totalizar el valor total por mesa, todas deben *\n");
    printf("*    estar desocupadas.                                            *\n");
    scanf("%d", &opcion);

    switch(opcion){

        case 1:
             cargarMesa(mesas,TAM,posicion);
            break;

        case 2:
             descargarMesa(mesas,TAM,posicion);
            break;

        case 3:
             verEstMesa(mesas,TAM,contador);
            break;

        case 4:
             cargarValorConsumo(mesas,TAM,posicion,precio,precios);
            break;

        case 5:
             totalizarConsumo(mesas,TAM,precio,precios);
             break;
        case 6:
            opcion = 6;
            break;

        default:
            printf("Opcion Incorrecta, por favor ingrese una opcion de nuevo: \n");
            break;
    }

    system("pause");
    }while( opcion != 6);
    return 0;
}

void cargarMesa(int x[], int tam, int indice)
{
    //no hago un for por que el usuario elije cuando cargar
    printf("Ingrese el numero de la mesa a ocupar: ");
    scanf("%d",&indice); //guardo el valor, y valido

    indice = indice -1; //va del 1 al 50, pero empieza en 0, asi va del 0 al 49

    if(indice <0 || indice >= tam)
    {
        printf("Esta mesa no existe\n");
    }
    else if(x[indice] == 0){
        x[indice] = 1;
        printf("Mesa entregada\n");
    }
    else
    {
        printf("Esta mesa ya ha sido ocupada\n");
    }

}

void descargarMesa(int x[], int tam, int indice)
{
    //no hago un for por que el usuario elije cuando cargar
    printf("Ingrese el numero de la mesa a desocupar: ");
    scanf("%d",&indice); //guardo el valor, y valido

    indice = indice -1; //va del 1 al 50, pero empieza en 0, asi va del 0 al 49

    if(indice <0 || indice >= tam)
    {
        printf("Esta mesa no existe\n");
    }
    else if(x[indice] == 1){
        x[indice] = 0;
        printf("Mesa desocupada\n");
    }
    else
    {
        printf("Esta mesa ya ha sido desocupada\n");
    }

}

void verEstMesa(int x[], int tam, int mesaOcupada)
{
    int i;
    printf("Las mesas ocupadas son la numero: \n");

    for(i=0;i<tam;i++)
    {
        if(x[i] == 1)
        {
            printf("%d\n",i+1);
            mesaOcupada++;
        }
    }

    printf("Y en total son %d mesa/s",mesaOcupada);
}

void cargarValorConsumo(int x[], int tam, int indice, float valor, float consumo[])
{
    //cuando entras aca, inicializo
    valor = 0;

    printf("Ingrese el numero de mesa a calcular :");
    scanf("%d",&indice);

    indice = indice -1;

    if(x[indice] !=0)
    {
        printf("Esta mesa no esta desocupada\n");
    }
    else
    {
        printf("Ingrese el monto a cargar de esta mesa: ");
        scanf("%f",&valor);

        //valor entra valiendo 0, y se le mueve a consumo el valor, si vuelvo a cargar
        //consumo queda con el mismo valor y el que se incializa de nuevo es el valor,
        //y asi, sucesivamente
        consumo[indice] = consumo[indice] + valor;

        printf("El valor ingresado de %.2f da un total de %.2f a la mesa numero %d\n",valor,consumo[indice],indice+1);
        }

}

void totalizarConsumo(int x[], int tam, float valorTotal, float consumo[])
{
    int i;
    valorTotal=0;
    int flag = 0;

    printf("Totalizando consumos...\n");

    for(i=0;i<tam;i++)
    {
        if(x[i] != 0)
        {
            flag ++;
        }
    }

    if(flag !=0)
    {
        printf("Hay %d mesas ocupadas/vacias\n",flag);
    }
    else
    {
        for(i=0;i<tam;i++)
        {
        valorTotal = valorTotal + consumo[i];
        }
    }
        printf("Valor total %d?n",valorTotal);
}
/*Un restaurante que dispone de 50 mesas, necesita llevar cuenta de las ventas diarias. Para
ello cada vez que una mesa es ocupada se registra el número de mesa y el valor de lo que van consumiendo.
Una vez que se cierra el local se deben obtener los siguientes resultados
a- Venta total del día
b- Indicar cuales fueron las mesas que no se ocuparon en todo el día.
c- Listado ordenado por venta que muestre Nro de mesa Venta
*/
