#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <math.h>
#include <algorithm>
using namespace std;
class Coordenada
  {
  private:
    double x;
    double y;
    double magnitud;
 public:
   Coordenada(double = 0, double = 0);
   double obtenerX();
   double obtenerY();
   double getMagnitud();
 };


  class PoligonoIrregular
    {
      private:
        vector<Coordenada> vectCoords;
        std::vector<Coordenada>::iterator i;
      public:
        PoligonoIrregular();
        void addVertice(Coordenada);
        void imprimeVertice();
        vector<Coordenada> ordenaA(vector<Coordenada>);
    };

 int main( )
  {
   /*  Rectangulo rectangulo1(2,3,5,1);
    double ancho, alto;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";
    rectangulo1.imprimeEsq();
    alto = rectangulo1.obtieneSupIzq().obtenerY() -
    rectangulo1.obtieneInfDer().obtenerY();
    ancho = rectangulo1.obtieneInfDer().obtenerX() -
    rectangulo1.obtieneSupIzq().obtenerX();
    cout << "El área del rectángulo es = " << ancho*alto << endl;*/
    cout << "\n1.-  Poligono Irregular";
    PoligonoIrregular p;
    srand(time(NULL));
    for(int i = 0; i < rand() % 200 + 1; i++)
      {
          double x = (rand() % 200 - 100) + (rand() % 1988 - 999)/1000.000;
          double y = (rand() % 200 - 100) + (rand() % 1988 - 999)/1000.000;
          cout << "\n x " << x << " y " << y << "\n";
          Coordenada c(x, y);
          p.addVertice(c);
      }

        p.imprimeVertice();
        cout << "\n";
    return 0;
  }

  PoligonoIrregular::PoligonoIrregular()
    {}
  void PoligonoIrregular::addVertice(Coordenada coord)
    {
      vectCoords.push_back(coord);
    }
  void PoligonoIrregular::imprimeVertice()
    {
      int m = 0;
      PoligonoIrregular p;
      cout << "\nCon iterador normal: \n";
      for(i = vectCoords.begin(); i != vectCoords.end(); i++)
        {
          cout << "\n C[" << m << "] = (" << (*i).obtenerX() << "," << (*i).obtenerY() << ")  Magnitud = " << (*i).getMagnitud();
          //cout << " Iterando " << m << " cosa " << (*i).obtenerX();
          m++;
        }
        cout << "\n Ordenado sensualmente :3 \n";
        p.ordenaA(vectCoords);
    }
  bool ord(Coordenada i, Coordenada j)
      {
        if(i.getMagnitud() > j.getMagnitud())
          {
            return true;
          }
        return false;
      }
    vector<Coordenada> PoligonoIrregular::ordenaA(vector<Coordenada> v)
      {
        //std::vector<Coordenada> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
          std::sort (v.begin(), v.end(), ord);
          for(i = v.begin(); i != v.end(); i++)
            {
              cout << "\n C["  << "] = (" << (*i).obtenerX() << "," << (*i).obtenerY() << ")  Magnitud = " << (*i).getMagnitud();
              //cout << " Iterando " << m << " cosa " << (*i).obtenerX();

            }
            return v;

      }
 Coordenada::Coordenada(double xx, double yy) : x(xx), y(yy)
    {}

 double Coordenada::obtenerX()
 {
   return x;
 }

 double Coordenada::getMagnitud()
 {
   magnitud = sqrt((pow(x, 2))+(pow(y, 2)));
   return magnitud;
 }


 double Coordenada::obtenerY()
 {
   return y;
 }
