//
// Created by Holly Strauch on 10/25/2019.
//

#include <iomanip>
#include <iostream>
#include "Property.h"

void Property::random_event(int event) {

    switch (event)
    {
        case 1: this->hurricane();
            break;
        case 2: this->tornado();
            break;
        case 3: this->earthquake();
            break;
        case 4: this->wildfire();
            break;
        case 5: this->crash();
            break;
        case 6: this->gent("temp");
            break;
    }
}

void Property::hurricane() {

    if(!this->location.compare("SE")){
        return;
    }

    this->value *= .5;
}

void Property::tornado() {

    if(!this->location.compare("MW")){
        return;
    }

    this->value *= .7;
}

void Property::earthquake() {

    if(!this->location.compare("NW")){
        return;
    }

    this->value *= .9;
}

void Property::wildfire(){
    if(!this->location.compare("SW")){
        return;
    }

    this->value *= .75;

}

void Property::crash(){
    this->value *= .7;
}

void Property::gent(string loc){
    if(!this->location.compare(loc)){
        return;
    }

    this->value += this->value * .2 ;

}

void Property::set_loc(){
    int loc = rand() % 5;

    switch(loc) {
        case 0:
            this->location = "NW";
            break;
        case 1:
            this->location = "SE";
            break;
        case 2:
            this->location = "NE";
            break;
        case 3:
            this->location = "MW";
            break;
        case 4:
            this->location = "SW";
    }
}

string Property::get_type() const{
    return type;
}

int Property::get_value() const{
    return this->value;
}
string Property::get_loc() const{
    return this->location;
}

int Property::get_num_tenants() const{
    return this->num_tenants;
}

int Property::get_mort() const {
    return this->mortgage;
}

Tenant Property::get_tenant(int index) const {
    return this->tenants[index];
}

int Property::get_rent() const {
    return this->rent;
}

int Property::get_duration() const {
    return this->dur_mortgage;
}

int Property::get_tax() const {
    return this->propery_tax;
}

void Property::inc_prop_val(){
    this->value += (int)(this->value *.01);
    this->propery_tax = this->value * .015;
}

void Property::dec_duration(){
    this->dur_mortgage--;
}


std::string Property::toString() const {

    cout << std::setprecision(2) << std::fixed;
    string prop;

    prop.append(this->get_type());
    prop.append("\t $");
    prop.append(to_string(this->get_value()));
    prop.append("\t ");
    prop.append(get_loc());
    prop.append("\t ");
    prop.append(to_string(this->get_num_tenants()));
    prop.append("\t $");
    prop.append(to_string(this->get_mort()));

    return prop;
}

