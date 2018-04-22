#include "datagramPaquet.h"
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PaqueteDatagrama::PaqueteDatagrama(char *data, unsigned int len, char *address, int port) {
	datos = new char[len];
	memcpy(datos, data, len);
	longitud = len;
	memcpy(ip, address, strlen(address));
	puerto = port;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int len) {
	datos = new char[len];
	longitud = len;
	ip[0] = '\0';
	puerto = 0;
}

PaqueteDatagrama::~PaqueteDatagrama() {

}

char *PaqueteDatagrama::obtieneDireccion() {
	return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud() {
	return longitud;
}

int PaqueteDatagrama::obtienePuerto() {
	return puerto;
}

char *PaqueteDatagrama::obtieneDatos() {
	return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port) {
	puerto = port;
}

void PaqueteDatagrama::inicializaIp(char *address) {
	memcpy(ip, address, strlen(address));
}

void PaqueteDatagrama::inicializaDatos(char *data) {
	memcpy(datos, data, 1024);
}
