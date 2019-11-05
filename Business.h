/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Business.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Business file creates a property with several rooms of differing sizes.  Each room will have its rent set individually.
 */

#ifndef REAL_ESTATE_TYCOON_BUSINESS_H
#define REAL_ESTATE_TYCOON_BUSINESS_H

#include "Property.h"

class Business: public Property {
    int* sizes;
    int* rentSpace;

    void set_spaces();
public:
    Business();
    Business &operator= (Business &right);
    Business(const Business &orig);
    /// Returns a string value "small", "medium" or "large" based on the sizes array index
    string get_room_size(int index);
    ///Prints out the individual rooms that contain tenants along with their size and current rent amount
    void print_rooms();
    ///Iterates through tenants and totals the money from each one.  Tenants may move out or not pay if amount is
    /// too high
    virtual int pay_rent();
    ///Sets the rent of each room in the Business object
    virtual void set_rent();
    ///Overrides Property get_rent, Business has no individual rent value
    virtual int get_rent() const;
};


#endif //REAL_ESTATE_TYCOON_BUSINESS_H
