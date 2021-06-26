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
/******************************************************************************/
short SgetMenu(char *title, char menu[][48])
{
   short i;
   int k;

   do
   {
      k = 0;
      clearScreen();
      printf("%s\n", title);
      printLine('=', 9);
      printf("\n\n");
      for(i = 0; i < 5; i++)
         printf("%i. %s\n", i + 1, menu[i]);
      printf("\nIhre Wahl: ");
      scanf("%d", &k);
      clearBuffer();
   } while((k > 5) || (k < 1));

   return k;
}

short ListTeamMenu()
{
   char *title = "Ausgabe";
   char menu[3][23] = {
   "Aufwaerts ausgeben",
   "Abwaerts ausgeben",
   "zurueck zum Hauptmenue"};
   short i;
   int k;

   do
   {
      k = 0;
      clearScreen();
      printf("%s\n", title);
      printLine('=', 7);
      printf("\n\n");
      for(i = 0; i < 3; i++)
         printf("%i. %s\n", i + 1, menu[i]);
      printf("\nIhre Wahl: ");
      scanf("%d", &k);
      clearBuffer();
   } while((k > 3) || (k < 1));

   return k;
}
