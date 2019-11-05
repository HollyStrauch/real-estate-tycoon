/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: main.cpp
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * main file runs the game.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"


int main(){

    srand(time(NULL));

    Game new_game = Game();
    new_game.start_game();

    return 0;
}

