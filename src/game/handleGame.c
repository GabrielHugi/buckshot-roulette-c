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
    byte bullets = 0;
    byte blanks = 0, lives = 0;
    // -> = implicit deference, needed here cuz weapon is a pointer to an object not a real object
    // so equivalent to (*currentGame.weapon).capacity
    for (int i = 0; i < currentGame.weapon->capacity; i++) {
      int bullet = rand() % 3;
      currentGame.weapon->loadOrder[i] = bullet;
      if (bullet != 0) bullets++;
      if (bullet == 1) blanks++;
      if (bullet == 2) lives++;
    }
    // check as to not allow for a full concentratio of live or blank rounds
    if (blanks == 0) {
      for (int i = 0; i < bullets; i++) {
        if (currentGame.weapon->loadOrder[i] == 0) {
          currentGame.weapon->loadOrder[i] = 1;
          break;
        }
        if (currentGame.weapon->loadOrder[i] == 2 && bullets > 1) {
          currentGame.weapon->loadOrder[i] = 1; bullets++;
          break;
        }
      }
    }
    if (lives == 0) {
      for (int i = 0; i < bullets; i++) {
        if (currentGame.weapon->loadOrder[i] == 0) {
          currentGame.weapon->loadOrder[i] = 2;
          break;
        }
        if (currentGame.weapon->loadOrder[i] == 1 && bullets > 1) {
          currentGame.weapon->loadOrder[i] = 2; bullets++;
          break;
        }
      }
    }
    currentGame.weapon->currentBullets = bullets;
  }
  if (pre == 1) {
    //uhh idk
    // if (strcmp(currentGame.weapon->name, "shotgun" && currentGame.mode == 1) == 0) {
  }
  sortUpShells();
}

void generateHP() {
  byte hp = (rand() % 4)+2;
  player.hp = hp;
  dealer.hp = hp;
}

void resolveEndgame() {
  if (player.hp == 0) {
    currentGame.winner = 1;
  }
  if (dealer.hp == 0) {
    currentGame.winner = 2;
  }
  // mayube print the win screen so asking like "yo bro wanna play again"
  //if (currentGame.winner != 0 && currentGame.over != 0) 
}

struct character *resolveTurn(struct character *origin, struct character *target, struct character *opponent) {
  if (currentGame.weapon->loadOrder[currentGame.weapon->currentBullets-1] == 2) {
    target->hp--;
    currentGame.weapon->loadOrder[currentGame.weapon->currentBullets-1] = 0;
    currentGame.weapon->currentBullets--;
    if (target == origin) return opponent; 
  }
  else if (currentGame.weapon->loadOrder[currentGame.weapon->currentBullets-1] == 1) {
    currentGame.weapon->loadOrder[currentGame.weapon->currentBullets-1] = 0;
    currentGame.weapon->currentBullets--; 
  }
  resolveEndgame();
  return target;
}

void resolvePrize() {
  if (currentGame.mode == 0) {
    // do not care
  }
  if (currentGame.mode == 1) {
    
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