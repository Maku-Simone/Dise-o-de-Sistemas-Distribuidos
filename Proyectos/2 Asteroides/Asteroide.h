#include <unistd.h>
using namespace std;
#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_
class Asteroide
  {
  private:
    double x;
    double y;
    double rMin;
    double rMax;
    double velocidad;
    double lados;
 public:
   Asteroide(int, int, int, int, int, int);
   void dibujar(int, int, int, int, int);  //x, y, min, max, l
 };
#endif
