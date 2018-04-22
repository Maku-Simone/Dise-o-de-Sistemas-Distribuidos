#include <unistd.h>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
int main()
  {
    string cadenota = "";
    int apariciones = 0, palabras; //10M
    char letra;
    cin >> palabras;
    srand(time(NULL));
    for(int i = 0; i < palabras; i++)
      {
        for(int j = 0; j < 3; j++)
          {
            letra = 'A' + (rand() % 26);
            cadenota.append(string(1,letra));
          }
          cadenota.append(" ");
      }
    /*for(int i = 0; i < cadenota.size(); i++)
        {
          cout << cadenota[i];
        }*/
    int pos = 0, posAnt = 0;
      for(int i = 0; i < cadenota.size(); i++)
        {
          posAnt = pos;
          pos = cadenota.find("IPN", pos);
          if(pos > posAnt)
            {
              apariciones ++;
            }
        }
        cout << /*"\n" <<  pos <<*/ "\nApariciones " << apariciones;
  }
