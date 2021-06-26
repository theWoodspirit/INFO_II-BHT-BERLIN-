#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "datetime.h"
#include "menu.h"
#include "sort.h"
#include "list.h"

int TeamCounter = 0;
sTeam *FirstTeam = NULL;
sTeam *LastTeam = NULL;

void addPlayer(sTeam *team)
{
   if(team->NumOfPlayers < MAXPLAYER)
   {
      sPlayer *pPlayer = team->player + team->NumOfPlayers;
      getText("\nGeben Sie bitte den Namen des Spielers ein:\n-> ", 40,
              0, &pPlayer->PlayerName);

      pPlayer->DateOfBirth = getDate();

      getNumber("Geben Sie bitte die Trikotnr. des Spielers ein:\n-> ",
                &pPlayer->JerseyNumber, 0, 99);

      pPlayer->goals = 0;
      team->NumOfPlayers++;
   }
   else
      printf("\nSpielerplaetze voll!\n");
}

void createTeam()
{
   sTeam *team = malloc(sizeof(sTeam));

   if(team)
   {
      team->Prev = NULL;
      team->Next = NULL;

      clearScreen();
      printf("Erfassung einer neuen Mannschaft\n");
      printLine('=', 32);
      printf("\n\n");

      while(!getText("Geben Sie bitte den Namen der Mannschaft ein:\n-> ", 35,
                     0, &team->TeamName));

      getText("Geben Sie bitte den Namen des Trainers ein:\n-> ", 40, 1,
              &team->CoachName);

      printf("\nErfassung der Spieler\n");
      printLine('-', 22);
      team->NumOfPlayers = 0;
      do
      {
         addPlayer(team);
      } while(askYesOrNo("Moechten Sie einen weiteren Spieler eingeben (j/n) ? "));
      TeamCounter++;

      insertDListElement(team, cmpTeamNameForwrd);
   }
   waitForEnter();
}

void deleteTeam()
{
   printf("deleteTeam\n");
   waitForEnter();
}

void deletePlayer()
{
   printf("deletePlayer\n");
   waitForEnter();
}

void searchPlayer()
{
   printf("searchPlayer\n");
   waitForEnter();
}

void sortTeams()
{
   clearScreen();

   char *title = "Sortieren";
   short Wahl = 0;
   char menu[5][48] = {"Spieler nach Namen sortieren",
                      "Spieler nach Geburtsdatum (Alter) sortieren",
                      "Spieler nach Trikotnr. Sortieren",
                      "Spieler nach Anzahl geschossener Tore sortieren",
                      "Zurueck zum Hauptmenue"};

   while(Wahl != 5)
   {
      Wahl = SgetMenu(title, menu);
      switch(Wahl)
      {
         case 1: sortName();
                 break;
         case 2: sortAlter();
                 break;
         case 3: sortTriknr();
                 break;
         case 4: sortTore();
                 break;
      }
   }
}

void listOnePlayer(sPlayer player, int i)
{
   printf("   %02d. %s (%d", i + 1, player.PlayerName, player.JerseyNumber);
   if(player.DateOfBirth)
   {
      printf("; * ");
      printDate(player.DateOfBirth);
   }
   if(player.goals == 1)
      printf("; 1 Tor)\n");
   else
      printf("; %d Tore)\n", player.goals);
}

void listOneTeam(sTeam *team)
{
   printf("\nName           : %s\n", team->TeamName);
   if(team->CoachName)
      printf("Trainer        : %s\n", team->CoachName);

   printf("Anzahl Spieler : %d\n", team->NumOfPlayers);
   printf("Spieler:\n");
   for(int i = 0; i < team->NumOfPlayers; i++)
      listOnePlayer(team->player[i], i);
}

void listTeams()
{
   short ChosenMenu;
   sTeam *team = NULL, *tmp = FirstTeam;

   // Abfrage des Menüpunktes der Ausgabe
   ChosenMenu = ListTeamMenu();

   if(ChosenMenu == 3)
   {
      waitForEnter();
      return;
   }

   else if(ChosenMenu == 1)
   {
      while(tmp)
      {//printf("moin\n"); tmp Zeiger zeigt nie auf null Zeiger :( -> Endlosschleife
         insertDListElement(tmp, cmpTeamNameForwrd);
         tmp = tmp->Next;
      }
   }

   else if(ChosenMenu == 2)
   {
      while(tmp)
      {
         insertDListElement(tmp, cmpTeamNameBackwrd);
         tmp = tmp->Next;
      }
   }

   clearScreen();
   printf("Liste der Mannschaften\n");
   printLine('=', 23);
   printf("\n");
   team = FirstTeam;

   while(team)
   {
      listOneTeam(team);
      team = team->Next;
   }
   waitForEnter();
}

void freeMem(char **pPtr)
{
   if(pPtr)
   {
      free(*pPtr);
      *pPtr = NULL;
   }
}

void freeMemOfOnePlayer(sPlayer player)
{
   freeMem(&player.PlayerName);
   free(player.DateOfBirth);
   player.DateOfBirth = NULL;
}

void freeMemOfOneTeam(sTeam *team)
{
   int i;

   freeMem(&team->TeamName);
   freeMem(&team->CoachName);

   for(i = 0; i < team->NumOfPlayers; i++)
      freeMemOfOnePlayer(team->player[i]);
}

void freeMemOfAllTeams()
{
   sTeam *team = FirstTeam;

   while(team)
   {
      freeMemOfOneTeam(team);
      team = team->Next;
   }
}
