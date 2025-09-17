#include "general.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "../gamevars/vars.h"
#include "../interaction/messages.h"
#include "handleGame.h"

//global handles et cetera
char handle[50];
char **words;
int handleValid = 0;
int option;

//functions

// responds with position of option chosen
void treatFGets(char *skibidi) {
  skibidi[strlen(skibidi)-1] = '\0';
}

/* example of how to call this fun
  char *words[] = {"sigma\n", "boy\n"};
  askLoop(&handleValid, "pick an option: ", words, 2, printStartingLocation);
*/
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

/* example of how to call this function fr
  askNumericLoop(&handleValid, "Choose a number (1-2): ", 1, 2, printPlayerTurnScreen);
*/
byte askNumericLoop(int *handleValid, char *message, byte min, byte max, void (*printScreen)(void)) {
  byte option;

  // The loop structure is identical to askLoop
  while (*handleValid != 1) {
    printf("\n");
    printCustom(message, 1);

    // Use scanf to attempt to read one number.
    int scanf_result = scanf("%hhu", &option);
    
    // This part is essential for scanf in a loop:
    // It clears out any leftover characters (like the '\n' or bad text)
    // to prevent an infinite loop on the next iteration.
    while (getchar() != '\n');

    // VALIDATION:
    // 1. Did scanf successfully read a number? (scanf_result == 1)
    // 2. Is that number within the allowed range?
    if (scanf_result == 1 && option >= min && option <= max) {
      *handleValid = 0; // Reset the flag, just like in askLoop
      return option;    // Return the valid numeric choice
    }

    // On invalid input, reprint the screen, just like in askLoop
    printNewScreen();
    printScreen();
  }
  return 0; // Should not be reached, but satisfies compiler
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

  int previousRound = -1;
  while (currentGame.over == 0) {
    //per turn vars
    byte option;
    struct character *current = &player;
    struct character *target = &dealer;

    //show hands + prepare round
    if (currentGame.rounds == previousRound) {
      generateShells(0);
      currentGame.phase = 3;
      printNewScreen();
      printGameLocation();
      sleep(3);
    }
    else {
      generateShells(0);
      generateHP();
      currentGame.phase = 3;
      printNewScreen();
      printGameLocation();
      sleep(3);
    }

    previousRound = currentGame.rounds;
    
    while (currentGame.weapon->currentBullets != 0 && player.hp > 0 && dealer.hp > 0) {
      if (current->id == 0) {
        //player turn
        currentGame.phase = 4;
        printNewScreen();
        printGameLocation();
        // test
        for (int i = 0; i < currentGame.weapon->capacity; i++) {
          printf("%d ", currentGame.weapon->loadOrder[i]);
        }
        printf("\n");
        // test
        option = askNumericLoop(&handleValid, "Choose:", 1, 2, printGameLocation);
        if (option == 1) target = &player;
        else target = &dealer;
        current = resolveTurn(current, target, &dealer);

        // result screen
        printf("\nYOU SHOT\n");
        sleep(3);
      }
      else {
        //dealer turn
        // for now will just always shoot for testing
        currentGame.phase = 5;
        printNewScreen();
        // test
        for (int i = 0; i < currentGame.weapon->capacity; i++) {
          printf("%d ", currentGame.weapon->loadOrder[i]);
        }
        printf("\n");
        // test
        printGameLocation();
        option = 2;
        if (option == 1) target = &dealer;
        else target = &player;
        current = resolveTurn(current, target, &player);
        sleep(3);

        // result screen
        printf("\nDEALER SHOT\n");
        sleep(3);
      }
    }
    resolvePrize();
    //prints option to play agan n shit
    if (currentGame.winner != 0) {
      currentGame.phase = 200;
      printNewScreen();
      printGameLocation();
      option = askNumericLoop(&handleValid, "Choose:", 1, 2, printGameLocation);
      if (option == 1) currentGame.rounds++;
      else currentGame.over = 1;
      current = &player;
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
  currentGame.prize = 101;
  currentGame.phase = 200;
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
