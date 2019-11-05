/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Game.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Game files runs the main functionality of the game.  It tracks and controls each turn and contains those properties
 * which the player can purchase
 */

#ifndef REAL_ESTATE_TYCOON_GAME_H
#define REAL_ESTATE_TYCOON_GAME_H

#include "House.h"
#include "Apt.h"
#include "Business.h"
#include "Player.h"

class Game {
    House** avail_h;
    Apt** avail_a;
    Business** avail_b;
public:
    Game();
    void start_game();
    void intro();
    void print_avail_p();
    void buy_sell_raise(Player &player1);
    bool get_input(string action);
    void buy_property(Player &player1);
    void update_listing(Player &player1, int p, int pArr);
    void end_game(Player &player1);
};


#endif //REAL_ESTATE_TYCOON_GAME_H
