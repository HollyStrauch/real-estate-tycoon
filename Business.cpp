//
// Created by Holly Strauch on 10/27/2019.
//

#include "Business.h"
#include "Tenant.h"


Business::Business(){
    this->value = (rand() % 3 + 4) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;
    this->rent = 0;

    this->type = "BUSINESS";
    this->num_tenants = (rand() % 5 + 1);

    this->tenants = new Tenant[num_tenants];
    this->sizes = new int[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i].set_business();
        this->sizes[i] = rand() % 3;
    }

    this->set_loc();
}

Business & Business::operator= (Business &right){
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
    this->sizes = new int[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = right.tenants[i];
        this->sizes[i] = right.sizes[i];
    }
    return (*this);
}

