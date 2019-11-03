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
    int turn = 1;

    while(player1->get_bank_account() < 1000000 && player1->get_bank_account() > 0) {

        player1->collect_rent();
        player1->pay_mort();
        if(turn % 12 == 0){
            player1->pay_prop_tax();
        }
        cout << "$$ You currently have $" << player1->get_bank_account() << " in your account. $$" << endl;

        player1->random_event();
        buy_sell_raise(*player1);

        turn++;
    }

}

void Game::buy_sell_raise(Player &player1) {

    while (get_input("buy property")){
        buy_property(player1);
    }

    while (get_input("sell property")){
        player1.sell_property();
    }

    while (get_input("adjust rent")){
        player1.adjust_rent();
    }
}

void Game::buy_property(Player &player1) {
    int p1 = rand() % 3;
    int p2 = rand() % 3;
    int p3 = rand() % 3;

    cout << "Here are some of our FINEST LISTINGS! Better hurry before they're off the market!" << endl;
    cout << "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments"  << endl;
    cout << "1. " << this->avail_b[p1].toString() << endl;
    cout << "2. " << this->avail_a[p2].toString() << endl;
    cout << "3. " << this->avail_h[p3].toString() << endl;
    cout << "\n Alright, lets see which ones you can afford..." << endl;
    if (this->avail_b[p1].get_value() <= player1.get_bank_account() && get_input("purchase #1")){
        update_listing(player1, p1, 1);
    }
    if (this->avail_a[p2].get_value() <= player1.get_bank_account() && get_input("purchase #2")){
        update_listing(player1, p2, 2);
    }
    if (this->avail_h[p3].get_value() <= player1.get_bank_account() && get_input("purchase #3")){
        update_listing(player1, p3, 3);
    }
}

void Game::update_listing(Player &player1, int p, int pArr){

    if(pArr == 1){
        player1.buy_prop(&this->avail_b[p]);
        this->avail_b[p] = *(new Business());
    }else if (pArr == 2){
        player1.buy_prop(&this->avail_a[p]);
        this->avail_a[p] = *(new Apt());
    }else{
        player1.buy_prop(&this->avail_h[p]);
        this->avail_h[p] = *(new House());
    }
}

void Game::print_avail_p() {

    cout << "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments" << endl;
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

bool Game::get_input(const string action) {

    cout << "Would you like to " << action << "? y/n:";
    while (true){
        string in;
        getline(cin, in);

        if(in == "y" || in == "Y"){
            return true;

        }else if(in == "n" || in == "N"){
            return false;
        }

        cout << "?? What was that? Please enter y or n. I believe in you. ??" << endl;
    }
}
