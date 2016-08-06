//
// Created by boran on 14.07.2016.
//

#ifndef ASSIGNMENT_3_PHONENUMBER_H
#define ASSIGNMENT_3_PHONENUMBER_H

#include <string>
using namespace std;

class PhoneNumber {
public:
    PhoneNumber();
    int getAreaCode() const;
    void setAreaCode(int areaCode);
    int getNumber() const;
    void setNumber(int number);
    string getPhoneNumber();

    PhoneNumber *next;

private:
    int areaCode;
    int number;
};


#endif //ASSIGNMENT_3_PHONENUMBER_H
