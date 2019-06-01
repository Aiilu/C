#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    float sueldo;
} eEmpleado;

int menu();
eEmpleado* new_Empleado();
eEmpleado* new_EmpleadoParam(int, char*, char*, float);
int buscarLibre(eEmpleado** emp, int size);
void mostrarEmpleados(eEmpleado** emp, int size);
void mostrarEmpleado(eEmpleado* emp);
int altaEmpleado(eEmpleado** emp, int size);
void imprimirEmpleados(eEmpleado** emp, int size);
void guardarEmpleadosBinarios(eEmpleado** emp, int size);
int cargarEmpleado(eEmpleado** emp, int size);
int agrandarLista(eEmpleado** emp, int size);

int main()
{
    int size = 0;
    char seguir = 's';

    eEmpleado** lista = (eEmpleado**)malloc(sizeof(eEmpleado*)*sizeof(eEmpleado)); //pido lugar para un solo puntero
    //PUNTERO A EMP, A SI LO HAGO STRUCT DE PUNTERO, CON &
    //LISTA ES DOBLE PUNTERO, POR QUE ES UNA & QUE APUNTA A OTRA &
    //EMPLEADO ES **, POR QUE SE LO CASTEA COMO LA LISTA, QUE ES DOBLE PUNTERO

    if(lista == NULL)
    {
        printf("No se consiguio memoria\n");
        system("pause");
        exit(1);
    }

    do
    {
        switch(menu())
        {
        //verificar con r, por que no existe
        case 1:
           /* if(cargarEmpleado(lista,size)==0)
            {
                printf("No hay ningun .bin a levantar\n");
            }
            else
            {
                printf("Cargo exitosamente\n");
            }*/
            system("pause");
            break;
        case 2:
            if(altaEmpleado(lista,size)==1)
            {
                size++;

                if(agrandarLista(lista,size)==1)
                {
                    printf("Alta Exitosa!\n");
                }
                else
                {
                    printf("No lo logre\n");
                }
            }
            system("pause");
            break;
        case 3:
            printf("size4: %d",size);
            mostrarEmpleados(lista,size);
            system("pause");
            break;
        case 4:
            //guardarEmpleadosBinarios(lista,size);
            system("pause");
            break;
        case 5:
            imprimirEmpleados(lista,size);
            system("pause");
            break;
        case 6:
            printf("Hasta luego\n");
            system("pause");
            seguir = 'n';
            break;
        default:
            printf("Esta opcion no existe\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    free(lista);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("   Menu de Opciones\n");
    printf("1. Cargar Empleados\n");
    printf("2. Alta Empleado\n");
    printf("3. Listar Empleado\n");
    printf("4. Guardar empleados archivo\n");
    printf("5. Imprimir empleados\n"); //hacer un archivo de texto
    printf("6. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

eEmpleado* new_Empleado()
{
    eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(emp !=NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre," ");
        strcpy(emp->apellido," ");
        emp->sueldo = 0;
    }

    return emp;
}

eEmpleado* new_EmpleadoParam(int id, char* nombre, char* apellido, float sueldo)
{
    eEmpleado* emp = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(emp !=NULL)
    {
        emp->id = id;
        strcpy(emp->nombre,nombre);
        strcpy(emp->apellido,apellido);
        emp->sueldo = sueldo;
    }

    return emp;
}

/*int buscarLibre(eEmpleado** emp, int size)
{
    int indice = -1;

    if(emp !=NULL && size > 0)
    {
        for(int i=0; i<size; i++)
        {
            if((emp+i)->estado == 0)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}
*/

void mostrarEmpleados(eEmpleado** emp, int size)
{
    if(emp !=NULL && sizeof(size) > 0)
    {
        printf("Id  Nombre  Apellido  Sueldo\n");

        for(int i=0; i<sizeof(size); i++)
        {
                printf("Aca todo bien\n");
                mostrarEmpleado(*(emp+i));
                printf("Me muero aca\n");
        }
    }
}


void mostrarEmpleado(eEmpleado* emp)
{
    if(emp !=NULL)
    {
        printf("%d %s %s %.2f\n",emp->id,emp->nombre,emp->apellido,emp->sueldo);
    }
}



int altaEmpleado(eEmpleado** emp, int size)
{
    int todoOk = 0;
    int auxInt;
    char auxCad[20];
    char auxCad2[20];
    float auxFloat;

    if(emp !=NULL)
    {
            printf("Ingrese id: ");
            scanf("%d",&auxInt);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxCad);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxCad2);

            printf("Ingrese sueldo: ");
            scanf("%f",&auxFloat);

            eEmpleado* nuevoEmp = new_EmpleadoParam(auxInt,auxCad,auxCad2,auxFloat); //nos devuleve la &

            if(nuevoEmp !=NULL)
            {
                //el lugar donde lo quiero guardar
                *(emp + size) = nuevoEmp;

                todoOk = 1;
                //ACA NO LIBERO, XQ NO QUIERO LIBERARLO TODAVIA, LA NECESITO
                //DSP agrego mas espacio dsp del primer empleado;
            }
    }

    return todoOk;

}


void imprimirEmpleados(eEmpleado** emp, int size)
{
    FILE* f;

    if(emp !=NULL && size > 0)
    {
        f = fopen("./listaEmpleados.txt","w");

        if(f !=NULL)
        {
            fprintf(f,"Id  Nombre  Apellido  Sueldo\n");

            for(int i=0; i<size; i++)
            {

                    fprintf(f,"%d %s %s %.2f\n",(*(emp+i))->id,(*(emp+i))->nombre,(*(emp+i))->apellido,(*(emp+i))->sueldo);

            }

            fprintf(f,"\n\n");
        }

        fclose(f);
    }
}

/*
void guardarEmpleadosBinarios(eEmpleado** emp, int size)
{
    FILE* f;

    if(emp !=NULL && size > 0)
    {
        f = fopen("./empleados.bin","wb");

        if(f !=NULL)
        {
            for(int i=0; i<size; i++)
            {
                if((emp+i)->estado == 1)
                {
                    fwrite((emp+i),sizeof(eEmpleado),1,f);
                }
            }
        }

        fclose(f);
    }
}

int cargarEmpleado(eEmpleado** emp, int size)
{
    int retorno = 0;
    int indice;
    FILE* f;
    int cant;

    if(emp !=NULL)
    {
        f = fopen("./empleados.bin","rb");

        if(f !=NULL)
        {
            while(!feof(f))
            {
                //voy a leer de a uno hasta que llegue a fin de fichero
                indice = buscarLibre(emp,size);

                //si no lo lee, es x que esta corrupto o es eof
                cant = fread((emp+indice), sizeof(eEmpleado),1,f);

                if(cant < 1)
                {
                    if(feof(f))
                    {
                        break;
                    }
                    else
                    {
                        printf("Problemas para leer el archivo\n");
                    }
                }
            }

            retorno = 1;
        }

        fclose(f);
    }

    return retorno;

}

*/

int agrandarLista(eEmpleado** emp, int size)
{
    int todoOk = 0;
    eEmpleado** aux;
    int id;

    id = size+1;

    aux = (eEmpleado**)realloc(emp,sizeof(eEmpleado*)*id); //te paso esta lista que tiene 1, agregale 1 mas, y asi

    if(aux !=NULL)
    {
        emp = aux;
        todoOk = 1;
    }

    return todoOk;
}
