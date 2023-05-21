//
// Created by Mohammad Ali Mashta on 18.05.23.
//

#ifndef BLATT1_PERSON_H
#define BLATT1_PERSON_H
#include <string>

class Person {
protected:
    std::string firstname;
    std::string lastname;
public:
    Person(std::string firstname, std::string lastname, int age);
    std::string getfirst();
    std::string getlast();
    int age;
};


#endif //BLATT1_PERSON_H
