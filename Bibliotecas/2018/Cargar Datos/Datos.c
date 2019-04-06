
int pedirEntero(void)
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    return numero;
}

float pedirFloat (void)
{
    float numero;

    printf("Ingrese un numero: ");
    scanf("%f", &numero);

    return numero;
}

void pedirString(char* dato)
{
    char buffer[1024];

    fflush(stdin);
    gets(dato);
    strcpy(buffer, dato);

    while (strlen(buffer)>19)
    {
        printf("Reingrese dato: ");
        fflush(stdin);
        gets(dato);
        strcpy(buffer, dato);
    }
    strcpy(dato, buffer);
}
