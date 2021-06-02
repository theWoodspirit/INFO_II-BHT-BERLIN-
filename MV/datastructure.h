#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#define MAXPLAYER 23
#define MAXTEAMS 10

typedef struct
{
	short Day;
	short Month;
	int Year;
} sDate;

typedef struct
{
   char *PlayerName;
   sDate *DateOfBirth;
   int JerseyNumber;
   short goals;
} sPlayer;

typedef struct
{
   char *TeamName;
   char *CoachName;
   int NumOfPlayers;
   sPlayer player[MAXPLAYER];
} sTeam;

extern sTeam Teams[];
extern int TeamCounter;

#endif
