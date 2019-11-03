//
// Created by Holly Strauch on 10/27/2019.
//

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
