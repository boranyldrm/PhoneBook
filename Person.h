/*
 Created by boran on 13.07.2016.
 Boran Yildirim
 CS201-02
 21401947
*/

#ifndef ASSIGNMENT_3_PERSON_H
#define ASSIGNMENT_3_PERSON_H

#include <string>
#include "PhoneNumber.h"

using namespace std;

class Person {

public:
    Person();
    ~Person();
    const string &getFirstName() const;
    void setFirstName(const string &firstName);
    const string &getLastName() const;
    void setLastName(const string &lastName);
    void addPhoneNumberToPerson(const int areaCode, const int number);
    void showPhoneNumber();
    PhoneNumber *deletephoneNumberTail();
    int deletePhoneNumber(const int areaCode, const int number);
    bool checkPhoneNumber(const int areaCode, const int number);

    Person *next;
    Person *prev;

private:
    string firstName;
    string lastName;
    PhoneNumber *phoneNumberTail;
};


#endif //ASSIGNMENT_3_PERSON_H
