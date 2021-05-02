#include "../../Code/datastructure.h"
#include "datetime.h"
#include <stdlib.h>

/* durch 4 teilbar und kein jahrhundert oder durch 400 teilbar */  
int isLeapYear(int y){
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

/* validiere Datum nach gregorianischen Kalender  */
int isDateValid(int d, int m, int y){
	
	if(m < 1 || m > 12 || d < 1 || d > 31){
		return 0;
	}
	if (m == 2){
		if(isLeapYear(y)){
			if( d > 29){
				return 0;
			}	
		}else if( d > 28){
			return 0;
		}	
	}
	else if((m == 4 || m == 6 || m == 9 || m == 11) && d > 30 ){	
		return 0;
	}
	return 1;
}

/* wir nutzen strtol und den pointer */
int getDateFromString(char * input,sDate *date){
	
	char * succ;
  	long int day = strtol(input, &succ, 10),
 		month = strtol(succ+1, &succ, 10),
 		year = strtol(succ+1, &succ, 10);
 	
 	if(*succ == '\0' && isDateValid(day,month,year)){
 		date->Day = day;
		date->Month = month;
		date->Year = year;
		return 1;
	
	}
	return 0;
}
