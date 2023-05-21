//
// Created by Mohammad Ali Mashta on 18.05.23.
//

#ifndef BLATT1_MENSCHE_H
#define BLATT1_MENSCHE_H
#include <string>
#include "Person.h"
using std::string;

class Mensche: public Person{
public:
    Mensche(Person p, string w);
    string wohnort;
    bool sameName(Person person);

};


#endif //BLATT1_MENSCHE_H
