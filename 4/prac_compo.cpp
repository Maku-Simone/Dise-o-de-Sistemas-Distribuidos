#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;
 int main( )
  {
    Rectangulo rectangulo1(Coordenada(4,0.98),Coordenada(11.3,0.19)); //ejercicio 2
    double ancho, alto;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano polar:\n";
    rectangulo1.imprimeEsq();
    alto = rectangulo1.obtieneSupIzq().obtenerY() -
    rectangulo1.obtieneInfDer().obtenerY();
    ancho = rectangulo1.obtieneInfDer().obtenerX() -
    rectangulo1.obtieneSupIzq().obtenerX();
    cout << "El área del rectángulo es = " << rectangulo1.area(alto, ancho) << endl; //ejercicio 3
    return 0;
  }
