#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <iostream>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *data, unsigned int longitudDatos, char * dir_ip, int pto)
  {
    datos = new char[longitudDatos];
    memcpy(datos, data, longitudDatos);//aqui tambien
    memcpy(ip, dir_ip, 16); //le quite el & al dir
    longitud = longitudDatos;
    puerto = pto;
  }
PaqueteDatagrama::PaqueteDatagrama(unsigned int longitudDatos)
  {
    datos = new char[longitudDatos];
  }
PaqueteDatagrama::~PaqueteDatagrama()
    {
      delete(datos);
    }
char * PaqueteDatagrama::obtieneDireccion()
  {
    return ip;
  }
unsigned int PaqueteDatagrama::obtieneLongitud()
  {
    return longitud;
  }
int PaqueteDatagrama::obtienePuerto()
  {
    return puerto;
  }
char * PaqueteDatagrama::obtieneDatos()
  {
    return datos;
  }
void PaqueteDatagrama::inicializaPuerto(int pto)
  {
    puerto = pto;
  }

void PaqueteDatagrama::inicializaIp(char * dir_ip)
  {
    memcpy(ip, &dir_ip, 16);
  }

void PaqueteDatagrama::inicializaDatos(char * data)
  {
    memcpy(datos, &data, longitud);
  }

int main()
{
  char txt[] = "holi";
  char ip[] = "127.0.0.1";
  PaqueteDatagrama p(txt, sizeof(txt), ip, 9000);
  cout << "DATA: " << p.obtieneDatos() << " Long: " << p.obtieneLongitud() << " IP: "  << p.obtieneDireccion()
       << " Pto: " << p.obtienePuerto();
}
