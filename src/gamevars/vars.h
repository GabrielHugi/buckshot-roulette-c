// player "object" (but let's agree to not call it object because object oriented programming is for losers)
struct character {
    int hp;
};

// the lifes player has left
extern struct character player;
// items player has
extern char playerInv[8][15];
// the lifes dealer has left
extern struct character dealer;
// items dealer has
extern char dealerInv[8][15];