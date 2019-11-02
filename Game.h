//
// Created by Holly Strauch on 10/28/2019.
//

#ifndef REAL_ESTATE_TYCOON_GAME_H
#define REAL_ESTATE_TYCOON_GAME_H

#include "House.h"
#include "Apt.h"
#include "Business.h"
#include "Player.h"

class Game {
    Property* avail_h;
    Property* avail_a;
    Property* avail_b;
public:
    Game();
    void start_game();
    void print_avail_p();
    void buy_sell_raise(Player &player1);
    bool get_input(string action);
    void buy_property(Player &player1);
    void update_listing(Player &player1, int p, int pArr);
};


#endif //REAL_ESTATE_TYCOON_GAME_H
