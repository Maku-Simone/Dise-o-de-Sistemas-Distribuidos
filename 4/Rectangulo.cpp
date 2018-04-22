#include "Rectangulo.h"
#include "Coordenada.h"
#include <iostream>
using namespace std;
double Rectangulo::area(double alto,  double ancho)
  {
    return alto * ancho;
  }
Rectangulo::Rectangulo(Coordenada x, Coordenada y): superiorIzq(x.obtenerX(), x.obtenerY()) ,  inferiorDer(y.obtenerX(), y.obtenerY())
{} //Aqui le meti mano :3

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
