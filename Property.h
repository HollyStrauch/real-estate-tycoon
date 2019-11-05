/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Property.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Property is the parent class that contains getters and the random events that can happen to property
 */

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
    int location;
    string type;

    void set_loc();

public:
    Property();
    Property(const Property &orig);
    virtual ~Property();
    virtual int get_value() const;
    virtual string get_loc(int loc) const;
    virtual int get_num_tenants() const;
    virtual string get_type() const;
    virtual int get_mort() const;
    virtual string toString() const;
    virtual Tenant get_tenant(int index) const;
    virtual int get_rent() const;
    virtual int pay_rent();
    virtual int get_duration() const;
    virtual int get_tax() const;
    virtual void set_rent();

    virtual void inc_prop_val();
    virtual void dec_duration();
    virtual void hurricane();
    virtual void tornado();
    virtual void earthquake();
    virtual void wildfire();
    virtual void crash();
    virtual void gent(int loc);
    virtual void random_event(int event, int loc);

    static int user_input_price();




};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
