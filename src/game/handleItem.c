#pragma once
#include "./gamevars/vars.h";

void handleItem(struct character destination, struct item what) {
    //official items
    //0 - Burner Phone, gives advice on future
    if (what.effect == 0) {

    }
    //1 - Beer, ejects one shell
    //2 - Adrenaline, lets you steal sum shit
    //3 - Cigarette pack, heals 1 hp
    //4 - Expired medicine, 50% heals 2 hp, 50% lose 1 hp
    //5 - Hand saw, makes gun do 2x damage, on revolver it will make it have a 50% chance of missing the shot
    //6 - Handcuffs & Jammer, opponent doesn't play next round
    //7 - Inverter, inverts round
    //8 - Magnifying glass, sees current round
}