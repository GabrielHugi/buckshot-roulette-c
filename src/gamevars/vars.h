// player "object" (but let's agree to not call it object because object oriented programming is for losers)
struct character {
    int hp;
    char inv[8][15];
};

struct shotgun {
    // 0 = nothing, 1 = blank, 2 = live
    int loadOrder[8];
}

struct item {
    /*
    0 - 
    1 - 
    2 -
    */
    int effect;
    
}

// the player
extern struct character player;
// the dealer
extern struct character dealer;