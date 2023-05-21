//
// Created by Mohammad Ali Mashta on 18.05.23.
//

#include "Person.h"
#include <string>
using std::string ;

Person::Person(string first, string last, int age)
: firstname(first), lastname(last), age(age)
{

}

std::string Person::getfirst() {
    return firstname;
}

std::string Person::getlast() {
    return lastname;
}