#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include "datagramPaquet.h"
#include "datagramSocket.h"
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string>

int puerto = 7200;
using namespace std;

int main(int argc, char *argv[])
{ 
    if(argc != 2) {
      printf("Usage: ./client serverIp\n");
   }
   char *server_ip = argv[1];
   //printf("%s\n", server_ip);
   int mensaje[2];
   mensaje[0] = 10;
   mensaje[1] = 11;
   PaqueteDatagrama p((char*)mensaje, 4 * sizeof(int), server_ip, puerto);
   SocketDatagrama* s = new SocketDatagrama(0);
   s->envia(p);
   s->recibe(p);
   printf("\nPacket recieved from: %s on port: %d \n", p.obtieneDireccion(), puerto);
   int *num = (int*)p.obtieneDatos();
   printf("%d + %d = %d\n", mensaje[0], mensaje[1], num[0]);
   delete s;
   return 0;
}