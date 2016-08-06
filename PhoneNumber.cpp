//
// Created by boran on 14.07.2016.
//

#include "PhoneNumber.h"
#include <iostream>

PhoneNumber::PhoneNumber() {
    setAreaCode(0);
    setNumber(0);
    next = NULL;
}

int PhoneNumber::getAreaCode() const {
    return areaCode;
}

void PhoneNumber::setAreaCode(int areaCode) {
    PhoneNumber::areaCode = areaCode;
}

int PhoneNumber::getNumber() const {
    return number;
}

void PhoneNumber::setNumber(int number) {
    PhoneNumber::number = number;
}

string PhoneNumber::getPhoneNumber() {
    return to_string(areaCode) + "" + to_string(number);
}
