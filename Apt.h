//
// Created by Holly Strauch on 10/27/2019.
//

#ifndef REAL_ESTATE_TYCOON_APT_H
#define REAL_ESTATE_TYCOON_APT_H

#include "Property.h"

class Apt:public Property {
public:
    Apt();
    Apt &operator= (Apt &right);
    Apt(const Apt &orig);
    virtual int pay_rent() const;
};


#endif //REAL_ESTATE_TYCOON_APT_H
