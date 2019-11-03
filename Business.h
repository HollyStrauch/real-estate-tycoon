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
    virtual int pay_rent();
    virtual void set_rent();
    virtual int get_rent() const;
};


#endif //REAL_ESTATE_TYCOON_BUSINESS_H
