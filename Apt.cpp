//
// Created by Holly Strauch on 10/27/2019.
//

#include "Apt.h"

Apt::Apt(){
    this->value = (rand() % 6 + 3) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * 1.5;
    this->dur_mortgage = this->value / this->mortgage;

    this->num_tenants = (rand() % 10 + 1);
    this->tenants = new Tenant*[num_tenants];

}