//
// Created by Holly Strauch on 10/27/2019.
//

#ifndef REAL_ESTATE_TYCOON_HOUSE_H
#define REAL_ESTATE_TYCOON_HOUSE_H

#include "Property.h"

class House:public Property{
public:
    House();
    House &operator= (House &right);
    virtual int pay_rent() const;
};


#endif //REAL_ESTATE_TYCOON_HOUSE_H
