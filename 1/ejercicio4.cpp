#include <iostream>

using namespace std;

int main( )
 {
   double temp, far;		
   cout << "Mete la temperatura en grados centigrados \n";
   cin >> temp;   
   far = (static_cast<double>(9)/static_cast<double>(5))*temp + 32.0;		
   cout << temp << " = " << far << "°F\n";
   return 0;  
 }
