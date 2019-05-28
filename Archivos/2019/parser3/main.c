#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int num3;
    int num4;
    int cant;

    FILE* f;

    f = fopen("./numeros.txt","r");

    if(f == NULL)
    {
        printf("No se puede abrir el archivo\n");
        system("pause");
        exit(1);
    }

    while(!feof(f))
    {
        cant = fscanf(f,"%d,%d,%d,%d\n",&num1,&num2,&num3,&num4);



        printf("%d %d %d %d\n",num1, num2, num3, num4);


           if(feof(f))
           {
               break;
           }

    }

    fclose(f);

    return 0;
}
