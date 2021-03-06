/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Player.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Player defines the player's state including the properties they own and the actions they can perform on them
 */
#ifndef REAL_ESTATE_TYCOON_PLAYER_H
#define REAL_ESTATE_TYCOON_PLAYER_H

#include "Property.h"

class Player{
    int bank_account;
    int num_prop;
    string name;

    struct Node {
        Property *p;
        Node *next;
    };
    Node *head;
    Node *tail;

    void del_node(int index);

public:
    Player();
    ~Player();
    Player(const Player &orig);
    Player &operator= (const Player &orig);
    void sell_property();
    void print_prop();
    void buy_prop(Property* prop);
    void del_at_index(int index);
    Property* get_prop(int index);
    void sale_price(double prop_value);
    bool check_avail(int index);
    int get_bank_account();
    void collect_rent();
    void pay_mort();
    void pay_prop_tax();
    void adjust_rent();
    void random_event();

    static int user_input_price();
    static int user_input_prop(int total);
};

#endif //REAL_ESTATE_TYCOON_PLAYER_H
