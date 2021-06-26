#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_
#define MAXPLAYER 23

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

typedef struct sTm
{
   char *TeamName;
   char *CoachName;
   int NumOfPlayers;
   sPlayer player[MAXPLAYER];
   struct sTm *Next;
   struct sTm *Prev;
} sTeam;

extern sTeam *FirstTeam;
extern sTeam *LastTeam;
extern int TeamCounter;

#endif
