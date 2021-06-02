#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

short getMenu(char *title, char menu[][24])
{
   short i;
   int k;
   do
   {
      k = 0;
      clearScreen();
      printf("%s\n", title);
      printLine('=', 28);
      printf("\n\n");
      for(i = 0; i < 8; i++)
         printf("%i. %s\n", i + 1, menu[i]);
      printf("\nIhre Wahl: ");
      scanf("%d", &k);
      clearBuffer();
   } while((k > 8) || (k < 1));

   return k;
}
