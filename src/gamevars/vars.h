#pragma once
struct gun;

struct game {
  // 0 = shotgun, 1 = revolver, 2 = rifle
  struct gun *weapon;
  // 0 = no, 1 = yes
  int extended;
  // mode: 1 = pve, 2 = pvp(local), 3 = pvp(internet) --- idk why this isn't 0 indexed but it's joever
  int mode;
  // 0 = story, 1 = endless
  int endless;
};

// player "object" (but let's agree to not call it object because object oriented programming is for losers)
struct character {
  char name[7];
  int hp;
  int inv[8];
};

struct gun {
  // 0 = nothing, 1 = blank, 2 = live
  int loadOrder[31];
  // ammount of hp this takes
  int damage;
  // max bullets
  int capacity;
  // current bullets
  int currentBullets;
  // name for redundancy and object shit idk also useful so i don't have to waste time coding this garbage
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
