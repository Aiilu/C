#include <stdio.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* nuevoEmpleado;

    nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

    Employee* nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        employee_setId(nuevoEmpleado, atoi(idStr));
        employee_setNombre(nuevoEmpleado, nombreStr);
        employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr));
        employee_setSueldo(nuevoEmpleado, atoi(sueldoStr));
    }
    return nuevoEmpleado;
}
void employee_delete();

int employee_setId(Employee* this,int id)
{
    int okId = 0;
    if(this != NULL && id >0)
    {
        this->id = id;
        okId = 1;
    }
    return okId;
}

int employee_getId(Employee* this,int* id)
{
    int okId = 0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        okId = 1;
    }
    return okId;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int okNombre = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 128)
    {
        strcpy(this->nombre, nombre);
        okNombre = 1;
    }
    return okNombre;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int okNombre = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        okNombre = 1;
    }
    return okNombre;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int okHoras = 0;
    if(this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        okHoras = 1;
    }
    return okHoras;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int okHoras = 0;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        okHoras = 1;
    }
    return okHoras;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int okSueldo = 0;
    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        okSueldo = 1;
    }
    return okSueldo;
}
int employee_getSueldo(Employee* this,int* sueldo)
{

    int okSueldo = 0;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        okSueldo = 1;
    }
    return okSueldo;



}

void mostrarEmpleado(Employee* empleado)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(empleado != NULL)
    {
        if(employee_getId(empleado, &id) && employee_getNombre(empleado, nombre) && employee_getHorasTrabajadas(empleado, &horas) && employee_getSueldo(empleado, &sueldo))
        {
            printf("%4d %15s %4d %6d\n", id, nombre, horas, sueldo);
        }
    }
}

void printEmpleadoTexto(FILE* pFile, Employee* empleado)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(empleado != NULL)
    {
        if(employee_getId(empleado, &id) && employee_getNombre(empleado, nombre) && employee_getHorasTrabajadas(empleado, &horas) && employee_getSueldo(empleado, &sueldo))
        {
            fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
        }
    }
}

int employeeSortByName(void* empleadoA, void* empleadoB){

int retorno = 0;
Employee* empA;
Employee* empB;

if(empleadoA != NULL && empleadoB != NULL){
    empA = (Employee*) empleadoA;
    empB = (Employee*) empleadoB;
    retorno = strcmp(empA->nombre, empB->nombre);
}
return retorno;

}

int employeeSortById(void* empleadoA, void* empleadoB){

int retorno = 0;
Employee* empA;
Employee* empB;

if(empleadoA != NULL && empleadoB != NULL){
    empA = (Employee*) empleadoA;
    empB = (Employee*) empleadoB;
    if(empA->id < empB->id){
        retorno = 1;
    }else if(empA->id > empB->id){
        retorno = -1;
    }else{
        retorno = 0;
    }
}
return retorno;

}

int employeeSortByWorkHours(void* empleadoA, void* empleadoB){

int retorno = 0;
Employee* empA;
Employee* empB;

if(empleadoA != NULL && empleadoB != NULL){
    empA = (Employee*) empleadoA;
    empB = (Employee*) empleadoB;
    if(empA->horasTrabajadas < empB->horasTrabajadas){
        retorno = 1;
    }else if(empA->horasTrabajadas > empB->horasTrabajadas){
        retorno = -1;
    }else{
        retorno = 0;
    }
}
return retorno;

}

int employeeSortBySalary(void* empleadoA, void* empleadoB){

int retorno = 0;
Employee* empA;
Employee* empB;

if(empleadoA != NULL && empleadoB != NULL){
    empA = (Employee*) empleadoA;
    empB = (Employee*) empleadoB;
    if(empA->sueldo < empB->sueldo){
        retorno = 1;
    }else if(empA->sueldo > empB->sueldo){
        retorno = -1;
    }else{
        retorno = 0;
    }
}
return retorno;

}


