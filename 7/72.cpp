#include <string>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#include <iostream>


int main()
  {
    int opc;
    cout << "1.- con [i]\n2.- Con .at()\n";
    cin >> opc;

    if(opc == 1)
      {
        string cadena("ESCOM");
        cout << cadena[6] << endl;
      }
    else
      {
        if(opc == 2)
          {
            string cadena("ESCOM");
            cout << cadena.at(6) << endl;
          }
        else
          {
            cout <<"\n Muerete";
          }
      }
      return 1;
  }
