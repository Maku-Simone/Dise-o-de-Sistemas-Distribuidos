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
    Fecha f;
    if(!f.valida(dd,mm,aaaa))
      {
        return;
      }
    else
      {
        anio = aaaa;
        mes = mm;
        dia = dd;
      }
    return;
  }
void Fecha::muestraFecha()
  {
    cout << "\nLa fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl << "\n";
    return;
  }
int Fecha::convierte()
    {
      //cout << "\nFecha: " << (anio*10000+mes*100+dia) << "\n";
      return (anio*10000+mes*100+dia);
    }
bool Fecha::leapyr()
  {
    if((anio%4 == 0 || anio%400 == 0) && (anio % 100 != 0))
      {
        return true;
      }
      return false;
  }
bool Fecha::valida(int mm, int dd, int aaaa)
  {
    if(mm < 1 || mm > 12)
      {
        cout << "\nError, mes invalido >:c\n";
        return false;
      }
    if(dd < 1 || dd > 31)
      {
        cout << "\nEste dia no existe :c \nAsumiendo que todos los meses tienen 31 dias...\n";
        return  false;
      }
    if(aaaa < 0)
      {
        cout << "\nNO se puede volver en el tiempo\n";
        return false;
      }
    return true;
  }
int Fecha::getDia()
  {
    return dia;
  }
int Fecha::getMes()
 {
   return mes;
 }
int Fecha::getAnio()
  {
    return anio;
  }
int Fecha::masVieja(Fecha a, Fecha b)
    {
      if(a.convierte() > b.convierte())
        {
          return 1;
        }
      if(a.convierte() == b.convierte())
          {
            return  0;
          }
      if(a.convierte() < b.convierte())
        {
          return -1;
        }
    }

    int Fecha::masVieja2(Fecha *a, Fecha* b)
        {
          if(a->convierte() > b->convierte())
            {
              return 1;
            }
          if(a->convierte() == b->convierte())
              {
                return  0;
              }
          if(a->convierte() < b->convierte())
            {
              return -1;
            }
        }
