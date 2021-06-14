#include <stdio.h>
#include <stdlib.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "teams.h"
#include "menu.h"
#include "database.h"

int main()
{
   char *title = "Mannschaften-Verwaltung V5.2";
   short ChosenMenu;
   char menu[8][24] = {
   "Neue Mannschaft anlegen",
   "Spieler hinzufuegen",
   "Spieler loeschen",
   "Mannschaft loeschen",
   "Suchen",
   "Sortieren",
   "Auflisten",
   "Programm beenden"};

   load();
   do
   {
      ChosenMenu = getMenu(title, menu);
      switch(ChosenMenu)
      {
         case 1: createTeam();
                 break;
         case 2: addPlayer();
                 break;
         case 3: deletePlayer();
                 break;
         case 4: deleteTeam();
                 break;
         case 5: searchPlayer();
                 break;
         case 6: sortTeams();
                 break;
         case 7: listTeams();
                 break;
      }
   } while(ChosenMenu != 8);

   if(askYesOrNo("Speichern? (j/n) "))
      save();

   freeMemOfAllTeams();

   return 0;
}
