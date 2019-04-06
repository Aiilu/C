#ifndef legajo
#define VACIO -1
#define BAJA 0
#define LLENO 1
typedef struct
{
    int legajos;
    char nombres[21];
    char sexos[15];
    float alturas;
    int notas;
    int estado;
    char sexo;
    float promedio;
} sAlumno;

void menuOpcion(sAlumno[],int);
sAlumno cargarUnAlumno();
void mostrarUnAlumno(sAlumno);
void cargarAlumnos(sAlumno[],int);
void mostrarAlumnos(sAlumno[],int);
void ordenarAlfabeticamente(sAlumno[],int);
void ordenarPorSexo(sAlumno[],int);
void alumnosAprobados(sAlumno[],int);
void alumnosDesaprobados(sAlumno[],int);
void alumnoLlamadoJuan(sAlumno[],int);
void validarNombreConP(sAlumno[],int);
void notasMaximas(sAlumno[],int);
void alumnoMasMediocre(sAlumno[],int);
//GRAFICO
void modificarListado(sAlumno[],int);
void cargarIlogico(sAlumno[],int);
void darDeBaja(sAlumno[],int);
int buscarLibre(sAlumno[],int);
int cargarLibre(sAlumno[],int);
#endif // legajo
