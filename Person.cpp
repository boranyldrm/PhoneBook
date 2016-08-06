/*
 Created by boran on 13.07.2016.
 Boran Yildirim
 CS201-02
 21401947
*/

#include "Person.h"
#include <iostream>
#include <string>

Person::Person() {
    firstName = "";
    lastName = "";
    phoneNumberTail = NULL;
    prev = NULL;
    next = NULL;
}

Person::~Person() {
    if (phoneNumberTail != NULL) {
        PhoneNumber *cur = phoneNumberTail -> next;
        do {
            PhoneNumber *tmp = cur;
            cur = cur -> next;
            delete tmp;
        } while(cur != phoneNumberTail);
    }
}

const string &Person::getFirstName() const {
    return firstName;
}

void Person::setFirstName(const string &firstName) {
    Person::firstName = firstName;
}

const string &Person::getLastName() const {
    return lastName;
}

void Person::setLastName(const string &lastName) {
    Person::lastName = lastName;
}

void Person::addPhoneNumberToPerson(const int areaCode, const int number) {
    if (phoneNumberTail == NULL) {
        phoneNumberTail = new PhoneNumber;
        phoneNumberTail -> setAreaCode(areaCode);
        phoneNumberTail -> setNumber(number);
        phoneNumberTail -> next = phoneNumberTail;
    }
    else {
        bool flag = true;
        PhoneNumber *cur = phoneNumberTail;
        do {
            if (cur -> getAreaCode() == areaCode && cur -> getNumber() == number) {
                flag = false;
                break;
            }
            cur = cur -> next;
        } while(cur -> next != phoneNumberTail);
        if (flag) {
            PhoneNumber *tmp = new PhoneNumber;
            tmp -> setAreaCode(areaCode);
            tmp -> setNumber(number);
            tmp -> next = phoneNumberTail -> next;;
            phoneNumberTail -> next = tmp;
        }
        else
            cout << areaCode << "-" << number << " is already exist, cannot be added." << endl;

    }
}

int Person::deletePhoneNumber(const int areaCode, const int number) {
    if (phoneNumberTail == NULL) {
        cout << "Warning! There is no any phone number." << endl;
        return -1;
    }
    else if (phoneNumberTail -> next == phoneNumberTail && phoneNumberTail -> getAreaCode() == areaCode && phoneNumberTail -> getNumber() == number) {
        PhoneNumber *tmp = phoneNumberTail;
        phoneNumberTail = NULL;
        delete tmp;
        return 1;
    }

    else if (phoneNumberTail -> getAreaCode() == areaCode && phoneNumberTail -> getNumber() == number) {
        PhoneNumber *tmp = phoneNumberTail;
        PhoneNumber *cur;
        for(cur = phoneNumberTail; cur -> next != phoneNumberTail; cur = cur -> next);
        phoneNumberTail = phoneNumberTail -> next;
        cur -> next = phoneNumberTail;
        delete tmp;
        return 1;
    }
    PhoneNumber *cur = phoneNumberTail;
    do {
        if (cur -> next -> getAreaCode() == areaCode && cur -> next -> getNumber() == number) {
            PhoneNumber *tmp = cur -> next;
            cur -> next = tmp -> next;
            delete tmp;
            return 1;
        }
        cur = cur -> next;
    } while(cur != phoneNumberTail);
    if (cur == phoneNumberTail) {
        cout << areaCode << "-" << number << " is not found." << endl;
        return -1;
    }
    return -1;
}


void Person::showPhoneNumber() {

    if (phoneNumberTail != NULL){
        PhoneNumber *cur = phoneNumberTail;
        do {
            cout << cur -> getAreaCode() << "-" << cur -> getNumber() << endl;
            cur = cur -> next;
        } while(cur != phoneNumberTail);
    }
}

bool Person::checkPhoneNumber(const int areaCode, const int number){
    if (phoneNumberTail == NULL) {
        return false;
    }
    else {
        PhoneNumber *cur = phoneNumberTail;
        do {
            if (cur -> getAreaCode() == areaCode && cur -> getNumber() == number) {
                return true;
            }
            cur = cur -> next;
        } while(cur != phoneNumberTail);
    }
    return false;
}
