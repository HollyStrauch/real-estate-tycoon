/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: House.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * House file creates a property with a single tenant.
 */

#ifndef REAL_ESTATE_TYCOON_HOUSE_H
#define REAL_ESTATE_TYCOON_HOUSE_H

#include "Property.h"

class House:public Property{
public:
    House();
    House &operator= (const House &right);
    House(const House &orig);
    ~House();
    virtual int pay_rent();
};


#endif //REAL_ESTATE_TYCOON_HOUSE_H
