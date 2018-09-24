#include <stdio.h>
#include <stdlib.h>
#define T 10
int main()
 {

 int vector[T]={4,2,3,1,5,34,33,8,9,12};
int i;
int j;
int aux;

for(i=0; i<T-1; i++)
	{
	 for(j=i+1; j<T; j++)
		{
		  if(vector[i]<vector[j])
          {
		  aux=vector[i];
		  vector[i]=vector[j];
		  vector[j]=aux;

          }
		}
	}


for (i=0;i<T;i++)
{
printf("%d\n", vector[i]);
}


    return 0;
}
