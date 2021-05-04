#include <unistd.h>
#include <stdio.h>
#include "tools.h"
#include <malloc.h>

void clearBuffer(){
    fflush(stdin);
    fflush(stdout);
}

void clearScreen(){
    system("cls");
}

void waitForEnter(){
    printf("\nBitte Eingabetaste druecken ...\n");
    getchar();
    clearBuffer();
}

int askYesOrNo(char *Question){
    printf("%s", Question);
    char answer;
    scanf("%c", &answer);
    fflush(stdin);
    if(answer == 'j' || answer == 'J'){
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

int getNumber(char * question, int * pointer, int lowerBound, int upperBound){
    do
    {
        printf("%s", question);
        scanf("%d", pointer);
        clearBuffer();
        if (*pointer >= lowerBound && *pointer <= upperBound)
            return 1;
        else
            printf("Ungueltige Eingabe.");
    } while (askYesOrNo("Moechten Sie noch einmal (j/n)?"));
    return 0;
}

int getText(char * question, int length, int empty, char ** pointer){

    // wrong output if strlen(input) == 1


    do
    {
        printf("%s", question);
        char * input = malloc(sizeof(char) * length);
        input[0] = '\0';

        char text[512];
        sprintf( text, "%%%d[^\n]", length);
        scanf(text, input);
        clearBuffer();


        //printf(" string before copy: %s , length: %d\n", input, strlen(input));

        *pointer = malloc(sizeof(char) * strlen(input));
        if (input[0] == '\0' && empty == 0)
            printf("Ungueltige Eingabe. ");

        else{
            strncpy(*pointer,input,strlen(input));
            //printf("string in function : %s, length: %d \n", *pointer, strlen(*pointer));
            free(input);
            return 1;
        }
    } while (askYesOrNo("Moechten Sie noch einmal (j/n)? "));
    return 0;
}
