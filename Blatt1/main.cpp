#include <iostream>
using namespace std;
#include "Person.h"
#include "Mensche.h"


int main(){
    Person alip("ali","Ma",12);
    Mensche ali(Person("ali","As",12),"Gf");


    if (ali.sameName(alip)) {
        cout << "samename" << endl;
    }

    return 0;
}
