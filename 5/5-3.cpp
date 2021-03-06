#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;
class Coordenada
  {
  private:
    double x;
    double y;
 public:
   Coordenada(double = 0, double = 0);
   double obtenerX();
   double obtenerY();
 };

  class PoligonoIrregular
    {
      private:
        vector<Coordenada> vectCoords;
        static int verticesTotales;
      public:
        PoligonoIrregular();
        static int getVerticesTotales();
        void addVertice(Coordenada);
        void imprimeVertice();
    };

 int main( )
  {
    vector<PoligonoIrregular> vectPoli;
    for(int i = 0; i < 50000; i++)  //500 elementos de 100 vertices cada uno
      {
        for(int j = 0; j < 50; j++)
          {
            Coordenada c(i+i+i, i*i);
            PoligonoIrregular p;
            p.addVertice(c);
            vectPoli.push_back(p);
          }
      }
      cout << "\n Se usaron en total: " << vectPoli[0].getVerticesTotales() << "\n";
    return 0;
  }


  int PoligonoIrregular:: verticesTotales = 0;
  PoligonoIrregular::PoligonoIrregular()
    {}
  void PoligonoIrregular::addVertice(Coordenada coord)
    {
      vectCoords.push_back(coord);
      verticesTotales++;
    }
  void PoligonoIrregular::imprimeVertice()
    {
      for(int i = 0; i < vectCoords.size(); i++)
        {
          cout << "\n C[" << i << "] = (" << vectCoords[i].obtenerX() << "," << vectCoords[i].obtenerY() << ")" ;
        }
    }
  int PoligonoIrregular::getVerticesTotales()
    {
      return verticesTotales;
    }
 Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
    {}

 double Coordenada::obtenerX()
 {
   return x;
 }

 double Coordenada::obtenerY()
 {
   return y;
 }
