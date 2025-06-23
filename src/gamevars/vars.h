// player "object" (but let's agree to not call it object because object oriented programming is for losers)
struct character {
    int hp;
    char inv[8][15];
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
};

struct item {
    /*
    official items
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
    10 - Body armor, tanks up 1 hp on the next hit but the next hit has to come in the immediate next round, otherwise the armor breaks cuz its old and shit
    11 - Running shoes, lets you attempt to run away with wathever money you already have, 70% chance of failure
    12 - Coffe, racks a random number of shells between 1 and 4 with the chance for 2 shells being 2/5, the rest having evenly distributed chances 
    additions for sigma mode
     - Mogging, makes your opponent look ugly and takes 1 hp from him, but there is a 20% chance that you will be the one considered ugly and your self steem will be obliterated for 2 points
     - 
    */
    int effect;
    
};

// the player
extern struct character player;
// the dealer
extern struct character dealer;
// shotgun
extern struct item shotgun;
