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
  printNewScreen();
  printMenu();
  while (handleValid != 1) {
    printf("\n");
    printCustom("Select option: ", 1);
    fgets(handle, 45, stdin);
    if (strcmp(handle, "normal\n") == 0 || strcmp(handle, "extended\n") == 0) handleValid = 1;
    else {
      printNewScreen();
      printMenu();
    }
  } handleValid = 0;

  // sets result
  if (strcmp(handle, "normal\n") == 0) currentGame.extended = 0;
  else currentGame.extended = 1;

  printNewScreen();
  printGamemodes();
  while (handleValid != 1) {
    printf("\n");
    printCustom("Select option: ", 1);
    fgets(handle, 45, stdin);
    if (strcmp(handle, "shotgun\n") == 0 || strcmp(handle, "revolver\n") == 0 || strcmp(handle, "rifle\n") == 0) handleValid = 1;
    else {
      printNewScreen();
      printGamemodes();
    }
  }
  printNewScreen();
  printStartingLocation();
}
