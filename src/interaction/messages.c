#pragma once
#include "../gamevars/vars.h";
#include <string.h>
#include <stdio.h>

void fillIn (char *str, int size, char what) {
  for (int i = 0; i < size; i++) {
    str[i] = what;
  }
}

void putInsideBox (char **items, int lines) {
  int max = 80;
  for (int i = 0; i < lines; i++) {
    int len = strlen(items[i]);
    int left = (max-len)/2; int right = (max-len)/2;
    if (left + right != max-len) right++;
    char leftStr[left]; char rightStr[right];
    fillIn(leftStr, left, ' '); fillIn(rightStr, right, ' ');
    sprintf(items[i], "%s%s%s", leftStr, items[i], rightStr);
  }
}

void printMenu() {
  char string[4][30];
  for (int i = 0; i < 4; i++) memset(string[i], 0, 20);
  sprintf(string[0], "buckshot roulette C");
  sprintf(string[1], "choose your game settings");
  sprintf(string[2], "normal");
  sprintf(string[3], "extended");
}

void printGamemodes() {
  char string[4][20];
  for (int i = 0; i < 4; i++) memset(string[i], 0, 15);
  sprintf(string[0], "pick a gamemode");
  sprintf(string[1], "shotgun");
  sprintf(string[2], "revolver");
  sprintf(string[3], "rifle");
}

}

void printStats() {
  char string[6][60];
  for (int i = 0; i < 6; i++) memset(string[i], 0, 60);
  //memcpy(string[0], "-----------Player HP: %d-----------", , playerhp);
  sprintf(string[0], "-----------Player HP: %d-----------", player.hp);
  sprintf(string[1], "-%s--%s------%s--%s-", playerInv[0], playerInv[1], playerInv[4], playerInv[5]);
  sprintf(string[2], "-%s--%s------%s--%s-", playerInv[2], playerInv[3], playerInv[6], playerInv[7]);
  sprintf(string[3], "-----------Dealer HP: %d-----------", dealer.hp);
  sprintf(string[4], "-%s--%s------%s--%s-", dealerInv[0], dealerInv[1], dealerInv[4], dealerInv[5]);
  sprintf(string[5], "-%s--%s------%s--%s-", dealerInv[2], dealerInv[3], dealerInv[6], dealerInv[7]);
  
}

void printCareful() {
  printf("Careful, now...");
}


