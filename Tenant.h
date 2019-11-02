//
// Created by Holly Strauch on 10/25/2019.
//

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
    Tenant &operator= (Tenant &right);
    int get_agree() const;
    int get_budget() const;
    bool get_type() const;
    bool get_exists() const;
    void set_not_exist();
    void set_business();
};
#endif //REAL_ESTATE_TYCOON_TENANT_H
