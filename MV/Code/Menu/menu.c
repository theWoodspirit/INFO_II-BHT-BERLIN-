#include <stdio.h>
#include "menu.h"
#include "../team.h"
#include "../../Factory/Tools/tools.h"

void getMenu(char * menutitle, char menu[][20]){
	int i;
	do
	{
	    clearScreen();
		printf("%s\n", menutitle);
		printLine('=', 50);

		for(i=0; i < 8; i++){
			printf("%d. ",i+1);
			puts(menu[i]);
		}

		printf("\n");
	} while (getMenuPoint());
}

int getMenuPoint(){
    int answer;
	printf("Ihre Wahl: ");
	scanf("%d", &answer);
    clearBuffer();
	if(answer > 0 || answer < 9) {
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
	return 1;
}	
