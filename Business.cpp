//
// Created by Holly Strauch on 10/27/2019.
//

#include <iostream>
#include "Business.h"
#include "Tenant.h"


Business::Business(){
    this->value = (rand() % 3 + 4) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;

    this->type = "BUSINESS";
    this->num_tenants = (rand() % 5 + 1);

    this->rentSpace = new int[num_tenants];
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

int Business::pay_rent(){
    int total = 0;
    int counter = 0;

    for(int i = 0; i < this->num_tenants; i++) {
        while(!this->get_tenant(counter).get_exists()){
            counter++;
        }

        if (this->get_tenant(counter).get_budget() > this->rentSpace[counter]) {
            total += this->rentSpace[counter];
            this->value += this->value / 10;
        } else if (this->get_tenant(counter).get_agree() > 1) {
            this->get_tenant(counter).leave();
            cout << "~~ Tenant has moved out ~~" << endl;
        } else {
            cout << "XX Someone is refusing to pay rent XX" << endl;
        }
    }
    return total;
}

void Business::set_rent() {
    int count = 0;
    for(int i = 0; i < this->num_tenants; i++){
        while(!this->get_tenant(count).get_exists()){
            count++;
        }

        cout << "Room #" << count + 1 << " current rent: " << this->rentSpace[count] << "\n Enter new rent amount: " << endl;
        int price = user_input_price();

        this->rentSpace[count] = price;
    }

}

int Business::get_rent() const {
    return 0;
}
