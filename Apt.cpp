//
// Created by Holly Strauch on 10/27/2019.
//

#include "Apt.h"

Apt::Apt(){
    this->value = (rand() % 3 + 3) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;

    this->type = "APT";
    this->num_tenants = (rand() % 10 + 1);
    this->tenants = new Tenant*[num_tenants];
    this->set_loc();

}

//Apt & Apt::operator= (Apt &right){
//
//
//    if (&right == this)
//        return (*this);
//
//    this->value = right.value;
//    this->mortgage = right.mortgage;
//
//
//    return (*this);
//}