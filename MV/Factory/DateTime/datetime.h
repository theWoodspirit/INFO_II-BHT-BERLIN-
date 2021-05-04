#ifndef DATETIME_H_
#define DATETIME_H_

int isLeapYear(int y);
int isDateValid(int d, int m, int y);
int getDateFromString(char * input,sDate *date);

sDate * getDate();
void printDate(sDate * date);

#endif
