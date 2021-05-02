#ifndef DATASTRUCTURE_H_
#define DATASTRUCTURE_H_

#define MAXPLAYER 23
#define MAXTEAMS 10

typedef struct sDate{
	int Day;
	int Month;
	int Year;
}sDate;

typedef struct sPlayer{
	char * name;
	sDate * birthday;
	int playerNumber;
	int goalsMade;
}sPlayer;

typedef struct sTeam{
	char * name;
	char * trainer;
	int playerCnt;
	sPlayer team[MAXPLAYER];
}sTeam;

#endif
