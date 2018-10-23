#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* pNumero;

   pNumero = (int*) malloc(sizeof(int)*5);

   if(pNumero == NULL)
   {
       printf("No se consiguio memoria");
       exit(1);
   }
   int i;
   for(i=0;i<5;i++)
   {

   }
   *pNumero = 5;

   printf("%d\n", *pNumero);

   free(pNumero);

    return 0;
}
