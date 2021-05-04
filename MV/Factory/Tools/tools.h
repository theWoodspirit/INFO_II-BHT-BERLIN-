#ifndef TOOLS_H_
#define TOOLS_H_

void clearBuffer();
void clearScreen();
void waitForEnter();
int askYesOrNo(char *Question);
void printLine(char x, int length);

int getText(char * question, int length, int empty, char ** pointer);
int getNumber(char * question, int * pointer, int lowerBound, int upperBound);

#endif
