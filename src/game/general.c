#include "general.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../gamevars/vars.h"
#include "../interaction/messages.h"
#include "handleGame.h"

//global handles et cetera
char handle[50];
char **words;
int handleValid = 0;
int option;

//functions

/* example of how to call this fun
  char *words[] = {"sigma\n", "boy\n"};
  askLoop(&handleValid, "pick an option: ", words, 2, printStartingLocation);
*/
// responds with position of option chosen
void treatFGets(char *skibidi) {
  skibidi[strlen(skibidi)-1] = '\0';
}

int askLoop(int *handleValid, char *message, char **options, int optionNumber, void (printScreen(void))) {
  while (*handleValid != 1) {
    printf("\n");
    printCustom(message, 1);
    fgets(handle, 45, stdin); treatFGets(handle);
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

// end of functions (functions as in tools of course)

int pveGame() {
  printNewScreen();
  printStartingLocation();
  words = (char *[]){ "door", "pill" };
  option = askLoop(&handleValid, "Select interaction:", words, 2, printStartingLocation);
  if (option == 0) currentGame.endless = 0;
  if (option == 1) currentGame.endless = 1;

  printNewScreen();
  printSecondaryLocation();
  words = (char *[]){ "door", "bars" };
  option = askLoop(&handleValid, "Select interaction:", words, 2, printSecondaryLocation);
  if (option == 1) {
    printNewScreen();
    printDeath(0);
    return 1;
  }

  //da game
  currentGame.phase = 0;
  printNewScreen();
  printGameLocation();
  sleep(2);

  currentGame.phase = 1;
  printNewScreen();
  printGameLocation();
  while (handleValid != 1) {
    printf("\n");
    printCustom("Name:", 1);
    fgets(handle, 45, stdin); treatFGets(handle);
    //for (int i = 0; i < optionNumber; i++) {
    //  if(strcmp(handle, options[i]) == 0) *handleValid = 1;
    //}
    if(strlen(handle) <= 6 && strcmp("god\n", handle)) {
      handleValid = 1;
    }
    else {
      printNewScreen();
      printGameLocation();
    }
  } handleValid = 0;
  strcpy(player.name, handle);

  currentGame.phase = 2;
  printNewScreen();
  printGameLocation();
  sleep(3);

  // starting the actual gameplay

  while (currentGame.over == 0) {
    //per turn vars
    byte option;
    struct character *current = &player;
    struct character *target = &dealer;

    //show hands + prepare round
    generateShells(0);
    generateHP();
    currentGame.phase = 3;
    printNewScreen();
    printGameLocation();
    sleep(3);
    
    while (currentGame.weapon->currentBullets != 0) {
      //player turn
      currentGame.phase = 4;
      printNewScreen();
      printGameLocation();
      printPlayOption();
      while (handleValid != 1) {
        printf("\n");
        printCustom("Choose:", 1);
        scanf("%hhu", &option);
        while (getchar() != '\n');
        if(option == 1 || option == 2) {
          handleValid = 1;
        }
        else {
          printNewScreen();
          printGameLocation();
          printPlayOption();
        }
      } handleValid = 0;
      if (option == 1) target = &player;
      else target = &dealer;
      current = resolveTurn(current, target, &dealer);

      // result screen
      sleep(3);

      //dealer turn
      // for now will just always shoot for testing
      currentGame.phase = 5;
      printNewScreen();
      printGameLocation();
      printPlayOption();
      option = 2;
      if (option == 1) target = &dealer;
      else target = &player;
      current = resolveTurn(current, target, &player);

      // result screen
      sleep(3);
    }
  }

}

int pvpGame() {

}

int multiplayerGame() {

}

int initiateGame() {
  // test screens
if (2 == 1) {
  currentGame.weapon = &shotgun;
  currentGame.mode = 1;
  generateShells(0);
  sortUpShells();
  currentGame.phase = 3;
  printGameLocation();
}
else {
  printNewScreen();
  printMenu();
  words = (char *[]){ "normal", "extended"};
  option = askLoop(&handleValid, "Select option:", words, 2, printMenu);
  // sets result
  if (option == 0) currentGame.extended = 0;
  else currentGame.extended = 1;

  printNewScreen();
  printGamemodes();
  words = (char *[]){ "shotgun", "revolver", "rifle" };
  option = askLoop(&handleValid, "Select option:", words, 3, printGamemodes);
  if (option == 0) currentGame.weapon = &shotgun;
  if (option == 1) currentGame.weapon = &revolver;
  if (option == 2) currentGame.weapon = &rifle;

  printNewScreen();
  printPlaymodes();
  words = (char *[]){ "pve", "pvp", "multiplayer" };
  option = askLoop(&handleValid, "Select option:", words, 3, printPlaymodes);
  if (option == 0) {currentGame.mode = 1; pveGame();}
  if (option == 1) {currentGame.mode = 2; pvpGame();}
  if (option == 2) {currentGame.mode = 3; multiplayerGame();}








// test screens, to remove test screens remove the if else }
}
}
