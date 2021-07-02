#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

int cmpTeamName(sTeam *Team1, sTeam *Team2);
void insertDListElement(sTeam *NewTeam, int (*cmpfct) (sTeam *, sTeam *));
sTeam *removeDListElement(sTeam *Remove, int (*cmpfct) (sTeam *, sTeam *));

#endif // LIST_H_INCLUDED
