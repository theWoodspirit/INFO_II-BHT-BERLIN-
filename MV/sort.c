#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "teams.h"
#include "datastructure.h"

void tausche(int *e1, int *e2)
{
   int temp;

   temp = *e1;
   *e1 = *e2;
   *e2 = temp;
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
int partition(int *Array, int ui, int oi, int (*cmpfct) (int *, int *))
{
   int *comp = Array + ui;           /* Zeiger auf Grenzwert */
   int i = ui + 1, j = oi;           /* Laufindizes */

   while (i <= j)
   {
      // nächstes Element > *comp von links suchen (im linken Teil)
      while (i <= j && (cmpfct(Array + i, comp) <= 0))
         i++;
      // nächstes Element < *comp von rechts suchen (im rechten Teil)
      while (j >= i && (cmpfct(Array + j, comp) >= 0))
         j--;

      if (i < j)
      {
         tausche(Array + i, Array + j);
         i++;
         j--;
      }
   }
   i--;
   /* setze Grenzwert zwischen beide Teile */
   tausche(comp, Array + i);

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
void Qsort(int *Array, int ui, int oi, int (*cmpfct) (int *, int *))
{
   int idx;      /* Grenzwert einer Zerlegung */

   if (ui >= oi) /* Abbruchbedingung der Rekursion */
      return;
   else
   {
      idx = partition(Array, ui, oi, cmpfct);
      Qsort(Array, ui, idx – 1, cmpfct); /* linken Teil rekursiv sortieren */
      Qsort(Array, idx + 1, oi, cmpfct); /* rechten Teil rekursiv sortieren */
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
void QuickSort(int *Array, int Anzahl, int (*cmpfct) (int *, int *))
{
   Qsort(Array, 0, Anzahl – 1, cmpfct);
}

void sortName()
{
   clearScreen();
   printf("Spieler nach Namen sortieren ... ");
   // sortieren
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
   clearScreen();
   printf("Spieler nach Trikotnr. sortieren ... ");
   // sortieren
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
   {
      QuickSort(Teams[i].player, Teams[i].NumOfPlayers, );
   }
   printf("ok\n");
   waitForEnter();
}
