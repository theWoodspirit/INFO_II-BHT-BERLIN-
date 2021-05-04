#include "Code/Menu/menu.h"

#include <stdio.h>
#include <malloc.h>
#include "Factory/Tools/tools.h"

void showMenu();


int main()
{
    showMenu();

    //char*x;
    //printf("get Text return = %d \n",getText("input:", 10, 0, &x));
    //printf("string in main: %s",x);

    //waitForEnter();

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
