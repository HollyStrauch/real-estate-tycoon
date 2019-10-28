//
// Created by Holly Strauch on 10/25/2019.
//

#ifndef REAL_ESTATE_TYCOON_PLAYER_H
#define REAL_ESTATE_TYCOON_PLAYER_H

#include "Property.h"

class Player{
    double bank_account;
    int num_prop;
    //Property* props;
    string name;

    struct Node {
        Property *p;
        Node *next;
    };
    Node *head;
    Node *tail;

public:
    Player(string name);
    ~Player();
    void sell_property();
    void print_prop();
    Property buy_prop(Property* prop);
    void del_at_index(int index);
    Property* get_prop(int index);
    int user_input_prop(int total);
    void sale_price(double prop_value);
    bool check_avail(int index);
    double user_input_price();
};

#endif //REAL_ESTATE_TYCOON_PLAYER_H
