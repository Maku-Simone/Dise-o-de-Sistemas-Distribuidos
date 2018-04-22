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
         cout << "\nNo es bisiesto :c\n";
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
          cout << "\nNo es bisiesto :c\n";
        }


      Fecha c;
      c.inicializaFecha(100,02,2016);
      c.muestraFecha();
      c.convierte();
      if(c.leapyr())
        {
          cout << "\nEs bisiesto :3";
        }
      else
       {
         cout << "\nNo es bisiesto :c\n";
       }

     Fecha d;
     d.inicializaFecha(10,17,2016);
     d.muestraFecha();
     d.convierte();
     if(d.leapyr())
       {
         cout << "\nEs bisiesto :3";
       }
     else
      {
        cout << "\nNo es bisiesto :c\n";
      }



  Fecha ee;
  ee.inicializaFecha(10,02,-1525);
  ee.muestraFecha();
  ee.convierte();
  if(ee.leapyr())
    {
      cout << "\nEs bisiesto :3";
    }
  else
   {
     cout << "\nNo es bisiesto :c\n";
   }
 return 1;
}
