#include "vars.h"
#include <time.h>
#include <stdlib.h>

struct game currentGame;
struct character player;
struct character dealer;
struct gun shotgun;
struct gun rifle;
struct gun revolver;

int prepareVariables () {
    shotgun.damage = 1;
    shotgun.capacity = 8;
    revolver.damage = 4;
    revolver.capacity = 6;
    rifle.damage = 1;
    rifle.capacity = 30;
}
