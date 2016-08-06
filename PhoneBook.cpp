/*
 Created by boran on 13.07.2016.
 Boran Yildirim
 CS201-02
 21401947
*/

#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook() {
    head = NULL;
}

PhoneBook::~PhoneBook() {
    if (head != NULL) {
        Person *cur = head;
        while (cur != NULL) {
            Person *tmp = cur;
            cur = cur -> next;
            delete tmp;
        }
    }
}

void PhoneBook::addPerson(const string firstName, const string lastName) {

    int flag = -1;
    Person *check = head;
    while(check != NULL) {
        if (check -> getFirstName() == firstName && check -> getLastName() == lastName) {
            cout << "Warning! " << firstName << " " << lastName << " is already in your phone book" << endl;
            flag = 0;
            break;
        }
        check = check -> next;
    }
    if(flag == -1) {
        if (head == NULL) {
            head = new Person;
            head -> setFirstName(firstName);
            head -> setLastName(lastName);
            head -> next = NULL;
			head -> prev = NULL;
        }
        else {
            Person *tmp = new Person;
            tmp -> setFirstName(firstName);
            tmp -> setLastName(lastName);

            if (tmp -> getLastName() < head -> getLastName()) {
                head -> prev = tmp;
                tmp -> next = head;
                tmp -> prev = NULL;
                head = tmp;
            }
            else if (tmp -> getLastName() == head -> getLastName()) {
                if (tmp -> getFirstName() <= head -> getFirstName()) {
                    head -> prev = tmp;
                    tmp -> next = head;
                    tmp -> prev = NULL;
                    head = tmp;
                }
                else {
                    tmp -> next = head -> next;
                    tmp -> prev = head;
                    head -> next = tmp;
                }
            }
            else {
                Person *cur = head;
                while (cur != NULL) {
                    if (cur -> getLastName() < tmp -> getLastName() && cur -> next != NULL && cur -> next -> getLastName() > tmp -> getLastName()) {
                        tmp -> next = cur -> next;
                        tmp -> prev = cur;
                        cur -> next -> prev = tmp;
                        cur -> next = tmp;
                        break;
                    }
                    else if (cur -> getLastName() < tmp -> getLastName() && cur -> next == NULL) {
                        cur -> next = tmp;
                        tmp -> prev = cur;
                        tmp -> next = NULL;
                        break;
                    }
                    else if (cur -> getLastName() == tmp -> getLastName()) {
                        if (tmp -> getFirstName() <= cur -> getFirstName()) {
                            tmp -> next = cur;
                            tmp -> prev = cur -> prev;
                            cur -> prev -> next = tmp;
                            cur -> prev = tmp;
                            break;
                        }
                        else {
                            tmp -> next = cur -> next;
                            tmp -> prev = cur;
                            cur -> next -> prev = tmp;
                            cur -> next = tmp;
                            break;
                        }
                    }
                    else
                        cur = cur -> next;
                }
            }
        }
    }
}

void PhoneBook::deletePerson(const string firstName, const string lastName) {

    if(head == NULL)
        cout << "Warning! The phone book is empty." << endl;
    else {
        if (head -> getFirstName() == firstName && head -> getLastName() == lastName) {
            Person *headTmp = head;
            head = head -> next;
            head -> prev = NULL;
            delete headTmp;
        }
        else {
            Person *check = head;
            while (check != NULL) {
                if (check -> getFirstName() == firstName && check -> getLastName() == lastName) {
                    Person *tmp = check;
                    if (tmp -> next == NULL) {
                        check -> prev -> next = NULL;
                        delete tmp;
                        break;
                    }
                    else {
                        check -> prev -> next = check -> next;
                        tmp -> next -> prev = tmp -> prev;
                        delete tmp;
                        break;
                    }
                }
                check = check -> next;
            }
        }
        cout << firstName << " " << lastName << " is deleted." << endl;
    }
}

void PhoneBook::addPhoneNumber(const string firstName, const string lastName, const int areaCode, const int number) {
    Person *cur = head;
    int no = 0;
    while(cur != NULL){
        if(cur -> getFirstName() == firstName && cur -> getLastName() == lastName){
            cur -> addPhoneNumberToPerson(areaCode, number);
            no = -1;
            break;
        }
        cur = cur -> next;
    }
    if (no == 0) {
        cout << "There is no one called " << firstName << " " << lastName << " in the phone book." << endl;
    }
}

void PhoneBook::deletePhoneNumber(const string firstName, const string lastName, const int areaCode, const int number) {
    if (head == NULL) {
        cout << "Warning! " << "The phone book is empty." << endl;
    }
    else {
        int x = -1;
        Person *check = head;
        while (check != NULL) {
            if (check -> getFirstName() == firstName && check -> getLastName() == lastName) {
                x = check -> deletePhoneNumber(areaCode, number);
                break;
            }
            check = check -> next;
        }
        if (x != -1) {
            cout << firstName << " " << lastName << "\'s " << areaCode << "-" << number << " is deleted." << endl;
        }
    }
}

void PhoneBook::showPerson(const string firstName, const string lastName) {
    Person *cur = head;
    bool flag = true;
    while (cur != NULL) {
        if (cur -> getFirstName() == firstName && cur -> getLastName() == lastName) {
            cout << firstName << " " << lastName << endl;
            cur -> showPhoneNumber();
            cout << endl;
            flag = false;
            break;
        }
        cur = cur -> next;
    }
    if (flag) {
        cout << "Warning! There is no one called " << firstName << " " << lastName << endl;
    }
}

void PhoneBook::showPhoneNumber(const int areaCode, const int number) {
    Person *cur = head;
    bool flag = true;
    while (cur != NULL) {
        if (cur -> checkPhoneNumber(areaCode, number)) {
            cout << cur -> getFirstName() << " " << cur -> getLastName() << endl;
            cout << areaCode << "-" << number << endl;
            flag = false;
            break;
        }
        cur = cur -> next;
    }
    if (flag) {
        cout << "Warning! There is no such a phone number." << endl;
    }
}

void PhoneBook::showAll() {
    Person *cur = head;
    while(cur != NULL){
        cout << cur->getFirstName() << " " << cur->getLastName() << endl;
        cur->showPhoneNumber();
        cur = cur-> next;
        cout << endl;
    }
}
