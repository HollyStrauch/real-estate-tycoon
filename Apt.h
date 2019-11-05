/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Apt.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Apt file creates a property with several rooms all with the same rent amount.
 */
#ifndef REAL_ESTATE_TYCOON_APT_H
#define REAL_ESTATE_TYCOON_APT_H

#include "Property.h"

class Apt:public Property {
public:
    Apt();
    Apt &operator= (const Apt &right);
    Apt(const Apt &orig);
    ~Apt();

    ///\brief Iterates through tenants and totals the money from each one.  Tenants may move out or not pay if amount is
    ///      too high
    virtual int pay_rent();
    ///\brief Sets the rent for the Apt object
    virtual void set_rent();
};


#endif //REAL_ESTATE_TYCOON_APT_H
