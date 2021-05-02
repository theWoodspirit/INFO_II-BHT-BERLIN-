#include <unistd.h>
#include <stdio.h>
#include "tools.h"


void clearBuffer(){
	fflush(stdin);
	fflush(stdout);
}

void clearScreen(){
	system("cls");
    system("clear");
}

void waitForEnter(){
	printf("\nBitte Eingabetaste druecken ...\n");
	//getchar();
	clearBuffer();
}

int askYesOrNo(char *Question){
	printf("%s", Question);
	char answer;
	scanf("%c", &answer);
	fflush(stdin);	
	if(answer == 'j' || answer == 'J'){
        printf("YES!");
		return 1;
	}
	return 0;
}

void printLine(char x, int length){
	
	int i;
	for(i = 0; i < length ; i++){
		printf("%c", x);
	}
	printf("\n");
}
