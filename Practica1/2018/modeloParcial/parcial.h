
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
}eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
}eSector;

int menu();
void inicializarEmpleados(eEmpleado[],int);
void mostrarEmpleado(eEmpleado[],int);
void mostrarEmpleados(eEmpleado[],int);
int buscarLibre(eEmpleado[],int);
void altaEmpleado(eEmpleado[],int);
