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

 class Rectangulo
  {
    private:
      Coordenada superiorIzq;
      Coordenada inferiorDer;
    public:
      Rectangulo();
      Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
      void imprimeEsq();
      Coordenada obtieneSupIzq();
      Coordenada obtieneInfDer();
  };

  class PoligonoIrregular
    {
      private:
        vector<Coordenada> vectCoords;
      public:
        PoligonoIrregular();
        void addVertice(Coordenada);
        void imprimeVertice();
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
    for(int i = 0; i < rand() % 20; i++)
      {
          Coordenada c((i+1)*rand() % 10, i + rand() % 10);
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
      for(int i = 0; i < vectCoords.size(); i++)
        {
          cout << "\n C[" << i << "] = (" << vectCoords[i].obtenerX() << "," << vectCoords[i].obtenerY() << ")" ;
        }
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

 Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
 { }

 Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double
   yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
 { }

 void Rectangulo::imprimeEsq()
 {
   cout << "Para la esquina superior izquierda.\n";
   cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
   cout << "Para la esquina inferior derecha.\n";
   cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
 }

 Coordenada Rectangulo::obtieneSupIzq()
 {
   return superiorIzq;
 }

 Coordenada Rectangulo::obtieneInfDer()
 {
   return inferiorDer;
 }
