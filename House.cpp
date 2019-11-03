//
// Created by Holly Strauch on 10/27/2019.
//

#include "House.h"
#include <iostream>

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

House::House(const House &orig) {
    this->value = orig.value;
    this->mortgage = orig.mortgage;
    this->propery_tax = orig.propery_tax;
    this->dur_mortgage = orig.dur_mortgage;
    this->rent = orig.rent;

    this->type = orig.type;
    this->num_tenants = orig.num_tenants;
    this->location = orig.location;

    this->tenants = orig.tenants;
}

int House::pay_rent(){

    if ( this->num_tenants == 0){
        return 0;
    }
    if (this->get_tenant(0).get_budget() > this->rent) {
        return this->rent;

    }else if (this->get_tenant(0).get_agree() > 1){
        this->get_tenant(0).leave();
        cout << "~~ Tenant has moved out ~~" << endl;
        this->num_tenants--;
    } else {
        cout << "XX Someone is refusing to pay rent XX" << endl;
    }
    return 0;
}
