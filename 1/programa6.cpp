#include <iostream>
using namespace std;

int main( ){
    double precio = 78.7;
    cout << precio<<"\n";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << precio;
    return 0;
}
