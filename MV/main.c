#include "Code/Menu/menu.h"
#include "Code/team.h"



int main(){
    char * menuTitle = "Mannschaften-Verwaltung V2.0";
    char menu[8][20] = {"Mannschaft anlegen",
                        "Spieler hinzufuegen",
                        "Spieler loeschen",
                        "Mannschaft loeschen",
                        "Suchen",
                        "Sortieren",
                        "Auflisten",
                        "Programm beenden"};
    while (1){
        int answer = getMenu(menuTitle, menu);
        if (answer == 1) {
            createTeam();
        } else if (answer == 2) {
            addPlayer();
        } else if (answer == 3) {
            deletePlayer();
        } else if (answer == 4) {
            deleteTeam();
        } else if (answer == 5) {
            searchPlayer();
        } else if (answer == 6) {
            sortTeams();
        } else if (answer == 7) {
            listTeams();
        } else if (answer == 8) {
            return 0;
        }
    }
}


