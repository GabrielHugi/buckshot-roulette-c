#pragma once;
#include "../gamevars/vars.h";
#include <string.h>

void fillIn (char *str, int size, char what) {
  for (int i = 0; i < size; i++) {
    str[i] = what;
  }
}

void putInsideBox (char **items, int lines) {
  int max = 80;
  for (int i = 0; i < items; i++) {
    int len = strlen(items);
    int left = (max-len)/2; int right = (max-len)/2;
    if (left + right != max-len) right++;
    char leftStr[left]; char rightStr[right];
    fillIn(leftStr, left, ' '); fillIn(rightStr, right, ' ');
    sprintf(items[i], "%s%s%s", leftStr, items[i], rightStr);
  }
}
void printStats() {
  char string[6][60];
  for (int i = 0; i < 6; i++) memset(string[i], 0, 60);
  //memcpy(string[0], "-----------Player HP: %d-----------", , playerhp);
  sprintf(string[0], "-----------Player HP: %d-----------", playerhp);
  sprintf(string[1], "-%s--%s------%s--%s-", playerInv[0], playerInv[1], playerInv[4], playerInv[5]);
  sprintf(string[2], "-%s--%s------%s--%s-", playerInv[2], playerInv[3], playerInv[6], playerInv[7]);
  sprintf(string[3], "-----------Dealer HP: %d-----------", dealerhp);
  sprintf(string[4], "-%s--%s------%s--%s-", dealerInv[0], dealerInv[1], dealerInv[4], dealerInv[5]);
  sprintf(string[5], "-%s--%s------%s--%s-", dealerInv[2], dealerInv[3], dealerInv[6], dealerInv[7]);
  
}

void printCareful() {
  printf("Careful, now...");
}

