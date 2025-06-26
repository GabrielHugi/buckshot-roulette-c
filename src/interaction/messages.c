#include "messages.h"
#include "../gamevars/vars.h"
#include <string.h>
#include <stdio.h>

void fillIn (char *str, int size, char what) {
  for (int i = 0; i < size-1; i++) {
    str[i] = what;
  }
  str[size-1] = '\0';
}

void putInsideBox (char items[][80], int lines, int leftBorder, int rightBorder) {
  int max = 80;
  for (int i = 0; i < lines; i++) {
    int len = strlen(items[i]);
    int left = (max-len)/2; int right = (max-len)/2;
    if (left + right != max-len) right++;
    char leftStr[left+1]; char rightStr[right+1];
    char fillLeft = '\0'; char fillRight = '\0';
    if (leftBorder == 1) fillLeft = ' '; if (rightBorder == 1) fillRight = ' ';
    fillIn(leftStr, left, fillLeft); fillIn(rightStr, right, fillRight);
    char temp[80]; strcpy(temp, items[i]);
    sprintf(items[i], "%s%s%s", leftStr, temp, rightStr);
  }
}

/*
MENUS
*/

void printMenu() {
  char string[4][80];
  for (int i = 0; i < 4; i++) memset(string[i], 0, 80);
  sprintf(string[0], "buckshot roulette C");
  sprintf(string[1], "choose your game settings");
  sprintf(string[2], "normal");
  sprintf(string[3], "extended");
  putInsideBox(string, 4, 1, 1);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", string[i]);
  }
}

void printCustom(char string[80], int isInput) {
  char temp[1][80];
  strcpy (temp[0], string);
  putInsideBox(temp, 1, 1, -(isInput-1));
  printf(temp[0]);
}

void printGamemodes() {
  char string[4][80];
  for (int i = 0; i < 4; i++) memset(string[i], 0, 80);
  sprintf(string[0], "pick a gamemode");
  sprintf(string[1], "shotgun");
  sprintf(string[2], "revolver");
  sprintf(string[3], "rifle");
  putInsideBox(string, 4, 1, 1);
  for (int i = 0; i < 4; i++) {
    printf("%s\n", string[i]);
  }
}


/*
GAME SCREENS
*/
void printStats() {
  char string[6][60];
  for (int i = 0; i < 6; i++) memset(string[i], 0, 60);
  //memcpy(string[0], "-----------Player HP: %d-----------", , playerhp);
  sprintf(string[0], "-----------Player HP: %d-----------", player.hp);
  sprintf(string[1], "-%s--%s------%s--%s-", player.inv[0], player.inv[1], player.inv[4], player.inv[5]);
  sprintf(string[2], "-%s--%s------%s--%s-", player.inv[2], player.inv[3], player.inv[6], player.inv[7]);
  sprintf(string[3], "-----------Dealer HP: %d-----------", dealer.hp);
  sprintf(string[4], "-%s--%s------%s--%s-", dealer.inv[0], dealer.inv[1], dealer.inv[4], dealer.inv[5]);
  sprintf(string[5], "-%s--%s------%s--%s-", dealer.inv[2], dealer.inv[3], dealer.inv[6], dealer.inv[7]);
  
}

void printStartingLocation() {
  if (currentGame.gun == 0) {
    char string[9][80];
    for (int i = 0; i < 9; i++) memset(string[i], 0, 60);
    sprintf(string[0], "######################################################################");
    sprintf(string[1], "#############################|----------|#############################");
    sprintf(string[2], "#############################|----------|#############################");
    sprintf(string[3], "#############################|----------|#############################");
    sprintf(string[4], "#############################|----------|#############################");
    sprintf(string[5], "#############################|--------O-|#############################");
    sprintf(string[6], "#############################|----------|#############################");
    sprintf(string[7], "#############################|----------|#############################");
    sprintf(string[8], "#############################|----------|#############################");
    putInsideBox(string, 9, 1, 1);
    for (int i = 0; i < 9; i++) {
    printf("%s\n", string[i]);
  }
  }
}

/*
MISC
*/
void printCareful() {
  printf("Careful, now...");
}

void printNewScreen() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

