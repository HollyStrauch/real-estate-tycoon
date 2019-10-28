//
// Created by Holly Strauch on 10/28/2019.
//

#ifndef REAL_ESTATE_TYCOON_GAME_H
#define REAL_ESTATE_TYCOON_GAME_H

#include "House.h"
#include "Apt.h"
#include "Business.h"

class Game {
    House* avail_h;
    Apt* avail_a;
    Business* avail_b;
public:
    Game();
    void start_game();
    void print_avail_p();

};


#endif //REAL_ESTATE_TYCOON_GAME_H
