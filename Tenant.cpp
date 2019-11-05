/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Tenant.cpp
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Tenant class is used in Properties and have differing ranges of budgets dependant on type.
 */

#include "Tenant.h"
#include <stdlib.h>

/**
 * Constructor
 * @param type dictates if it is a business or a citizen, effects budget
 */
Tenant::Tenant(bool type){

    this->type = type;
    this->agree = rand() % 5 + 1;
    this->exists = true;

    if (type){
        // citizen
        this->budget = (rand() % 45 + 5) * 100;
    }else{
        // business
        this->budget = (rand() % 8 + 2) * 1000;
    }
}

/**
 * \brief Default constructor sets values to citizen
 */
Tenant::Tenant(){
    this->type = true;
    this->exists = true;
    this->agree = rand() % 5 + 1;
    this->budget = (rand() % 45 + 5) * 100;
}

/**
 * Copy constructor
 * @param orig, the Tenant being copied from
 */
Tenant::Tenant(const Tenant &orig){
    this->type = orig.type;
    this->agree = orig.agree;
    this->exists = orig.exists;
    this->budget = orig.budget;
}

/**
 * Assignement operator override
 * @param right, an initialized Tenant
 * @return this Tenant with copied values
 */
Tenant & Tenant::operator= (Tenant &right){

    if (&right == this)
        return (*this);

    this->type = right.get_type();
    this->exists = right.get_exists();
    this->agree = right.get_agree();
    this->budget = right.get_budget();

    return (*this);
}

/**
 * \brief sets the type and budget values in tenant to business
 */
void Tenant::set_business() {
    this->type = false;
    this->budget = (rand() % 8 + 2) * 1000;
}

///Returns this agreability score
int Tenant::get_agree() const {
    return this->agree;
}

///Returns this budget
int Tenant::get_budget() const {
    return this->budget;
}

///Returns this type as a bool
bool Tenant::get_type() const {
    return this->type;
}

///Returns bool if exists
bool Tenant::get_exists() const {
    return this->exists;
}

///Sets exist to false
void Tenant::leave() {
    this->exists = false;
}

