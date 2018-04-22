#include <iostream>

using namespace std;

int main( )
 {
   double temp, far;		
   cout << "Mete la temperatura en grados centigrados \n";
   cin >> temp;   
   far = (9.0/5.0)*temp + 32.0;		
   cout << temp << " = " << far << "°F\n";
   return 0;  
 }
