#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    char dni[128];

}eCliente;

typedef struct
{
    int idVenta;
    int idCliente;
    int codProd;
    int cant;
    float total;
}eVentas;

typedef struct
{
    int codigo;
    char descripcion[50];
    float precio;
}eProductos;

int ordenarXapellido(void* numA, void* numB);
void* calcularMonto(void* pp);
/*
eVendedor* employee_newParametros(char* idStr,char* nombreStr,char* nivelStr, char* cantProdStr, char* montoStr);
int filtrarNivelCero(void* x);
int filtrarNivelUno(void* x);
int filtrarNivelDos(void* x);
eVendedor* employee_new();
void calcularComision(void* pp);
void* calcularComision2(void* pp);
*/
/*eVendedor* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmpleado(Employee* pEmp);

int ordenarXid(void* numA, void* numB);
int ordenarXnombre(void* numA, void* numB);
int ordenarXhoras(void* numA, void* numB);
int ordenarXsueldo(void* numA, void* numB);

int darAlta(LinkedList*);
int ordenarEmpleados(LinkedList*);
int listarEmpleados(LinkedList*);
int darBaja(LinkedList*);
int darModificacion(LinkedList*);

int searchId(int id, LinkedList* pArrayEmp);
int generadorId(LinkedList* pArrayListEmployee);

void* modificarSueldo(void* pp);
void modificarSueldo2(void* pp);
int filtrarSueldo(void* x);
void em_calcularSueldo(void* p);
void calcularSueldo(void* pp);*/
#endif // employee_H_INCLUDED
