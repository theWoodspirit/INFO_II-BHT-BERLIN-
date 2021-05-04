#include "../Factory/Tools/tools.h"
#include "datastructure.h"
#include "team.h"
#include <stdio.h>
#include "../Factory/DateTime/datetime.h"


sTeam Teams[MAXTEAMS];
int TeamCounter = 0;

void createTeam(){
    if(TeamCounter >= MAXTEAMS){
        printf("Es koennen keine weiteren Teams erstellt werden.");
    }
    else{
        getText("Bitte Team-Name eingeben: ",
                20,0 , &Teams[TeamCounter].name);

        getText("Bitte Name fuer Trainer eingeben: ",
                20,1,  &Teams[TeamCounter].trainer);

        Teams[TeamCounter].playerCnt = 0;

        // spieler adden
        do
        {
            addPlayer();
        } while (askYesOrNo("Noch ein Spieler hinzuefugen (j/n) ?")
                  && Teams[TeamCounter].playerCnt <=  23);

        TeamCounter++;
    }
    printf("%d", TeamCounter);
	//waitForEnter();
}

void deleteTeam(){
	printf("deleteTeam\n");
	waitForEnter();
}

void addPlayer(){
    // name
    getText("Bitte Name des Spielers eingeben: ", 30, 0,
            &Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].name);

    // bday
    Teams[TeamCounter].team[ Teams[TeamCounter ].playerCnt].birthday = getDate();

    //trikot nr.
    getNumber("Bitte Trikot-Nr. eingeben: ",
              &Teams[TeamCounter].team[ Teams[TeamCounter].playerCnt].playerNumber,
              1,100);

    Teams[TeamCounter].team[Teams[TeamCounter].playerCnt].goalsMade = 0;
    Teams[TeamCounter].playerCnt++;
	//waitForEnter();
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
    printf("Liste der Mannschaften \n");
    printLine('_',50);
    for(int i = 0; i < TeamCounter; i++){
        listOneTeam(Teams[i]);
        printf("\n");
    }


    waitForEnter();
}

void listOneTeam(sTeam team){
    char c = ' ';
    printf("Name %*c: %s \n",20,c,team.name);
    printf("Trainer %*c: %s \n",17,c,team.trainer);
    printf("Anzahl Spieler %*c: %d \n", 10,c,team.playerCnt);
    printf("Spieler:\n" );
    for(int i = 0; i < team.playerCnt; i++){
        printf("%*c %2d. ",4,c,i+1);
        listOnePlayer(team.team[i]);
    }
}

void listOnePlayer(sPlayer player){
    printf( "%s (%d;  *",player.name, player.playerNumber);
    printDate(player.birthday);
    printf(")\n");
}