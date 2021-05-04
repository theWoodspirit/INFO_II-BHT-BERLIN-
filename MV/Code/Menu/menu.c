#include <stdio.h>
#include "menu.h"
#include "../team.h"
#include "../../Factory/Tools/tools.h"

int getMenu(char * menutitle, char menu[][20]){

    clearScreen();
    printf("%s\n", menutitle);
    printLine('=', 50);

    for(int i=0; i < 8; i++){
        printf("%d. ",i+1);
        puts(menu[i]);
    }

    int answer;
    printf("\n Ihre Wahl: ");
    scanf("%d", &answer);
    clearBuffer();

    if(answer < 0 || answer > 9) {
        printf("Ihre eingabe war falsch.\n");
        printf("Bitte versuchen Sie es nochmal.\n");

        waitForEnter();
        return getMenu(menutitle, menu);
    }

    return answer;
}


