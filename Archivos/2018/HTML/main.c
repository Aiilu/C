#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;

    f = fopen("index.html", "r");

    if(f==NULL)
    {
        printf("Problemas al crear el archivo");
        exit(1);
    }

    while(!feof(f))
    {

    printf("%c",fgetc(f));
    //fprintf(f, "<html><head><title>Mi pagina web</title></head><body><h1>Esta es mi pagina puto</h1></body></html>");

    }

    fclose(f);

    return 0;
}
