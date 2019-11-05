/**
 * Program: Real Estate Tycoon
 * Author: Holly Strauch
 * 11/5/19
 * File: Tenant.h
 *
 * Runs a Real Estate Tycoon game where the player can buy different types of properties, adjust and collect rent on
 * them and sell properties.  Player must pay mortgages and taxes, and random events can occur that will effect the
 * current property values.  Tenants on properties may leave or refuse to pay rent if it is too high.  Player will win
 * if their bank account hits $1,000,000 and lose if it hits $0;
 *
 * Tenant class is used in Properties and have differing ranges of budgets dependant on type.
 */


#ifndef REAL_ESTATE_TYCOON_TENANT_H
#define REAL_ESTATE_TYCOON_TENANT_H

class Tenant{
private:
    bool type;
    bool exists;
    int budget;
    int agree;


public:
    Tenant(bool type);
    Tenant();
    Tenant(const Tenant &orig);
    Tenant &operator= (Tenant &right);
    int get_agree() const;
    int get_budget() const;
    bool get_type() const;
    bool get_exists() const;
    void leave();
    void set_business();
};
#endif //REAL_ESTATE_TYCOON_TENANT_H
