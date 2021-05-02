#include "../Factory/Tools/tools.h"
#include "datastructure.h"
#include "team.h"
#include <stdio.h>
#include "string.h"
#include "../Factory/DateTime/datetime.h"


sTeam Teams[MAXTEAMS];
int TeamCounter = 0;

void getString(char * str){
//das ist Neinkobs kommentar
}

void createTeam(){

    //sTeam team;
    printf("Bitte Name fuer Team eingeben: ");
    gets(Teams[TeamCounter].name);
    clearBuffer();
    printf("Bitte Name fuer Trainer eingeben: ");
    gets(Teams[TeamCounter].trainer);
    clearBuffer();
    Teams[TeamCounter].playerCnt = 0;


    do
    {
       addPlayer();
    } while (askYesOrNo("Noch ein Spieler hinzuefugen?") && Teams[TeamCounter].playerCnt <=  23);

    TeamCounter++;
    listTeams();


    //Teams[TeamCounter]=team;
    //printf("%s %10d \n",team.name, team.playerCnt);


    TeamCounter++;
	waitForEnter();
}
void deleteTeam(){
	printf("deleteTeam\n");
	waitForEnter();
}
void addPlayer(){
    printf("addPlayer \n");
    printf("Bitte Name von Spieler eingeben: ");
    gets(Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].name);
    clearBuffer();
    printf("Gerburtsdatum von Spieler eigeben: ");


    sDate Date;
    char Input[20];

    do
    {
        printf("Geben Sie bitte ein gueltiges Datum ein: ");
        *Input = '\0';
        scanf("%19[^\n]", Input);
        clearBuffer();
        if (getDateFromString(Input, &Date))
            break;
        else
            printf("Das eingegebene Datum '%s' ist ungueltig!\n", Input);
    } while (askYesOrNo("Moechten Sie noch einmal (j/n) ? "));


    Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].birthday = &Date;
    printf("Bitte geben Sie die Trikot Nr. ein: ");
    scanf("%d", Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].playerNumber);
    Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].goalsMade = 0;
    Teams[TeamCounter].playerCnt++;
	waitForEnter();
}
void deletePlayer(){
	printf("deletePlayer\n");
	waitForEnter();
}
void searchPlayer(){
	printf("searchPlayer\n");
	waitForEnter();
}
void sortTeams(){
	printf("sortTeams\n");
	waitForEnter();
}
void listTeams(){
    int i;
    printLine('_',50);
    for(i = 0; i < 10; i++){
        printf("%s %10x \n",Teams[i].name, &Teams[i].name);
        //printf("%s %10x \n ", Teams[i].team[0].name, &Teams[i].team[0]);
    }
}


