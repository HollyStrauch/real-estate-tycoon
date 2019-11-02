//
// Created by Holly Strauch on 10/25/2019.
//

#include "Tenant.h"
#include <stdlib.h>

Tenant::Tenant(bool type){

    this->type = type;
    this->agree = rand() % 5 + 1;
    this->exists = true;

    if (type){
        // citizen
        this->budget = (rand() % 45 + 5) * 100;
    }else{
        // business
        this->budget = (rand() % 8 + 2) * 1000;
    }
}

Tenant::Tenant(){
    this->type = false;
    this->exists = false;
    this->agree = 0;
    this->budget = 0;
}

int Tenant::get_agree() const {
    return this->agree;
}

int Tenant::get_budget() const {
    return this->budget;
}

bool Tenant::get_type() const {
    return this->type;
}

bool Tenant::get_exists() const {
    return this->exists;
}

void Tenant::set_not_exist() {
    this->exists = false;
}

Tenant & Tenant::operator= (Tenant &right){

    if (&right == this)
        return (*this);

    this->type = right.get_type();
    this->exists = right.get_exists();
    this->agree = right.get_agree();
    this->budget = right.get_budget();

    return (*this);
}