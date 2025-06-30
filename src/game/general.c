#include "general.h"
#include <stdio.h>
#include <string.h>
#include "../gamevars/vars.h"
#include "../interaction/messages.h"

//functions

/* example of how to call this fun
  char *words[] = {"sigma\n", "boy\n"};
  askLoop(&handleValid, "pick an option: ", words, 2, printStartingLocation);
*/
// responds with position of option chosen
int askLoop(int *handleValid, char *message, char **options, int optionNumber, void (printScreen(void))) {
  char handle[50];
  while (*handleValid != 1) {
    printf("\n");
    printCustom(message, 1);
    fgets(handle, 45, stdin);
    //for (int i = 0; i < optionNumber; i++) {
    //  if(strcmp(handle, options[i]) == 0) *handleValid = 1;
    //}
    for (int i = 0; i < optionNumber; i++) if(strcmp(handle, options[i]) == 0) {
      *handleValid = 0;
      return i;
    }
    printNewScreen();
    printScreen();
  }
}

int normalGame() {

}

int extendedGame() {

}

int initiateGame() {
  // test screens
if (1 == 1) {
  currentGame.gun = 0;
  printStartingLocation();
}
else {
  char handle[50];
  char **words;
  int handleValid = 0;
  int option;
  printNewScreen();
  printMenu();
  words = (char *[]){ "normal\n", "extended\n"};
  option = askLoop(&handleValid, "Select option:", words, 2, printMenu);
  // sets result
  if (option == 0) currentGame.extended = 0;
  else currentGame.extended = 1;

  printNewScreen();
  printGamemodes();
  words = (char *[]){ "shotgun\n", "revolver\n", "rifle\n" };
  option = askLoop(&handleValid, "Select option:", words, 3, printGamemodes);
  if (option == 0) currentGame.gun = 0;
  if (option == 1) currentGame.gun = 1;
  if (option == 2) currentGame.gun = 2;

  printNewScreen();
  printStartingLocation();
  words = (char *[]){ "door\n" };
  askLoop(&handleValid, "Select interaction:", words, 1, printStartingLocation);








// test screens, to remove test screens remove one }
}
}
