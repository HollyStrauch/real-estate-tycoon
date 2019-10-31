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
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = new Tenant(false);
    }

    this->sizes = nullptr;
    this->set_loc();
}


//must set up sizes

