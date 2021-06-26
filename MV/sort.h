#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void sortName();
void sortAlter();
void sortTriknr();
void sortTore();
void QuickSort(sTeam *team, int Anzahl, int (*cmpfct) (sPlayer *, sPlayer *));
void Qsort(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *));
int partition(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *));
void tausche(sPlayer *e1, sPlayer *e2);
int cmpTricotNr(sPlayer *player1, sPlayer *player2);
int cmpDate(sPlayer *player1, sPlayer *player2);
int cmpPlayerName(sPlayer *player1, sPlayer *player2);
int cmpGoals(sPlayer *player1, sPlayer *player2);

#endif // SORT_H_INCLUDED
