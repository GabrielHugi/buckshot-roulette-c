#include <stdio.h>
#include "game/general.h"
#include "gamevars/vars.h"
#include "game/handleGame.h"
/*
remembr to search how to monopolize the terminal screen like gnu nano does
this will be done later btw first i will just do raw terminal shit
*/

// curent run cmd for dev use:
// gcc src/main.c src/game/general.c src/game/handleItem.c src/gamemodes/gamemodes.c src/gamevars/vars.c src/interaction/messages.c src/game/handleGame.c src/tools/tools.c -o main
int main() {
  prepareVariables();
  prepareGame();
  initiateGame();
}