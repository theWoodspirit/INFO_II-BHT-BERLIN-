#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void sortName();
void sortAlter();
void sortTriknr();
void sortTore();
void QuickSortTricotNr(sTeam *team, int Anzahl, int (*cmpfct) (sPlayer *, sPlayer *));
void QsortTricotnr(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *));
int partitionTricotNr(sTeam *team, int ui, int oi, int (*cmpfct) (sPlayer *, sPlayer *));
void tausche(sPlayer *e1, sPlayer *e2);
int cmpTricotNr(sPlayer *player1, sPlayer *player2);

#endif // SORT_H_INCLUDED
