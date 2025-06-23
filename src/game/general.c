#pragma once
#include <string.h>
#include "add path to messages thing"

int normalGame() {

}

int extendedGame() {

}

int initiateGame() {
  char handle[50];
  int handleValid = 0;
  printMenu();
  while (handleValid != 1) {
    fgets(handle, 45, stdin);
    if (strcmp(handle, "normal\n") == 0 || strcmp(handle, "extended\n") == 0) handleValid = 1;
  }

}
