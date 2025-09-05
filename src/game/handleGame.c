#include "../gamevars/vars.h"
#include "../tools/tools.h"
#include "handleGame.h"
#include <time.h>
#include <stdlib.h>

void prepareGame() {
  srand(time(NULL));
}

void sortUpShells() {
  int left = 0, right = currentGame.weapon->capacity;
  byte anew[currentGame.weapon->capacity];
  for (int i = 0; i <= currentGame.weapon->capacity; i++) {
    if (currentGame.weapon->loadOrder[i] >= 1) {
      anew[left] = currentGame.weapon->loadOrder[i];
      left++;
    }
    if (currentGame.weapon->loadOrder[i] < 1) {
      anew[right] = currentGame.weapon->loadOrder[i];
      right--;
    }
  }
  for (int i = 0; i < currentGame.weapon->capacity; i++) currentGame.weapon->loadOrder[i] = anew[i];
  return;
}

void generateShells(int pre) {
  // pre is for story mode
  // wtf is pre i forgot
  // oh yeah its cuz story mode has non random
  // gun
  if (pre == 0) {
    unsigned char bullets = 0;
    // -> = implicit deference, needed here cuz weapon is a pointer to an object not a real object
    for (int i = 0; i < currentGame.weapon->capacity; i++) {
      int bullet = rand() % 3;
      currentGame.weapon->loadOrder[i] = bullet;
      if (bullet != 0) bullets++;
    }
    currentGame.weapon->currentBullets = bullets;
  }
  if (pre == 1) {
    //uhh idk
    // if (strcmp(currentGame.weapon->name, "shotgun" && currentGame.mode == 1) == 0) {
  }
}

// this prob useless
void shuffleShells() {

}

void popAmmo() {
    if (currentGame.weapon->currentBullets == 0) return;
    int first = 0, last = currentGame.weapon->currentBullets-1;
    for (int i = 1; i < last; i++) {
      currentGame.weapon->loadOrder[i-1] = currentGame.weapon->loadOrder[i];
    }
    currentGame.weapon->loadOrder[last] = 0;
    return;
}