#include <stdio.h>
#include <stdlib.h>
/*

 _
/ \
   \_/

*/
int main()
{
   int N;
   printf("Inserisci il numero di onde: ");
   scanf("%d", &N);
   for (int i = 0; i < N; i++)
      printf(" _    ");
   printf("\n");
   for (int i = 0; i < N; i++)
      printf("/ \\   ");
   printf("\n");
   for (int i = 0; i < N; i++)
      printf("   \\_/");
   return 0;
}
