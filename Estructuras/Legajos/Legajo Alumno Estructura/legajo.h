#ifndef legajo

typedef struct
{
    int legajos;
    char nombres[21];
    char sexos[15];
    float alturas;
    int notas;
} sAlumno;

void menuOpcion(sAlumno[]);
sAlumno cargarUnAlumno();
void mostrarUnAlumno(sAlumno);
void cargarAlumnos(sAlumno[],int);
void mostrarAlumnos(sAlumno[],int);
void ordenarAlfabeticamente(sAlumno[],int);
//void ordenarPorSexo(sAlumno[],int);
void alumnosAprobados(sAlumno[],int);
void alumnosDesaprobados(sAlumno[],int);
void alumnoLlamadoJuan(sAlumno[],int);
void validarNombreConP(sAlumno[],int);
void notasMaximas(sAlumno[],int);
void alumnoMasMediocre(sAlumno[],int);
void alumnosMinimoPromedio(sAlumno[],int);
void alumnosMaximoPromedio(sAlumno[],int);
void porcentAlumAprobDesap(sAlumno[],int);
void alumnosPromSeis(sAlumno[],int);
//GRAFICO
void modificarListado(sAlumno[],int);

#endif // legajo
