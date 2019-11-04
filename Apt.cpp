//
// Created by Holly Strauch on 10/27/2019.
//

#include "Apt.h"
#include <iostream>

/**
 * \brief constructor
 */
Apt::Apt(){
    this->value = (rand() % 4 + 3) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;
    this->rent = 0;

    this->type = "APARTMENT";
    this->num_tenants = (rand() % 10 + 1);

    this->tenants = new Tenant[num_tenants];

    this->location = rand() % 5;
}

/**
 * \brief Assignment operator override
 * @param right The Apt to assign values from
 * @return new Apt
 */
Apt & Apt::operator= (Apt &right){

    if (&right == this)
        return (*this);

    this->value = right.value;
    this->mortgage = right.mortgage;
    this->propery_tax = right.propery_tax;
    this->dur_mortgage = right.dur_mortgage;
    this->rent = right.rent;

    this->type = right.type;
    this->num_tenants = right.num_tenants;
    this->location = right.location;

    this->tenants = new Tenant[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = right.tenants[i];
    }
    return (*this);
}

/**
 * \brief Copy Constructor
 * @param orig Apt
 */
Apt::Apt(const Apt &orig) {
    this->value = orig.value;
    this->mortgage = orig.mortgage;
    this->propery_tax = orig.propery_tax;
    this->dur_mortgage = orig.dur_mortgage;
    this->rent = orig.rent;

    this->type = orig.type;
    this->num_tenants = orig.num_tenants;
    this->location = orig.location;

    this->tenants = new Tenant[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = orig.tenants[i];
    }
}

/**
 * \brief Destructor
 */
Apt::~Apt(){
    delete tenants;
    tenants = nullptr;
}

/**
 * \brief Iterates through tenants and totals the money from each one.  Tenants may move out or not pay if amount is
 *      too high
 * @return Total rent money collected (integer)
 */
int Apt::pay_rent(){
    int total = 0;
    int counter = 0;

    for(int i = 0; i < this->num_tenants; i++) {
        while(!this->get_tenant(counter).get_exists()){
            counter++;
        }

        if (this->get_tenant(counter).get_budget() > this->rent) {
            total += this->rent;
        } else if (this->get_tenant(counter).get_agree() > 1) {
            this->get_tenant(counter).leave();
            cout << "~~ Tenant has moved out ~~" << endl;
            this->num_tenants--;
        } else {
            cout << "XX Someone is refusing to pay rent XX" << endl;
        }
    }
    return total;
}

/**
 * \brief Sets the rent for the Apt object
 */
void Apt::set_rent() {
    cout << "Current rent: " << this->rent << "\n Enter new rent amount: " << endl;
    int price = user_input_price();

    this->rent = price;
}