#include "vars.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct game currentGame;
struct character player;
struct character dealer;
struct gun shotgun;
struct gun rifle;
struct gun revolver;
const int stdMaxChars = 150;

int prepareVariables () {
    shotgun.damage = 1;
    shotgun.capacity = 8;
    strcpy(shotgun.name, "shotgun");
    revolver.damage = 4;
    revolver.capacity = 6;
    strcpy(revolver.name, "revolver");
    rifle.damage = 1;
    rifle.capacity = 30;
    strcpy(rifle.name, "rifle");
    strcpy(dealer.name, "dealer");
    for (int i = 0; i < 8; i++) {
        player.inv[i] = -1;
        dealer.inv[i] = -1;
    }
    currentGame.phase = 0;
    currentGame.over = 0;
}
