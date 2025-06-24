#include "general.h"
#include <stdio.h>
#include <string.h>
#include "../gamevars/vars.h"
#include "../interaction/messages.h"

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
    printNewScreen();
    if (strcmp(handle, "normal\n") == 0 || strcmp(handle, "extended\n") == 0) handleValid = 1;
  } handleValid = 0;

  // sets result
  if (strcmp(handle, "normal\n") == 0) currentGame.extended = 0;
  else currentGame.extended = 1;

  printGamemodes();
  while (handleValid != 1) {
    fgets(handle, 45, stdin);
    printNewScreen();
    if (strcmp(handle, "normal\n") == 0 || strcmp(handle, "extended\n") == 0) handleValid = 1;
  }
}
