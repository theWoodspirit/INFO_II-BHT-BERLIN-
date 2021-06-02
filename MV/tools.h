#ifndef TOOLS_H_
#define TOOLS_H_

void clearBuffer();
void clearScreen();
void waitForEnter();
int askYesOrNo(char *Question);
void printLine(char c, int i);

int getText(char *Prompt, int MaxLen, int AllowEmpty, char **pPointer);
void getNumber(char *Prompt, int *Pointer, int Von, int Bis);

#endif
