#ifndef TEAMS_H_INCLUDED
#define TEAMS_H_INCLUDED
#include "datastructure.h"

void createTeam();
void deleteTeam();
void addPlayer();
void deletePlayer();
void searchPlayer();
void sortTeams();
void listTeams();

void listOneTeam(sTeam team);
void listOnePlayer(sPlayer player, int i);

void freeMem(char **pPtr);
void freeMemOfOnePlayer(sPlayer player);
void freeMemOfOneTeam(sTeam team);
void freeMemOfAllTeams();
#endif // TEAMS_H_INCLUDED
