//
// Created by Holly Strauch on 10/25/2019.
//

#include "Tenant.h"
#include <stdlib.h>

Tenant::Tenant(bool type){

    this->type = type;
    this->agree = rand() % 5 + 1;

    if (type){
        // citizen
        this->budget = (rand() % 45 + 5) * 100;
    }else{
        // business
        this->budget = (rand() % 8 + 2) * 1000;
    }
}