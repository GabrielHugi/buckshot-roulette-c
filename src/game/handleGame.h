extern void prepareGame();
extern void generateShells(int pre);
void generateHP();
extern void shuffleShells();
extern void sortUpShells();
struct character *resolveTurn(struct character *origin, struct character *target, struct character *opponent);
extern void popAmmo();