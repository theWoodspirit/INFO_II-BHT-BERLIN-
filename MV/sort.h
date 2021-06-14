#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

void sortName();
void sortAlter();
void sortTriknr();
void sortTore();
void QuickSortTricotNr(sTeam *team, int Anzahl);
void QsortTricotnr(sTeam *team, int ui, int oi);
int partitionTricotNr(sTeam *team, int ui, int oi);
void tausche(int *e1, int *e2);

#endif // SORT_H_INCLUDED
