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
    double value;
    double mortgage;
    double dur_mortgage;
    double propery_tax;
    int num_tenants;
    Tenant** tenants;
    string location;
    string type;

    //ftn to generate location

public:
   // Property();
    double get_value() const;
    string get_loc() const;
    int get_num_tenants() const;
    string get_type() const;
    double get_mort() const;
  //  Tenant* get_tenants();
 //   Property gen_random(int event);
  //  ~Property();
    void hurricane();
    void tornado();
    void earthquake();
    void wildfire();
    void crash();
    void gent(string loc);
    void random_event(int event);



};


#endif //REAL_ESTATE_TYCOON_PROPERTY_H
