#include "Code/Menu/menu.h"

void showMenu();

int main()
{
    showMenu();
    return 0;
}

void showMenu()
{
    char * menuTitle = "Mannschaften-Verwaltung V2.0";
    char menu[8][20] = {"Mannschaft anlegen",
                        "Spieler hinzufuegen",
                        "Spieler loeschen",
                        "Mannschaft loeschen",
                        "Suchen",
                        "Sortieren",
                        "Auflisten",
                        "Programm beenden"};

    getMenu(menuTitle, menu);
}
