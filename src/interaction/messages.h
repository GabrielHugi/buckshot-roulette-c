#pragma once
#include "../gamevars/vars.h"

extern void printStats();
extern void printMenu();
extern void printCustom(char string[stdMaxChars], int isInput);
extern void printGamemodes();
extern void printPlaymodes();
extern void printStartingLocation();
extern void printSecondaryLocation();
extern void printGameLocation();
extern void printDeath(int cause);
extern void printNewScreen();
extern void printCareful();