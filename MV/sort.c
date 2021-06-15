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

int cmpPlayerName(sPlayer *player1, sPlayer *player2)
{
   /* Wenn strncmp > 0, dann ist Name von player1 weiter hinten alphabetisch,
   als von player2 -> Spieler tauschen */
   return (strncmp(player1->PlayerName, player2->PlayerName, sizeof(player1->PlayerName)));
}

int cmpGoals(sPlayer *player1, sPlayer *player2)
{
   int dif = player1->goals - player2->goals;

   if(!dif)
   {
      return (cmpPlayerName(player1, player2));
   }
   else
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
   //printf("\n%d\n", cmpfct(&team->player[0], &team->player[1]));
   Qsort(team, 0, Anzahl - 1, cmpfct);
}

void sortName()
{
   int i;
   clearScreen();
   printf("Spieler nach Namen sortieren ... ");

   // sortieren
   for(i = 0; i < TeamCounter; i++)
      QuickSort(&Teams[i], Teams[i].NumOfPlayers, cmpPlayerName);

   printf("ok\n");
   waitForEnter();
}

void sortAlter()
{
   clearScreen();
   printf("Spieler nach Geburtsdatum (Alter) sortieren ... ");
   // Sortieren
   printf("ok\n");
   waitForEnter();
}

void sortTriknr()
{
   int i;
   clearScreen();
   printf("Spieler nach Trikotnr. sortieren ... ");

   // sortieren
   for(i = 0; i < TeamCounter; i++)
      QuickSort(&Teams[i], Teams[i].NumOfPlayers, cmpTricotNr);

   printf("ok\n");
   waitForEnter();
}

void sortTore()
{
   int i;
   clearScreen();
   printf("Spieler nach Anzahl geschossener Tore sortieren ... ");

   // sortieren
   for(i = 0; i < TeamCounter; i++)
      QuickSort(&Teams[i], Teams[i].NumOfPlayers, cmpGoals);

   printf("ok\n");
   waitForEnter();
}
