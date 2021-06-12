#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

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
int partition(int *Array, int ui, int oi)
{
   int *comp = Array + ui;           /* Zeiger auf Grenzwert */
   int i = ui + 1, j = oi;           /* Laufindizes */

   while (i <= j)
   {
      // nächstes Element > *comp von links suchen (im linken Teil)
      while (i <= j && (*(Array + i) <= *comp))
         i++;
      // nächstes Element < *comp von rechts suchen (im rechten Teil)
      while (j >= i && (*(Array + j) >= *comp))
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
void qsort(int *Array, int ui, int oi)
{
   int idx;      /* Grenzwert einer Zerlegung */

   if (ui >= oi) /* Abbruchbedingung der Rekursion */
      return;
   else
   {
      idx = partition(Array, ui, oi);
      qsort(Array, ui, idx – 1); /* linken Teil rekursiv sortieren */
      qsort(Array, idx + 1, oi); /* rechten Teil rekursiv sortieren */
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
void QuickSort(int *Array, int Anzahl)
{
   qsort(Array, 0, Anzahl – 1);
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
   clearScreen();
   printf("Spieler nach Anzahl geschossener Tore sortieren ... ");
   // sortieren
   printf("ok\n");
   waitForEnter();
}
