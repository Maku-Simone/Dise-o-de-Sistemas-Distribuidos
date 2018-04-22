#include "datagramPaquet.h"
#include "datagramSocket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdlib.h>

SocketDatagrama::SocketDatagrama(int port) {
	s = socket(AF_INET, SOCK_DGRAM, 0);
	bzero((char *)&direccionLocal, sizeof(direccionLocal));
	direccionLocal.sin_family = AF_INET;
	direccionLocal.sin_addr.s_addr = INADDR_ANY;
	direccionLocal.sin_port = htons(port);
	bind(s, (struct sockaddr *)&direccionLocal,sizeof(direccionLocal));
}

SocketDatagrama::~SocketDatagrama() {
	close(s);
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
	char data[1024];
	recvfrom(s, (char *)data, 1024, 0, NULL, NULL);
	p.inicializaDatos(data);
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
	bzero((char *)&direccionForanea, sizeof(direccionForanea));
	direccionForanea.sin_family = AF_INET;
	direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
	direccionForanea.sin_port = htons(p.obtienePuerto());
	sendto(s, p.obtieneDatos(), 1024, 0, (struct sockaddr *) &direccionForanea, sizeof(direccionForanea));

}