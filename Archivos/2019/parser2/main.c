#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[] = {3,2,4,5,2,6,5,4,7,1,9,3};

    FILE* f;

    f = fopen("./numeros.txt","w");

    if(f == NULL)
    {
        printf("Es NULL\n");
        system("pause");
        exit(1);
    }

       /*  fprintf(f,"%d,%d,%d,%d\n",numeros[0],numeros[1],numeros[2],numeros[3]);
         fprintf(f,"%d,%d,%d,%d\n",numeros[4],numeros[5],numeros[6],numeros[7]);
         fprintf(f,"%d,%d,%d,%d\n",numeros[8],numeros[9],numeros[10],numeros[11]);*/

         for(int i=0; i<12; i++)
         {
             if((i+1)%4!=0)
             {
                fprintf(f,"%d,",numeros[i]);
             }
             else
             {
                 fprintf(f,"%d\n",numeros[i]);
             }
         }

    printf("Logre escribir\n");

    fclose(f);
    return 0;
}
