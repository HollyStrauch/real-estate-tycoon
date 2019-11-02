//
// Created by Holly Strauch on 10/25/2019.
//

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Player.h"

using namespace std;

Player::Player(string name){
    this->name = name;
    this->bank_account = 50000;
    this->num_prop = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

Player::~Player(){

    Node *temp = this->head;
    for (int i = 0; i < this->num_prop; i++){

        delete head->p;
        head->p = NULL;

        this->head = head->next;

        delete temp;
        temp = this->head;
    }

    head = nullptr;
    tail = nullptr;
}

void Player::adjust_rent(){

    cout << "+-$ ADJUST RENT $-+ \n Listing all owned properties. " << endl;
    this->print_prop();
    int index = 0;

    index = user_input_prop(this->num_prop);

    cout << "Enter the new rent amount" << endl;
    int price = user_input_price();

    Property* prop = get_prop(index - 1);
    prop->set_rent(price);

    cout << "Way to do your landlording duties!";
}

void Player::sell_property() {

    cout << "$$ SELL PROPERTIES $$ \n Listing all owned properties.  Properties must contain no tenants in order to sell." << endl;
    this->print_prop();
    int index = 0;

    do {
        index = user_input_prop(this->num_prop);
    }while(!check_avail(index - 1));

    Property* sell = get_prop(index - 1);
    sale_price(sell->get_value());

    del_at_index(index - 1);
}

void Player::print_prop() {

    cout <<  "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments" << endl;

    Node *temp = this->head;
    for (int i = 0; i < this->num_prop; i++){

        cout << i + 1 << temp->p->toString() << endl;
    }

    delete temp;

}

void Player::del_at_index(int index){

    Node* temp = this->head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    Node* del = temp->next;
    temp->next = temp->next->next;

    this->num_prop--;

    delete del;
    delete temp;
}

Property* Player::get_prop(int index){
    Node* temp = this->head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    return temp->p;
}


int Player::user_input_prop(int total){

    cout << "Enter the number of the property you would like to select" << endl;

    while (true){
        string input;
        getline(cin, input);

        try{
            int num = stoi(input);
            if( num > 0 && num <= total){
                return num;
            }
        }catch(invalid_argument const &e){
            cout << "Invalid entry, please try again" << endl;
        }
    }

}

void Player::sale_price(double prop_value) {

    cout << "Enter the amount you'd like to sell the property for";
    double price = user_input_price();
    int r = rand() % 3 + 1;

    switch(r){
        case 1: cout << "What a fantastic piece of property!! Your price as been accepted!" << endl;
            this->bank_account += (int) price;
            break;
        case 2: cout << "The buyer will pay the property value" << endl;
            this->bank_account += (int) prop_value;
            break;
        case 3: cout << "No one likes your property. You'll get 10% less than property value" << endl;
            this->bank_account += (int)(prop_value * .9);
    }
}

int Player::user_input_price(){

    while (true){
        string input;
        getline(cin, input);

        try{
            int num = stod(input);
            if( num > 0 ){
                return num;
            }
        }catch(invalid_argument const &e){
            cout << "Invalid entry, please try again" << endl;
        }
    }
}

bool Player::check_avail(int index){
    Node* temp = this->head;

    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    if(temp->p->get_num_tenants() == 0){
        cout << "Property is available to sell" << endl;
        return true;
    }else{
        cout << "Property contains tenants and is unavailable to sell" << endl;
        return false;
    }
}

int Player::get_bank_account() {
    return this->bank_account;
}

//may change to collect separately between business and citizen
void Player::collect_rent() {

    Node* temp = this->head;
    for(int i = 0; i < this->num_prop; i++){
        int counter = 0;
        for(int j = 0; j < temp->p->get_num_tenants(); j++){
            while(!temp->p->get_tenant(counter).get_exists()){
                counter++;
            }
            if (temp->p->get_tenant(counter).get_budget() > temp->p->get_rent()){
                this->bank_account += temp->p->get_rent();

                if (! temp->p->get_tenant(counter).get_type()){
                    temp->p->inc_prop_val();
                }
            }else if (temp->p->get_tenant(counter).get_agree() > 1){
                temp->p->get_tenant(counter).set_not_exist();
            }

        }
        temp = temp->next;
    }
}

void Player::pay_mort() {
    Node* temp = this->head;

    for(int i = 0; i < this->num_prop; i++){

        if(temp->p->get_duration() <= 0) {
            temp = temp->next;
            continue;
        }

        this->bank_account -= temp->p->get_mort();
        temp->p->dec_duration();

        cout << "--$ You payed $" << temp->p->get_mort() << " on property " << i+ 1 << ". Only " <<
            temp->p->get_duration() << " payments left! --$" << endl;

        temp = temp->next;
    }
}

void Player::pay_prop_tax() {
    Node* temp = this->head;

    for(int i = 0; i < this->num_prop; i++){
        this->bank_account -= temp->p->get_tax();

        cout << "--$ You payed $" << temp->p->get_tax() << " on property " << i + 1 << " --$" << endl;
        temp = temp->next;
    }

    cout << "Was it worth it?" << endl;
}

void Player::buy_prop(Property *prop) {
    Node * newProp = new Node;
    newProp->p = prop;
    newProp->next = nullptr;

    this->tail->next = newProp;
    this->tail = newProp;

    num_prop++;
}

void Player::random_event() {

    cout << "?? RANDOM EVENT!! What fate shall befall your properties? ??" << endl;

    Node* temp = this->head;
    int event = rand() % 6 + 1;

    for(int i = 0; i < this->num_prop; i++){
        temp->p->random_event(event);
    }

}