#ifndef TEAM_H_
#define TEAM_H_

#include "datastructure.h"
extern int TeamCounter;
extern sTeam Teams[];

void createTeam();
void deleteTeam();
void addPlayer();
void deletePlayer();
void searchPlayer();
void sortTeams();
void listTeams();

#endif
