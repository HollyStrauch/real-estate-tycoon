/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Player.cpp
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Player defines the player's state including the properties they own and the actions they can perform on them
 */

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "Player.h"

using namespace std;

Player::Player(string name){
    this->name = name;
    this->bank_account = 500000;
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
    if(index != 0) {
        Property *prop = get_prop(index - 1);
        prop->set_rent();
        cout << "Way to do your landlording duties you fat cat!" << endl;
    }else{
        cout << "Exiting..." << endl;
    }
}

/**
 * \brief Select a property, enter a desired listing price, and sell property.  Final price is decided randomly between
 *  asking price, property value, or 10% below property value
 */
void Player::sell_property() {

    cout << "$$ SELL PROPERTIES $$ \n Listing all owned properties.  Properties must contain no tenants in order to sell." << endl;
    this->print_prop();
    int index = 0;

    do {
        index = user_input_prop(this->num_prop);
    }while(index != 0 && !check_avail(index - 1));

    if(index != 0) {
        Property *sell = get_prop(index - 1);
        sale_price(sell->get_value());
        del_at_index(index - 1);
    }else{
        cout << "Exiting..." << endl;
    }
}

/**
 * \brief Print off all owned properties
 */
void Player::print_prop() {

    cout <<  "Location\t Value\t\t Loc\tTenants\tRent\t Mortgage\tPayments" << endl;

    Node *temp = this->head;
    for (int i = 0; i < this->num_prop; i++){

        cout << i + 1 << ". " << temp->p->toString() << endl;
        temp = temp->next;
    }

}

/**
 * Delete a Node at the specified index
 * @param index, the location of the Node in the linked list
 */
void Player::del_at_index(int index){

    Node* temp = this->head;
    if(this->num_prop == 1){
        delete temp->p;
        temp->next = nullptr;
        this->head = nullptr;
        this->tail = nullptr;
        delete temp;
    }else if (index == 0){
        this->head = this->head->next;
        delete temp->p;
        temp->next = nullptr;
        delete temp;
    }else{
        del_node(index);
    }
    this->num_prop--;
}

/**
 * \brief deletes nodes not at the front of the list or when list length == 1
 * @param index, the location of the Node in the linked list
 */
void Player::del_node(int index) {
    Node* temp = this->head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    if (index == this->num_prop - 1){
        this->tail = temp;
        delete temp->next->p;
        temp->next->next = nullptr;
        delete temp->next;
        this->tail->next = nullptr;
    }else{
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del->p;
        del->next = nullptr;
        delete del;
    }
}

/**
 * \brief Get a pointer to a property from a Node
 * @param index, the location of the Node in the linked list
 * @return a pointer to the property
 */
Property* Player::get_prop(int index){
    Node* temp = this->head;
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    return temp->p;
}

/**
 * \brief Gets integer input from user and validates that it is correct
 * @param total, the max integer accepted from the user
 * @return the integer number entered by the user
 */
int Player::user_input_prop(int total){

    cout << "## Enter the number of the property you would like to select, or '0' to exit. ##" << endl;

    while (true){
        string input;
        getline(cin, input);

        try{
            int num = stoi(input);
            if( num >= 0 && num <= total){
                return num;
            }
        }catch(invalid_argument const &e){
            cout << "That was not a valid number, please try again" << endl;
        }
    }

}

/**
 * \brief Takes int value from user as desired price, then randomly picks between selling property for your price,
 *  property value, or 10% under. Updates bank account
 * @param prop_value, the current value of the property
 */
void Player::sale_price(double prop_value) {
    cout << "Enter the amount you'd like to sell the property for: ";
    double price = user_input_price();
    int r = rand() % 3 + 1;
    int final = 0;

    switch(r){
        case 1: cout << "What a fantastic piece of property!! Your price as been accepted!" << endl;
            final = (int) price;
            break;
        case 2: cout << "The buyer will pay the property value" << endl;
            final = (int) prop_value;
            break;
        case 3: cout << "No one likes your property. You'll get 10% less than property value" << endl;
            final = (int)(prop_value * .9);
    }
    this->bank_account += final;
    cout << "$$ PROPERTY SOLD FOR $" << final << " $$" << endl;
}

/**
 * \brief Reads in a price from the user and validates that it is correct
 * @return The inputted price
 */
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

/**
 * \brief Check if there are no existing tenants in a property
 * @param index, the index of the Node containing the desired property
 * @return boolean true if there are no tenants, false otherwise
 */
bool Player::check_avail(int index){
    Node* temp = this->head;

    for(int i = 0; i < index; i++){
        temp = temp->next;
    }

    if(temp->p->get_num_tenants() <= 0){
        cout << "Property is available to sell" << endl;
        return true;
    }else{
        cout << "Property contains tenants and is unavailable to sell" << endl;
        return false;
    }
}

/**
 * \brief gets the player's current bank_account
 * @return bank_account
 */
int Player::get_bank_account() {
    return this->bank_account;
}

/**
 * \brief iterates through all properties and collects rent
 */
void Player::collect_rent() {
    int total = 0;
    Node* temp = this->head;

    cout << "\n$$ First of the month! Time for RENT!! $$" << endl;
    for(int i = 0; i < this->num_prop; i++){
        cout << "COLLECTING RENT ON PROPERTY " << i + 1 << endl;
        int rent =  temp->p->pay_rent();
        cout << "Collected $" << rent << " rent on property " << i + 1 << endl;
        total += rent;
        temp = temp->next;
    }
    cout << "$$ You pulled in $" << total << ". But can you get even more?? $$" << endl;
    this->bank_account += total;
}

/**
 * \brief iterates through all properties and deducts mortgage from current bank account
 */
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

/**
 * \brief iterates through properties and deducts property tax from bank account
 */
void Player::pay_prop_tax() {
    Node* temp = this->head;

    for(int i = 0; i < this->num_prop; i++){
        this->bank_account -= temp->p->get_tax();

        cout << "--$ You payed $" << temp->p->get_tax() << " on property " << i + 1 << " --$" << endl;
        temp = temp->next;
    }

    cout << "Was it worth it?" << endl;
}

/**
 * \brief Deducts value of property from bank account and adds a new Node containing the property
 * @param prop The new property being added to the player's list
 */
void Player::buy_prop(Property *prop) {
    this->bank_account -= prop->get_value();

    Node * newProp = new Node;
    newProp->p = prop;
    newProp->next = nullptr;

    if(num_prop == 0){
        this->head = newProp;
        this->tail = newProp;
    }else {
        this->tail->next = newProp;
        this->tail = newProp;
    }

    num_prop++;
}

/**
 * \brief Picks a random event and iterates through all properties, applying where applicable
 */
void Player::random_event() {

    cout << "\n?? RANDOM EVENT!! What fate shall befall your properties? ??" << endl;

    Node* temp = this->head;
    int event = rand() % 6 + 1;
    int loc = rand() % 5;

    for(int i = 0; i < this->num_prop; i++){
        temp->p->random_event(event, loc);
        temp = temp->next;
    }

}