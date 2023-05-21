//
// Created by Mohammad Ali Mashta on 18.05.23.
//
#include <iostream>
#include "Mensche.h"
#include "Person.h"
#include <string>
Mensche::Mensche(Person p, std::string w)
: Person(p), wohnort(w)
{
}

bool Mensche::sameName(Person person) {

    if (firstname == person.getfirst()) {
        return true;
    }
    return false;
}

