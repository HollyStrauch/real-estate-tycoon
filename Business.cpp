//
// Created by Holly Strauch on 10/27/2019.
//

#include <iostream>
#include "Business.h"
#include "Tenant.h"

/**
 * Constructor
 */
Business::Business(){
    this->value = (rand() % 3 + 4) * 100000;
    this->mortgage = (rand() % 50 + 1) * 100;
    this->propery_tax = this->value * .015;
    this->dur_mortgage = this->value / this->mortgage;

    this->type = "BUSINESS";
    this->num_tenants = (rand() % 5 + 1);

    this->rentSpace = new int[num_tenants];
    this->tenants = new Tenant[num_tenants];
    this->sizes = new int[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i].set_business();
        this->sizes[i] = rand() % 3;
        this->rentSpace[i] = 0;
    }
    this->location = rand() % 5;
}

/**
 * \brief Assignment Operator Overload
 * @param right Existing business to assign values from
 * @return new Business
 */
Business & Business::operator= (Business &right){
    if (&right == this)
        return (*this);

    this->value = right.value;
    this->mortgage = right.mortgage;
    this->propery_tax = right.propery_tax;
    this->dur_mortgage = right.dur_mortgage;
    this->rent = right.rent;

    this->type = right.type;
    this->num_tenants = right.num_tenants;
    this->location = right.location;

    this->rentSpace = right.rentSpace;
    this->sizes = right.sizes;

    this->tenants = new Tenant[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = right.tenants[i];
    }
    return (*this);
}

/**
 * \brief Copy Constructor
 * @param orig A Business to copy values from
 */
Business::Business(const Business &orig) {
    this->value = orig.value;
    this->mortgage = orig.mortgage;
    this->propery_tax = orig.propery_tax;
    this->dur_mortgage = orig.dur_mortgage;
    this->rent = orig.rent;

    this->type = orig.type;
    this->num_tenants = orig.num_tenants;
    this->location = orig.location;

    this->rentSpace = orig.rentSpace;
    this->sizes = orig.sizes;

    this->tenants = new Tenant[num_tenants];
    for (int i = 0; i < num_tenants; i++){
        this->tenants[i] = orig.tenants[i];
    }
}

/**
 * \brief Iterates through tenants and totals the money from each one.  Tenants may move out or not pay if amount is
 *      too high
 * @return Total rent money collected (integer)
 */
int Business::pay_rent(){
    int total = 0;
    int counter = -1;
    int num_ten = this->num_tenants;

    for(int i = 0; i < num_ten; i++) {
        do{
            counter++;
        }while(!this->get_tenant(counter).get_exists());
        if (this->get_tenant(counter).get_budget() > this->rentSpace[counter]) {
            total += this->rentSpace[counter];
            this->inc_prop_val();
        } else if (this->get_tenant(counter).get_agree() > 1) {
            this->get_tenant(counter).leave();
            cout << "~~ Tenant has moved out ~~" << endl;
            this->num_tenants--;
        } else {
            cout << "XX Someone is refusing to pay rent XX" << endl;
        }
    }
    return total;
}

/**
 * \brief Sets the rent of each room in the Business object
 */
void Business::set_rent() {
    print_rooms();

    int count = -1;
    for(int i = 0; i < this->num_tenants; i++){
        count++;
        while(!this->get_tenant(count).get_exists()){
            count++;
        }

        cout << "Room #" << count + 1 << " current rent: " << this->rentSpace[count] << "\n Enter new rent amount: " << endl;
        int price = user_input_price();

        this->rentSpace[count] = price;
    }

}

/**
 * \brief Prints out the individual rooms that contain tenants along with their size and current rent amount
 */
void Business::print_rooms() {

    cout << "Business Floor Plan: " << endl;
    int count = -1;
    for(int i = 0; i < this->num_tenants; i++){
        count++;
        while(!this->get_tenant(count).get_exists()){
            count++;
        }
        cout << "Room #" << count + 1 << " Size: " << this->get_room_size(count) << " Current Rent: " << this->rentSpace[count] << endl;
    }
}

/**
 *  \brief Returns a string value "small", "medium" or "large" based on the sizes array index
 * @param index Specifies which room in the sizes array
 * @return the corresponding string
 */
string Business::get_room_size(int index){
    if(this->sizes[index] == 0){
        return "SMALL";
    }else if(this->sizes[index] == 1){
        return "MEDIUM";
    }else{
        return "LARGE";
    }
}

/**
 * \brief Overrides Property get_rent, Business has no individual rent value
 * @return 0
 */
int Business::get_rent() const {
    return 0;
}
