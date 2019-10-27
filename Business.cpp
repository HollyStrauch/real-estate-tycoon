//
// Created by Holly Strauch on 10/27/2019.
//

#include "Business.h"
#include "Tenant.h"


Business::Business(){
    this->value = (rand() % 6 + 4) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * 1.5;
    this->dur_mortgage = this->value / this->mortgage;

    this->num_tenants = (rand() % 5 + 1);
    this->tenants = new Tenant*[num_tenants];
    this->sizes = new int[num_tenants];

}