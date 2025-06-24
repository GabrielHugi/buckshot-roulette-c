#include "handleItem.h"
#include "../gamevars/vars.h"

void burnerPhone(struct character destination);
void beer(struct character destination);
void adrenaline(struct character destination);
void cigarettePack(struct character destination);
void expiredMedicine(struct character destination);
void handSaw(struct character destination);
void handcuffs(struct character destination);
void inverter(struct character destination);
void magnifyingGlass(struct character destination);
void rustyHandgun(struct character destination);
void bodyArmor(struct character destination);
void runningShoes(struct character destination);
void coffee(struct character destination);

void handleItem(struct character destination, struct item what) {
    //official items
    //0 - Burner Phone, gives advice on future
    if (what.effect == 0) {
        burnerPhone(destination);
    }
    //1 - Beer, ejects one shell
    if (what.effect == 1) {
        beer(destination);
    }
    //2 - Adrenaline, lets you steal sum shit
    if (what.effect == 2) {
        adrenaline(destination);
    }
    //3 - Cigarette pack, heals 1 hp
    if (what.effect == 3) {
        cigarettePack(destination);
    }
    //4 - Expired medicine, 50% heals 2 hp, 50% lose 1 hp
    if (what.effect == 4) {
        expiredMedicine(destination);
    }
    //5 - Hand saw, makes gun do 2x damage, on revolver it will make it have a 50% chance of missing the shot
    if (what.effect == 5) {
        handSaw(destination);
    }
    //6 - Handcuffs & Jammer, opponent doesn't play next round
    if (what.effect == 6) {
        handcuffs(destination);
    }
    //7 - Inverter, inverts round
    if (what.effect == 7) {
        inverter(destination);
    }
    //8 - Magnifying glass, sees current round
    if (what.effect == 8) {
        magnifyingGlass(destination);
    }
    // extended mode
    //9 -
    if (what.effect == 9) {
        rustyHandgun(destination);
    }
    //10 - 
    if (what.effect == 10) {
        bodyArmor(destination);
    }
    //11 - 
    if (what.effect == 11) {
        runningShoes(destination);
    }
    //12 - 
    if (what.effect == 12) {
        coffee(destination);
    }
}

void burnerPhone(struct character destination) {

}
void beer(struct character destination) {

}
void adrenaline(struct character destination) {

}
void cigarettePack(struct character destination) {

}
void expiredMedicine(struct character destination) {

}
void handSaw(struct character destination) {

}
void handcuffs(struct character destination) {

}
void inverter(struct character destination) {

}
void magnifyingGlass(struct character destination) {

}
void rustyHandgun(struct character destination) {

}
void bodyArmor(struct character destination) {

}
void runningShoes(struct character destination) {

}
void coffee(struct character destination) {
  
}