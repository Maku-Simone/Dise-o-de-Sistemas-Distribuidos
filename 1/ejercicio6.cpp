#include <iostream>

using namespace std;

int main( )
 {
   int n;
   n = 2;		
   cout << "n = 2\n" << "n + (++n)\n";
   n + (++n);
   cout << "n = " << n << "\n";
   return 0;  
 }
