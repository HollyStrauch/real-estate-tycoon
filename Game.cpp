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

    print_avail_p();

}

void Game::print_avail_p() {

    cout << "Location\t Value\t\t Loc\tTenants\t Mortgage" << endl;
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ". " << this->avail_b[i].toString() << endl;
    }

    for(int i = 0; i < 3; i++){
        cout << i + 4 << ". " << this->avail_a[i].toString() << endl;
    }

    for(int i = 0; i < 3; i++){
        cout << i + 7 << ". " << this->avail_h[i].toString() << endl;
    }
}