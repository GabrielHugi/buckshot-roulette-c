#pragma once
#include <time.h>
typedef unsigned char byte;
struct gun;

struct game {
  // prize
  long int prize;
  // 0 = shotgun, 1 = revolver, 2 = rifle
  struct gun *weapon;
  // 0 = no, 1 = yes
  byte extended;
  // mode: 1 = pve, 2 = pvp(local), 3 = pvp(internet) --- idk why this isn't 0 indexed but it's joever
  byte mode;
  // 0 = story, 1 = endless
  byte endless;
  // phase depends on if its story or endless or wathever
  //story
  /*
    phases:
    0 - start
    1 - sign the waiver
    2 - waver signed
    3 - show bullets
    */
  byte phase;
  // who's turn, 0 - player, 1 - dealer
  byte turn;
  // over? if so what cause
  // 0 = not, 1 = fall, 2 = shot to death
  byte over;
  // who won
  // 0 = none, 1 = player, 2 = dealer
  byte winner;
  // rounds for endless
  int rounds;
  // round start time
  time_t roundStart;
};

struct memory {
  byte rememberedCapacity;
  byte rememberedLives;
  byte rememberedBlanks;
};

// player "object" (but let's agree to not call it object because object oriented programming is for losers, so we call it based C structure for based code devs)
struct character {
  /*
  id is for uniquely identifying which character is which. currently we only have offline so only
  player and dealer so we can just make it easy and call 
  0 = player
  1 = dealer  
  */
  byte id;
  char name[7];
  byte hp;
  byte inv[8];
  struct memory *memory;
};

struct gun {
  // 0 = nothing, 1 = blank, 2 = live
  byte loadOrder[31];
  // ammount of hp this takes
  byte damage;
  // max bullets
  byte capacity;
  // current bullets
  byte currentBullets;
  // idk why
  char name[10];
};

struct item {
  /*
  official items
  -1 - null
  0 - Burner Phone, gives advice on future
  1 - Beer, ejects one shell
  2 - Adrenaline, lets you steal sum shit
  3 - Cigarette pack, heals 1 hp
  4 - Expired medicine, 50% heals 2 hp, 50% lose 1 hp
  5 - Hand saw, makes gun do 2x damage, on revolver it will make it have a 50% chance of missing the shot
  6 - Handcuffs & Jammer, opponent doesn't play next round
  7 - Inverter, inverts round
  8 - Magnifying glass, sees current round
  additions for extended mode
  9 - Rusty handgun, 50% chance to hit him for 1 hp, 50% change explode on you for 1 hp (Is an item not a main weapon, you still have the turn regardless of outcome)
  a (in ascii) - Body armor, tanks up 1 hp on the next hit but the next hit has to come in the immediate next round, otherwise the armor breaks cuz its old and shit
  b - Running shoes, lets you attempt to run away with wathever money you already have, 70% chance of failure
  c - Coffe, racks a random number of shells between 1 and 4 with the chance for 2 shells being 2/5, the rest having evenly distributed chances 
  additions for sigma mode
   - Mogging, makes your opponent look ugly and takes 1 hp from him, but there is a 20% chance that you will be the one considered ugly and your self steem will be obliterated for 2 points
   - 
  */
  int effect;
    
};
// the game
extern struct game currentGame;
// the player
extern struct character player;
// the dealer
extern struct character dealer;
// guns
extern struct gun shotgun;
extern struct gun rifle;
extern struct gun revolver;

// constants
extern const int stdMaxChars;

extern int prepareVariables();
