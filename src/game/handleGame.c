#include "../gamevars/vars.h"
#include "../tools/tools.h"
#include "handleGame.h"
#include <time.h>
#include <stdlib.h>

void prepareGame() {
  srand(time(NULL));
}

void sortUpShells(int left, int right) {
  // quicksort
  int pivot = rand() % currentGame.weapon->capacity;
  int pivotVal = currentGame.weapon->loadOrder[pivot];
  byte anew[currentGame.weapon->capacity];
  for (int i = 0; i < currentGame.weapon->capacity; i++) {
    if (currentGame.weapon->loadOrder[i] <= pivotVal) {
      anew[left] = currentGame.weapon->loadOrder[i];
      left++;
    }
    if (currentGame.weapon->loadOrder[i] > pivotVal) {
      anew[right] = currentGame.weapon->loadOrder[i];
      right--;
    }
  }







    

}

void generateShells(int pre) {
  // pre is for story mode
  // wtf is pre i forgot
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

void shuffleShells() {

}