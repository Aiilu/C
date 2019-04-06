#include <stdio.h>
#include <stdlib.h>

int main()
{
   int* pNumero;

   pNumero = (int*) malloc(sizeof(int));

   if(pNumero == NULL)
   {
       printf("No se consiguio memoria");
       exit(1);
   }

   *pNumero = 5;

   printf("%d\n", *pNumero);

   free(pNumero);

    return 0;
}
