#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "teams.h"
#include "datetime.h"

void savePlayer(sPlayer Player, FILE *datei)
{
   fprintf(datei, "\t\t<Player>\n");
   fprintf(datei, "\t\t\t<Name>%s</Name>\n", Player.PlayerName);
   if(Player.DateOfBirth)
   {
      sDate *date = Player.DateOfBirth;
      fprintf(datei, "\t\t\t<Birthday>%02d.%02d.%04d</Birthday>\n",
              date->Day, date->Month, date->Year);
   }
   fprintf(datei, "\t\t\t<TricotNr>%d</TricotNr>\n", Player.JerseyNumber);
   fprintf(datei, "\t\t\t<Goals>%d</Goals>\n", Player.goals);
   fprintf(datei, "\t\t</Player>\n");
}

void saveTeam(sTeam team, FILE *datei)
{
   int i;

   fprintf(datei, "\t<Team>\n");
   fprintf(datei, "\t\t<Name>%s</Name>\n", team.TeamName);
   if(team.CoachName)
      fprintf(datei, "\t\t<Trainer>%s</Trainer>\n", team.CoachName);

   for(i = 0; i < team.NumOfPlayers; i++)
      savePlayer(team.player[i], datei);

   fprintf(datei, "\t</Team>\n");
}

void save()
{
   FILE *datei = fopen("teams.xml", "w");

   if(!datei)
   {
      printf("\nDatei zum Speichern konnte nicht geoeffnet werden!\n");
      return;
   }
   fprintf(datei, "<Daten>\n");

   int i;
   for(i = 0; i < TeamCounter; i++)
      saveTeam(Teams[i], datei);

   fprintf(datei, "</Daten>");
   fclose(datei);
}

void loadPlayer(FILE *datei, sPlayer *Player)
{
   char Zeile[101];
   char Buffer, *Zeilenanfang;
   size_t len;
   char *InputDate;

   Player->DateOfBirth = NULL;
   Player->goals = 0;
   Player->JerseyNumber = 0;
   Player->PlayerName = NULL;

   do
   {
      fscanf(datei, "%100[^\n]%c", Zeile, &Buffer);

      Zeilenanfang = Zeile;
      while((*Zeilenanfang == ' ') || (*Zeilenanfang == 9))
         Zeilenanfang++;

      if(strncmp(Zeilenanfang, "<Name>", 6) == 0)
      {
         // Bei mehrfacher vorhanden seins des Tags
         if(Player->PlayerName)
            freeMem(&Player->PlayerName);

         len = strlen(Zeilenanfang + 6) - 7; // Abziehen des Ende-Tags

         if(strncmp(Zeilenanfang + 6 + len, "</Name>", 7) == 0)
         {
            Player->PlayerName = calloc(len + 1, sizeof(char));
            if(Player->PlayerName)
               strncpy(Player->PlayerName, Zeilenanfang + 6, len);
         }
      }
      else if(strncmp(Zeilenanfang, "<Birthday>", 10) == 0)
      {
         if(Player->DateOfBirth)
         {
            free(Player->DateOfBirth);
            Player->DateOfBirth = NULL;
            freeMem(&InputDate);
         }
         len = strlen(Zeilenanfang + 10) - 11;

         if(strncmp(Zeilenanfang + 10 + len, "</Birthday>", 11) == 0)
         {
            sDate *date = malloc(sizeof(sDate));
            InputDate = calloc(11, sizeof(char));
            strncpy(InputDate, Zeilenanfang + 10, 10);
            // Textendezeichen hinzufügen, wegen Abfrage in getDateFromString
            *(InputDate + 11) = '\0';
            getDateFromString(InputDate, date);

            Player->DateOfBirth = date;
         }
      }
      else if(strncmp(Zeilenanfang, "<Goals>", 7) == 0)
      {
         len = strlen(Zeilenanfang + 7) - 8;

         if(strncmp(Zeilenanfang + 7 + len, "</Goals>", 8) == 0)
             Player->goals = atoi(Zeilenanfang + 7);
      }
      else if(strncmp(Zeilenanfang, "<TricotNr>", 10) == 0)
      {
         len = strlen(Zeilenanfang + 10) - 11;

         if(strncmp(Zeilenanfang + 10 + len, "</TricotNr>", 11) == 0)
            Player->JerseyNumber = atoi(Zeilenanfang + 10);
      }
      else if(feof(datei))
            break;
   } while(strncmp(Zeilenanfang, "</Player>", 9) != 0);
}

void loadTeam(FILE *datei, sTeam *team)
{
   char Zeile[101];
   char Buffer, *Zeilenanfang;
   size_t len;

   team->NumOfPlayers = 0;
   team->CoachName = NULL;
   team->TeamName = NULL;

   do
   {
      fscanf(datei, "%100[^\n]%c", Zeile, &Buffer);

      Zeilenanfang = Zeile;
      while((*Zeilenanfang == ' ') || (*Zeilenanfang == 9))
         Zeilenanfang++;

      if(strncmp(Zeilenanfang, "<Name>", 6) == 0)
      {
         if(team->TeamName)
            freeMem(&team->TeamName);

         len = strlen(Zeilenanfang + 6) - 7; // Abziehen des Ende-Tags

         if(strncmp(Zeilenanfang + 6 + len, "</Name>", 7) == 0)
         {
            team->TeamName = calloc(len + 1, sizeof(char));
            if(team->TeamName)
               strncpy(team->TeamName, Zeilenanfang + 6, len);
         }
      }
      else if(strncmp(Zeilenanfang, "<Trainer>", 9) == 0)
      {
         if(team->CoachName)
            freeMem(&team->CoachName);

         len = strlen(Zeilenanfang + 9) - 10;

         if(strncmp(Zeilenanfang + 9 + len, "</Trainer>", 10) == 0)
         {
            team->CoachName = calloc(len + 1, sizeof(char));
            if(team->CoachName)
               strncpy(team->CoachName, Zeilenanfang + 9, len);
         }
      }
      else if(strncmp(Zeilenanfang, "<Player>", 8) == 0)
      {
         loadPlayer(datei, team->player + team->NumOfPlayers);
         team->NumOfPlayers++;
      }
      else if(feof(datei))
            break;
   } while(strncmp(Zeilenanfang, "</Team>", 7) != 0);
}

void load()
{
   char Zeile[101];
   char Buffer, *Zeilenanfang;
   FILE *datei = fopen("teams.xml", "rt");

   if(datei)
   {
      do
      {
         // %c -> \n für den Zeilenumbruch einscannen
         fscanf(datei, "%100[^\n]%c", Zeile, &Buffer);
         // Leerzeichen / Tabulatoren entfernen
         Zeilenanfang = Zeile;
         while((*Zeilenanfang == ' ') || (*Zeilenanfang == 9))
            Zeilenanfang++;

         if(strncmp(Zeilenanfang, "<Team>", 6) == 0)
         {
            loadTeam(datei, &Teams[TeamCounter]);
            TeamCounter++;
         }

         if(feof(datei))
            break;
      } while(strncmp(Zeilenanfang, "</Daten>", 8) != 0);
   }
   fclose(datei);
}
