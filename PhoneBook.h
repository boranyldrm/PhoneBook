/*
 Created by boran on 13.07.2016.
 Boran Yildirim
 CS201-02
 21401947
*/

#ifndef ASSIGNMENT_3_PHONEBOOK_H
#define ASSIGNMENT_3_PHONEBOOK_H

#include "Person.h"
#include <string>

using namespace std;


class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();
    void addPerson( const string firstName, const string lastName );
    void deletePerson( const string firstName, const string lastName );
    void addPhoneNumber( const string firstName, const string lastName,
                         const int areaCode, const int number );
    void deletePhoneNumber( const string firstName, const string lastName,
                            const int areaCode, const int number );
    void showPerson( const string firstName, const string lastName );
    void showPhoneNumber( const int areaCode, const int number );
    void showAll();

private:
    Person *head;
};


#endif //ASSIGNMENT_3_PHONEBOOK_H
