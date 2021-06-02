#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

int isLeapYear(int y);
int isDateValid(int d, int m, int y);
int getDateFromString(char *input, sDate *date);
sDate *getDate();
void printDate(sDate *date);

#endif // DATETIME_H_INCLUDED
