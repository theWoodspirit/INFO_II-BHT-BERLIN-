#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

void savePlayer(sPlayer Player, FILE *datei);
void saveTeam(sTeam team, FILE *datei);
void save();
void loadPlayer(FILE *datei, sPlayer *Player);
void loadTeam(FILE *datei, sTeam *team);
void load();

#endif // DATABASE_H_INCLUDED
