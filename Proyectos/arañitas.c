#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>

int puerto = 7200;

int main(int argc, char *argv[])
{

   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, res = 0, cuadro = 0, x = 0, y = 0;
   double velocidad = 0.0;

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;

   /*
   La función inet_addr recibe una cadena que representa una IP en formato IPv4 y la convierte
   en un valor entero para ser usado como una dirección de internet
   */
   msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_port = htons(puerto);

   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   char msg[] = "Muffet";

   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(9000);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   printf("\n¿Cual será mi velocidad (v)? :3 {v | v [0, 10]}\n");
   scanf("%lf", &velocidad);
   if(velocidad > 10.0)
    {
      printf("\nLa araña ha ido tan rápido que no ha podido mantener su forma física \n");
      printf("\n*** La araña ahora está en el plano astral @3@ ***\n");
      exit(0);
    }
   sendto(s, (char *)&msg, sizeof(msg) * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   /* se bloquea esperando respuesta */
   recvfrom(s, (int *)&res, sizeof(int), 0, NULL, NULL);
   recvfrom(s, (int *)&cuadro, sizeof(int), 0, NULL, NULL);
   if(res > 3)
    {
      printf("\nYa hay cuatro arañas ;3;\n* Se mata * \n");
      close(s);
      exit(0);
    }
  switch (res) {
    case 0:
      ;
    break;
    case 1:
      y = cuadro;
    break;
    case 2:
      x = cuadro;
      y = cuadro;
    break;
    case 3:
      x = cuadro;
    break;
    default:
        ;
  }
   printf("\nSoy la araña %d, cuadro mide %d, mi posición es (%d, %d) y viajo a %lfpx/s\n", res, cuadro, x, y, velocidad);
   char pos[] = "posiciones";
   sendto(s, (char *)&pos, sizeof(pos) * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   close(s);
}
