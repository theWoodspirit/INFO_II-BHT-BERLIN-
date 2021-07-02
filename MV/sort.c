#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "teams.h"
#include "datastructure.h"

void tausche(sPlayer *e1, sPlayer *e2)
{
   sPlayer *temp = malloc(sizeof(sPlayer));

   if(temp)
   {
      *temp = *e1;
      *e1 = *e2;
      *e2 = *temp;
      free(temp);
   }
   else
      printf("\nKonnte kein Speicher fuer tausche-fkt reservieren.\n");
}

int cmpDate(sPlayer *player1, sPlayer *player2)
{
   if(!player1->DateOfBirth)
      return 1;
   if(!player2->DateOfBirth)
      return -1;

   if(player1->DateOfBirth->Year - player2->DateOfBirth->Year)
      return player1->DateOfBirth->Year - player2->DateOfBirth->Year;

   if(player1->DateOfBirth->Month - player2->DateOfBirth->Month)
      return player1->DateOfBirth->Month - player2->DateOfBirth->Month;

   return player1->DateOfBirth->Day - player2->DateOfBirth->Day;
}

int cmpPlayerName(sPlayer *player1, sPlayer *player2)
{
   int n = sizeof(player1->PlayerName);
   /* Wenn strncmp > 0, dann ist Name von player1 weiter hinten alphabetisch,
   als von player2 -> Spieler tauschen */
   return strncmp(player1->PlayerName, player2->PlayerName, n);
}

int cmpGoals(sPlayer *player1, sPlayer *player2)
{
   int dif = player1->goals - player2->goals;

   if(!dif)
   {
      return cmpPlayerName(player1, player2);
   }
   return dif;
}

int cmpTricotNr(sPlayer *player1, sPlayer *player2)
{
   return player1->JerseyNumber - player2->JerseyNumber;
}

/**********************************************************
 * int partition(int *Array, int ui, int oi)              *
 * Unterteilt das angegebene Array in zwei Teile, wobei   *
 * im linken Teil alle Werte kleiner und im rechten Teil  *
 * alle Werte größer als die mittlere Schranke sind. Der  *
 * Index der Schranke wird zurückgegeben.                 *
 * Parameter: Array – das zu sortierende Array            *
 *            ui - der untere Index des Teils des         *
 *            Arrays, der sortiert werden soll            *
 *            oi - der obere Index (entsprechend ui)      *
 * Rückgabe:  int - Index der Schranke                    *
 **********************************************************/
int partition(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *))
{
   int i = ui + 1, j = oi;                            /* Laufindizes */

   while(i <= j)
   {
      // nächstes Element > *comp von links suchen (im linken Teil)
      while (i <= j && (cmpfct(&team->player[i], &team->player[ui]) <= 0))
         i++;
      // nächstes Element < *comp von rechts suchen (im rechten Teil)
      while (j >= i && (cmpfct(&team->player[j], &team->player[ui]) >= 0))
         j--;

      if(i < j)
      {
         tausche(&team->player[i], &team->player[j]);
         i++;
         j--;
      }
   }
   i--;
   /* setze Grenzwert zwischen beide Teile */
   tausche(&team->player[ui], &team->player[i]);

   return i; // Position des Grenzwertes zurückgeben
}

/**********************************************************
 * void qsort(int *Array, int ui, int oi)                 *
 * Unterteilt das Array in zwei Teile (Funktion           *
 * partition) und ruft sich selber für beide Teile        *
 * erneut auf.                                            *
 * Parameter: Array – das zu sortierende Array            *
 *            ui - der untere Index des Teils des         *
 *            Arrays, der sortiert werden soll            *
 *            oi - der obere Index (entsprechend ui)      *
 * Rückgabe:  keine                                       *
 **********************************************************/
void Qsort(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *))
{
   int idx;      /* Grenzwert einer Zerlegung */

   if (ui >= oi) /* Abbruchbedingung der Rekursion */
      return;
   else
   {
      idx = partition(team, ui, oi, cmpfct);
      Qsort(team, ui, idx - 1, cmpfct); /* linken Teil rekursiv sortieren */
      Qsort(team, idx + 1, oi, cmpfct); /* rechten Teil rekursiv sortieren */
   }
}

/***********************************************************
* Quick-Sort                                               *
* Sortiert das angegebene Zahlen-Array in aufsteigender    *
* Reihenfolge.                                             *
* Parameter: Array – Zeiger auf das zu sortierende Array   *
*            Anzahl – Anzahl der Elemente im Array         *
* Rückgabe:  keine                                         *
***********************************************************/
void QuickSort(sTeam *team, int Anzahl, int (*cmpfct) (sPlayer *, sPlayer *))
{
   Qsort(team, 0, Anzahl - 1, cmpfct);
}

void sortName()
{
   sTeam *team = FirstTeam;

   clearScreen();
   printf("Spieler nach Namen sortieren ... \n\n");

   // sortieren
   while(team)
   {
      printf("Spieler der Mannschaft %s sortieren ... ", team->TeamName);
      QuickSort(team, team->NumOfPlayers, cmpPlayerName);
      printf("ok\n");
      team = team->Next;
   }

   waitForEnter();
}

void sortAlter()
{
   sTeam *team = FirstTeam;

   clearScreen();
   printf("Spieler nach Geburtsdatum (Alter) sortieren ... \n\n");

   // Sortieren
   while(team)
   {
      printf("Spieler der Mannschaft %s sortieren ... ", team->TeamName);
      QuickSort(team, team->NumOfPlayers, cmpDate);
      printf("ok\n");
      team = team->Next;
   }

   waitForEnter();
}

void sortTriknr()
{
   sTeam *team = FirstTeam;

   clearScreen();
   printf("Spieler nach Trikotnr. sortieren ... \n\n");

   // sortieren
   while(team)
   {
      printf("Spieler der Mannschaft %s sortieren ... ", team->TeamName);
      QuickSort(team, team->NumOfPlayers, cmpTricotNr);
      printf("ok\n");
      team = team->Next;
   }

   waitForEnter();
}

void sortTore()
{
   sTeam *team = FirstTeam;

   clearScreen();
   printf("Spieler nach Anzahl geschossener Tore sortieren ... \n\n");

   // sortieren
   while(team)
   {
      printf("Spieler der Mannschaft %s sortieren ... ", team->TeamName);
      QuickSort(team, team->NumOfPlayers, cmpGoals);
      printf("ok\n");
      team = team->Next;
   }

   waitForEnter();
}
