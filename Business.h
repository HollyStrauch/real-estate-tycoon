//
// Created by Holly Strauch on 10/27/2019.
//

#ifndef REAL_ESTATE_TYCOON_BUSINESS_H
#define REAL_ESTATE_TYCOON_BUSINESS_H

#include "Property.h"

class Business: public Property {
    int* sizes;
    int* rentSpace;

public:
    Business();
    Business &operator= (Business &right);
    virtual int get_rent() const;
    virtual void set_rent();
};


#endif //REAL_ESTATE_TYCOON_BUSINESS_H
