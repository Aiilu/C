#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int total;
}Employee;

Employee* employee_new();
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
void calcularSueldo(void* pp);
#endif // employee_H_INCLUDED
