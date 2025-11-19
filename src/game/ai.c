#include <stdio.h>
#include "../gamevars/vars.h"
#include "../tools/tools.h"
#include "ai.h"
#include <stdlib.h>

void addStartToMemory (struct character *who, byte capacity, byte lives, byte blanks) {
    who->memory->rememberedCapacity = capacity;
    who->memory->rememberedLives = lives;
    who->memory->rememberedBlanks = blanks;
}

void addShotToMemory (struct character *who, byte lives, byte blanks) {
    who->memory->rememberedCapacity += (lives + blanks);
    who->memory->rememberedLives += lives;
    who->memory->rememberedBlanks += blanks;
}

int whoToShootPVE() {
    float chanceToHit = dealer.memory->rememberedLives / dealer.memory->rememberedBlanks;
    if (chanceToHit >= 1) return 2;
    else return 1;
}