//
// Created by Holly Strauch on 10/25/2019.
//
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

