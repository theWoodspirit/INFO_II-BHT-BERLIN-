#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "teams.h"
#include "datastructure.h"


void swap(sPlayer a, sPlayer b) {
  sPlayer player = a;
  a = b;
  b = player;
  printf("%d wird zu %d \n",a.JerseyNumber,b.JerseyNumber);
  sleep(0.5);
}


int partition(sTeam team, int low, int high) {


  int pivot = team.player[high].JerseyNumber;


  int i = (low - 1);
  int j;

  for (j = low; j < high; j++) {
    if (team.player[j].JerseyNumber <= pivot) {


      i++;


      swap(team.player[i], team.player[j]);
    }
  }


  swap(team.player[i + 1], team.player[high]);


  return (i + 1);
}

void quickSortTrikotNr(sTeam team, int low, int high) {
  if (low < high) {

    int pi = partition(team, low, high);


    quickSortTrikotNr(team, low, pi - 1);


    quickSortTrikotNr(team, pi + 1, high);
  }
}

void sortName(){
}
void sortAlter(){
}
void sortTriknr(){
    int i;
    for(i = 0; i < TeamCounter; i++){
        quickSortTrikotNr(Teams[i], 0 , Teams[i].NumOfPlayers-1);
    }
}
void sortTore(){
}
