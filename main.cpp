//
// Created by Holly Strauch on 10/25/2019.
//
#include "Player.h"
#include "Property.h"
#include "House.h"
#include "Apt.h"
#include "Business.h"



Property** start_props(){

    Property **start_props = new Property*;

    for(int i = 0; i < 3; i++){
        start_props[i + 0][i] = new House();
        start_props[i + 1][i] = new Apt();
        start_props[i + 2][i] = new Business();
    }

    return start_props;
}

int main(){

    //setup
    Player* player1 = new Player("Holly");

    Property** avail_props = start_props();



    return 0;
}

