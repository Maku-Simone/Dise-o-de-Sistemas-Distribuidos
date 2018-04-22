#include "Fecha.h"
#include <iostream>
using namespace std;

int main()
  {
      Fecha a(20,02,2018);
      a.muestraFecha();
      a.convierte();
      if(a.leapyr())
        {
          cout << "\nEs bisiesto :3";
        }
      else
       {
         cout << "\nNo es bisiesto :c";
       }


       Fecha b(10,02,2016);
       b.muestraFecha();
       b.convierte();
       if(b.leapyr())
         {
           cout << "\nEs bisiesto :3";
         }
       else
        {
          cout << "\nNo es bisiesto :c";
        }
      return 1;
  }
