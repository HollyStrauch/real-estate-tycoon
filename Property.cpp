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

double Property::get_mort() const {
    return this->mortgage;
}


