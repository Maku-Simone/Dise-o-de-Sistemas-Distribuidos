#include "Fecha.h"
#include <iostream>
using namespace std;
Fecha::Fecha(int dd, int mm, int aaaa)
    {
      mes = mm;
      dia = dd;
      anio = aaaa;
    }
void Fecha::inicializaFecha(int dd, int mm, int aaaa)
  {
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
  }
void Fecha::muestraFecha()
  {
    cout << "\nLa fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl << "\n";
    return;
  }
void Fecha::convierte()
    {
      cout << "\nFecha: " << (anio*10000+mes*100+dia) << "\n";
    }
bool Fecha::leapyr()
  {
    if((anio%4 == 0 || anio%400 == 0) && (anio % 100 != 0))
      {
        return true;
      }
      return false;
  }
