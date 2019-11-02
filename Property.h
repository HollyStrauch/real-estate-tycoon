//
// Created by Holly Strauch on 10/25/2019.
//

#ifndef REAL_ESTATE_TYCOON_PROPERTY_H
#define REAL_ESTATE_TYCOON_PROPERTY_H

#include <string>
#include "Tenant.h"
using namespace std;


class Property{
protected:
    int value;
    int mortgage;
    int dur_mortgage;
    int propery_tax;
    int num_tenants;
    int rent;
    Tenant* tenants;
    string location;
    string type;

    void set_loc();

public:
   // Property();
    virtual int get_value() const;
    virtual string get_loc() const;
    virtual int get_num_tenants() const;
    virtual string get_type() const;
    virtual int get_mort() const;
    virtual string toString() const;
    virtual Tenant get_tenant(int index) const;
    virtual int get_rent() const;
    virtual int get_duration() const;
    virtual int get_tax() const;
    virtual void set_rent(int price);
  //  Tenant* get_tenants();
 //   Property gen_random(int event);
  //  ~Property();
    virtual void inc_prop_val();
    virtual void dec_duration();
    virtual void hurricane();
    virtual void tornado();
    virtual void earthquake();
    virtual void wildfire();
    virtual void crash();
    virtual void gent(string loc);
    virtual void random_event(int event);



};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
