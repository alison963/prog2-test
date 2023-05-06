#include <iostream>

using namespace std;

int numOnMac(int x) {
    cout << "ich versuche hier diese Funktion zu ändern" <<endl;
    return x +1;
}


int main(){
    cout << "Hello , World!" << endl;
    cout << "this is a test from (i add this from mac) windows" <<endl;

    cout << numOnMac(5) << endl;

    return 0;
}
