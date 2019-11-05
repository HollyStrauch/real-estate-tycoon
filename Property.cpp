/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Property.cpp
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Property is the parent class that contains getters and the random events that can happen to property
 */

#include <iomanip>
#include <iostream>
#include "Property.h"
#include "Tenant.h"

/**
 * Default Constructor sets all values to 0.
 */
Property::Property() {
    this->value = 0;
    this->mortgage = 0;
    this->propery_tax = 0;
    this->dur_mortgage = 0;
    this->rent = 0;

    this->type = "";
    this->num_tenants = 0;
    this->tenants = nullptr;
    this->location = 0;
}

/**
 * Destructor
 */
Property::~Property() {
    delete tenants;
}

/**
 * Property copy constructor
 * @param orig
 */
Property::Property(const Property &orig) {
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

/**
 * \brief assingment operator
 * @param orig
 * @return
 */
Property &Property::operator= (const Property &orig){
    if (&orig == this)
        return (*this);
    this->value = orig.value;
    this->mortgage = orig.mortgage;
    this->propery_tax = orig.propery_tax;
    this->dur_mortgage = orig.dur_mortgage;
    this->rent = orig.rent;

    this->type = orig.type;
    this->num_tenants = orig.num_tenants;
    this->location = orig.location;

    this->tenants = orig.tenants;

    return (*this);
}

/**
 * \brief runs an event on a property
 * @param event, int specifying what event
 * @param loc, int used int gentrification to pick a location
 */
void Property::random_event(int event, int loc) {

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
        case 6: this->gent(loc);
            break;
    }
}

/**
 * \brief decrease property value of properties in the SE by 50%
 */
void Property::hurricane() {

    if(this->location != 1){
        return;
    }

    this->value /= 2;
    cout << "--$ HURRICANE IN THE SE! " << this->get_type() << " property value dropped to $" << this->value << " $--" << endl;

}

/**
 * \brief decrease property value of properties in the MW by 30%
 */
void Property::tornado() {

    if(this->location != 3){
        return;
    }

    this->value *= .7;
    cout << "--$ TORNADO IN THE MW! " << this->get_type() << " property value dropped to $" << this->value << " $--" << endl;
}

/**
 * \brief decrease property value of properties in the NW to 10%
 */
void Property::earthquake() {

    if(this->location != 0){
        return;
    }

    this->value /= 10;
    cout << "--$ EARTHQUAKE IN THE NW! " << this->get_type() << " property value dropped to $" << this->value << " $--" << endl;
}

/**
 * \brief decrease property value of properties in the SW by 25%
 */
void Property::wildfire(){
    if(this->location != 4){
        return;
    }

    this->value *= .75;
    cout << "--$ WILDFIRE IN THE SW! " << this->get_type() << " property value dropped to $" << this->value << " $--" << endl;
}

/**
 * \brief decrease property value by 30%
 */
void Property::crash(){
    this->value *= .7;
    cout << "--$ STOCK MARKET CRASH! " << this->get_type() << " property value dropped to $" << this->value << " $--" << endl;

}

/**
 * \brief Increase property value at the location by 20%
 * @param loc, the location that values will be increased at
 */
void Property::gent(int loc){
    if(this->location != loc){
        return;
    }
    this->value += this->value / 5;
    cout << "++$ GENTRIFICATION! yay...? " << this->get_type() << " property value rose to $" << this->value << " in the "
        << get_loc(loc) << " $++" << endl;

}

/**
 * \brief returns a string representation of the location
 * @param loc, the integer representation of the location
 * @return A string location
 */
string Property::get_loc(int loc) const{

    switch(loc) {
        case 0:
            return "NW";
        case 1:
            return "SE";
        case 2:
            return "NE";
        case 3:
            return "MW";
        case 4:
            return "SW";
    }
    return "";
}

string Property::get_type() const{
    return type;
}

int Property::get_value() const{
    return this->value;
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

int Property::pay_rent(){
    return this->rent;
}

int Property::get_rent() const{
    return this->rent;
}

int Property::get_duration() const {
    return this->dur_mortgage;
}

int Property::get_tax() const {
    return this->propery_tax;
}

void Property::inc_prop_val(){
    this->value += (this->value / 100);
    this->propery_tax = this->value * .015;
}

void Property::dec_duration(){
    this->dur_mortgage--;
}

void Property::set_rent() {
    cout << "Current rent: " << this->rent << "\n Enter new rent amount: " << endl;
    int price = user_input_price();

    this->rent = price;
}

/**
 * \brief Gets an integer from the user and validates its correctness
 * @return The integer inputted from the user
 */
int Property::user_input_price(){

    while (true){
        string input;
        getline(cin, input);

        try{
            int num = stod(input);
            if( num > 0 ){
                return num;
            }
        }catch(invalid_argument const &e){
            cout << "Invalid entry, please try again" << endl;
        }
    }
}

/**
 * Creates a string representation of the property
 * @return The string representation
 */
std::string Property::toString() const {
    string val = to_string(this->get_value());
    val.resize(8);
    string prop;

    prop.append(this->get_type());
    prop.append("\t $");
    prop.append(val);
    prop.append("\t ");
    prop.append(get_loc(this->location));
    prop.append("\t ");
    prop.append(to_string(this->get_num_tenants()));
    prop.append("\t $");
    prop.append(to_string(this->get_rent()));
    prop.append("\t $");
    prop.append(to_string(this->get_mort()));
    prop.append("\t\t ");
    prop.append(to_string(this->get_duration()));

    return prop;
}

