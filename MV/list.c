#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"

// cmpTeamName wird noch in die Datei des Aufrufers gepackt, oder durch Includewächter beim Aufrufer eingesetzt
int cmpTeamNameForwrd(sTeam *Team1, sTeam *Team2)
{
   int n = sizeof(Team1->TeamName);
   return strncmp(Team1->TeamName, Team2->TeamName, n);
}

int cmpTeamNameBackwrd(sTeam *Team1, sTeam *Team2)
{
   int n = sizeof(Team1->TeamName);
   return strncmp(Team2->TeamName, Team1->TeamName, n);
}

void insertDListElement(sTeam *NewTeam, int (*cmpfct) (sTeam *, sTeam *))
{
   sTeam *tmp = FirstTeam;

   if(NewTeam)
   {
      if(FirstTeam == NULL)                    // Fall 1: Liste ist leer
         FirstTeam = LastTeam = NewTeam;
      else if(cmpfct(FirstTeam, NewTeam) >= 0) // Fall 2: vor dem Ersten einfügen
      {
         FirstTeam->Prev = NewTeam;
         NewTeam->Next = FirstTeam;
         FirstTeam = NewTeam;
      }
      else if(cmpfct(LastTeam, NewTeam) <= 0)  // Fall 3: nach dem Letzten einfügen
      {
         NewTeam->Prev = LastTeam;
         LastTeam = LastTeam->Next = NewTeam;
      }
      else                                     // Fall 4: mittendrin einfügen
      {
         while(tmp->Next)
         {
            if(cmpfct(tmp->Next, NewTeam) > 0)
            {
               NewTeam->Prev = tmp;
               NewTeam->Next = tmp->Next;
               tmp->Next = tmp->Next->Prev = NewTeam;
               break;
            }
            tmp = tmp->Next;
         }
      }
   }
}

sTeam *removeDListElement(sTeam *Remove, int (*cmpfct) (sTeam *, sTeam *))
{
   sTeam *tmp = FirstTeam, *rmv = NULL;

   if(Remove)
   {
      if(FirstTeam == NULL)                   // Fall 1: Liste ist leer
         ;
      else if(cmpfct(FirstTeam, Remove) == 0) // Fall 2: erstes Element entfernen
      {
         rmv = FirstTeam;
         FirstTeam = FirstTeam->Next;
         if(FirstTeam == NULL)                // Fall 2: Sonderfall: einziges Element entfernen
            LastTeam = NULL;
         else
            FirstTeam->Prev = NULL;
      }
      else if(cmpfct(LastTeam, Remove) == 0)  // Fall 3: letztes Element entfernen
      {
         rmv = LastTeam;
         LastTeam = LastTeam->Prev;
         LastTeam->Next = NULL;
      }
      else                                    // Fall 4: sonstiges Element entfernen
      {
         while(tmp->Next)
         {
            if(cmpfct(tmp->Next, Remove) == 0)
            {
               rmv = tmp->Next;
               tmp->Next = rmv->Next;
               tmp->Next->Prev = tmp;
               break;
            }
            tmp = tmp->Next;
         }
      }
   }
   return rmv;                                // entferntes Datensatz/Element zurückgeben
}
