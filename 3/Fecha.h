#include <cstdlib>
#ifndef FECHA_H_
#define FECHA_H_
class Fecha
   {
     private:
     int dia;
     int mes;
     int anio;
     public:
     Fecha(int = 3, int = 4, int = 2014);
     void inicializaFecha(int, int, int);
     int convierte();
     void muestraFecha();
     bool leapyr();
     bool valida(int, int, int);
     int getDia();
     int getMes();
     int getAnio();
     int masVieja(Fecha, Fecha);
     int masVieja2(Fecha*, Fecha*);
   };
#endif
