//
// Created by Holly Strauch on 10/27/2019.
//

#include "House.h"

House::House(){
    this->value = (rand() % 6 + 1) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;

    this->type = "HOUSE";
    this->num_tenants = 1;
    this->tenants = new Tenant*;
    this->set_loc();

}