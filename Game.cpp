/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Game.cpp
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Game files runs the main functionality of the game.  It tracks and controls each turn and contains those properties
 * which the player can purchase
 */

#include <iostream>
#include "Game.h"
#include "Player.h"


/**
 * \brief Runs the entire game
 */
void Game::start_game() {
    Player* player1 = new Player();
    intro();
    int turn = 1;

    while(player1->get_bank_account() < 1000000 && player1->get_bank_account() > 0) {

        player1->collect_rent();
        player1->pay_mort();
        if(turn % 12 == 0){
            cout << "--$ Time for TAXES! $--" << endl;
            player1->pay_prop_tax();
        }
        player1->random_event();
        cout << "\n$$ You currently have $" << player1->get_bank_account() << " in your account. $$" << endl;
        buy_sell_raise(*player1);

        turn++;
    }
    end_game(*player1);
}

/**
 * Constructor
 */
Game::Game(){
    this->avail_h = new House*;
    this->avail_b = new Business*;
    this->avail_a = new Apt*;

    for(int i = 0; i < 3; i++) {
        this->avail_a[i] = new Apt();
        this->avail_h[i] = new House();
        this->avail_b[i] = new Business();
    }
}

/**
 * Destructor
 */
Game::~Game(){
    for(int i = 0; i < 3; i++) {
        delete this->avail_a[i];
        delete this->avail_h[i];
        delete this->avail_b[i];
    }
    delete this->avail_a;
    delete this->avail_b;
    delete this->avail_h;
}

/**
 * Copy Constructor
 * @param orig
 */
Game::Game(const Game &orig){
    this->avail_h = new House*;
    this->avail_b = new Business*;
    this->avail_a = new Apt*;

    for(int i = 0; i < 3; i++) {
        this->avail_a[i] = orig.avail_a[i];
        this->avail_h[i] = orig.avail_h[i];
        this->avail_b[i] = orig.avail_b[i];
    }
}

/**
 * Assignment operator
 * @param orig
 * @return
 */
Game &Game::operator=(const Game &orig) {
    if (&orig == this)
        return (*this);

    this->avail_h = new House*;
    this->avail_b = new Business*;
    this->avail_a = new Apt*;

    for(int i = 0; i < 3; i++) {
        this->avail_a[i] = orig.avail_a[i];
        this->avail_h[i] = orig.avail_h[i];
        this->avail_b[i] = orig.avail_b[i];
    }

    return (*this);
}


/**
 * \brief prints out introduction to console
 */
void Game::intro(){
    for(int i = 0; i < 20; i++){
        cout << "$$$$";
    }
    cout << "\n WELCOME TO REAL ESTATE TYCOON! \nBUY, SELL, AND UP YOUR RENT UNTIL YOU BECOME A MILLIONAIRE! (or go broke)" << endl;
    cout << "\t\tLET THE CAPITALIST GAMES BEGIN!" << endl;
    for(int i = 0; i < 20; i++){
        cout << "$$$$";
    }
    cout << endl;
}

/**
 * \brief Prints out ending state to console
 * @param player1, the current player
 */
void Game::end_game(Player &player1) {
    if(player1.get_bank_account() == 0){
        for(int i = 0; i < 20; i++){
            cout << "XXXX";
        }
        cout << "\nYOU LOSE\n What a lousy capitalist you are. Go move to Norway." << endl;
        for(int i = 0; i < 20; i++){
            cout << "XXXX";
        }
    }else{
        for(int i = 0; i < 20; i++){
            cout << "$$$$";
        }
        cout << "\nWINNER!\n Look at you go, you cut-throat capitalist.  Nothing can stop you now." << endl;
        for(int i = 0; i < 20; i++){
            cout << "$$$$";
        }
    }
}

/**
 * \brief Prompts user to buy any of 3 properties, sell any number of properties, and adjust any number of rent amounts.
 * @param player1, the current player
 */
void Game::buy_sell_raise(Player &player1) {

    if (get_input("buy property")){
        buy_property(player1);
    }

    while (get_input("sell property")){
        player1.sell_property();
        cout << "Any others?" << endl;
    }

    while (get_input("adjust rent")){
        player1.adjust_rent();
        cout << "Any others?" << endl;
    }
}

/**
 * \brief Selects a random house, apt, and business that the user has the potential to buy
 * @param player1, the current player
 */
void Game::buy_property(Player &player1) {
    int p1 = rand() % 3;
    int p2 = rand() % 3;
    int p3 = rand() % 3;

    cout << "\nHere are some of our FINEST LISTINGS! Better hurry before they're off the market!" << endl;
    cout << "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments"  << endl;
    cout << "1. " << this->avail_b[p1]->toString() << endl;
    cout << "2. " << this->avail_a[p2]->toString() << endl;
    cout << "3. " << this->avail_h[p3]->toString() << endl;
    cout << "\n Alright, lets see which ones you can afford..." << endl;
    if (this->avail_b[p1]->get_value() <= player1.get_bank_account() && get_input("purchase #1")){
        update_listing(player1, p1, 1);
    }
    if (this->avail_a[p2]->get_value() <= player1.get_bank_account() && get_input("purchase #2")){
        update_listing(player1, p2, 2);
    }
    if (this->avail_h[p3]->get_value() <= player1.get_bank_account() && get_input("purchase #3")){
        update_listing(player1, p3, 3);
    }
}

/**
 * \brief Transfers the purchased property to the player and generate a new property in its place
 * @param player1, the current property
 * @param p the index of the property in the game property array
 * @param pArr specifies which game property array
 */
void Game::update_listing(Player &player1, int p, int pArr){

    if(pArr == 1){
        player1.buy_prop(this->avail_b[p]);
        this->avail_b[p] = new Business();
    }else if (pArr == 2){
        player1.buy_prop(this->avail_a[p]);
        this->avail_a[p] = new Apt();
    }else{
        player1.buy_prop(this->avail_h[p]);
        this->avail_h[p] = new House();
    }
}

/**
 * \brief prints out all the game properties
 */
void Game::print_avail_p() {

    cout << "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments" << endl;
    for(int i = 0; i < 3; i++){
        cout << i + 1 << ". " << this->avail_b[i]->toString() << endl;
    }

    for(int i = 0; i < 3; i++){
        cout << i + 4 << ". " << this->avail_a[i]->toString() << endl;
    }

    for(int i = 0; i < 3; i++){
        cout << i + 7 << ". " << this->avail_h[i]->toString() << endl;
    }
}

/**
 * Gets 'y' or 'n' input from user, validates if input is correct
 * @param action, a string denoting what the input is being applied to
 * @return boolean true if y, false if n
 */
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

        cout << "?? What was that? Please enter y or n. I believe in you." << endl;
    }
}
