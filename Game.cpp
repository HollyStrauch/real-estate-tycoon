//
// Created by Holly Strauch on 10/28/2019.
//

#include <iostream>
#include "Game.h"
#include "Player.h"

Game::Game(){
    this->avail_a = new Apt[3];
    this->avail_h = new House[3];
    this->avail_b = new Business[3];
}

void Game::start_game() {
    Player* player1 = new Player("Holly");

}