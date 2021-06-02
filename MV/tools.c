#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teams.h"

/******************************************************************************/

void clearScreen()
{
//   system("clear"); // Linux
   system("CLS");   // Windows
}

/******************************************************************************/

void clearBuffer()
{
   char Dummy;

   do
   {
      scanf("%c", &Dummy);
   } while (Dummy != '\n');
}

/******************************************************************************/

void waitForEnter()
{
   printf("\nBitte Eingabetaste druecken ... ");
   clearBuffer();
}

/******************************************************************************/

int askYesOrNo(char *Question)
{
   char Input;

   do
   {
      printf(Question); // same as printf("%s", Question);
      scanf("%c", &Input);
      if (Input != '\n')
         clearBuffer();
   } while ((Input != 'j') && (Input != 'J') && (Input != 'n') && (Input != 'N'));
   return ((Input == 'j') || (Input == 'J'));
}

/******************************************************************************/

void printLine(char c, int i)
{
   for(int k = 1; k <= i; k++)
      printf("%c", c);
}

int getText(char *Prompt, int MaxLen, int AllowEmpty, char **pPointer)
{
   char *Input = NULL;
   char Format[20];
   unsigned Len = 0;
   int ok = 0;

   if((pPointer == NULL) || (MaxLen == 0))
      return 0;

   *pPointer = NULL;

   Input = malloc(MaxLen + 1);
   if(Input)
   {
      sprintf(Format, "%%%i[^\n]", MaxLen);
      do
      {
         printf(Prompt);           // das selbe wie: printf("%s", Prompt);
         *Input = '\0';
         scanf(Format, Input);
         clearBuffer();
         Len = strlen(Input);
         if (Len > 0)
         {
            *pPointer = malloc(Len + 1);
            if (*pPointer)
            {
               strncpy(*pPointer, Input, Len + 1);
               ok = 1;
            }
         }
         else if(AllowEmpty)
            ok = 1;
      } while(ok != 1);
      free(Input);
      return 1;
   }
   else
      return 0;
}

void getNumber(char *Prompt, int *Pointer, int Von, int Bis)
{
   int IntOk = 1, AllCorrect = 1;
   do
   {
      printf(Prompt);
      IntOk = scanf("%d", Pointer);
      clearBuffer();
      if(!IntOk || (*Pointer < Von) || (*Pointer > Bis))
      {
         printf("Ungueltige Eingabe!\n");
         AllCorrect = 0;
      }
      else
         AllCorrect = 1;
   } while(!AllCorrect);
}

