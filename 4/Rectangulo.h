#include <iostream>
#include "Coordenada.h"
using namespace std;
#ifndef RECTANGULO_H_
#define RECTANGULO_H_
 class Rectangulo
  {
    private:
      Coordenada superiorIzq;
      Coordenada inferiorDer;
    public:
      Rectangulo();
      Rectangulo(Coordenada, Coordenada);
      Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
      void imprimeEsq();
      Coordenada obtieneSupIzq();
      double area(double, double); //area
      Coordenada obtieneInfDer();
  };
#endif
