//
// Created by Holly Strauch on 10/27/2019.
//

#include "House.h"

House::House(){
    this->value = (rand() % 6 + 1) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;
    this->rent = 0;

    this->type = "HOUSE";
    this->num_tenants = 1;
    this->tenants = new Tenant(true);
    this->set_loc();

}

House & House::operator= (House &right){

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

    this->tenants = right.tenants;

    return (*this);
}