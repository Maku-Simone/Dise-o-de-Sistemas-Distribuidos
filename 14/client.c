#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>

int puerto = 7200;
int port = 6666;

int main(int argc, char *argv[])
{
   if(argc != 2) {
      printf("Usage: ./client serverIp\n");
   }
   char *server_ip = argv[1];
   printf("%s\n", server_ip);
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[3], res = 0;

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(server_ip);
   msg_to_server_addr.sin_port = htons(puerto);

   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;

   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   recvfrom(s, (char *) num, 3*sizeof(int), 0, NULL, NULL);
   for(int i = num[0]; i < num[1]; i++)
    {
      if(num[2] % i == 0)
        {
            res = 1;
        }
       sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    }
   /* se bloquea esperando respuesta */
   //recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   printf("\nServer address: %s\n", inet_ntoa(msg_to_server_addr.sin_addr));
   printf("\n[%d,%d,%d]", num[0], num[1], num[2]);
   char *arr = (char*)malloc(8);
   sprintf(arr, "%d\n", msg_to_server_addr.sin_addr.s_addr);
   int i = 0;
   for (i; i < 8; i ++) {
      printf("%c ", arr[i]);
   }
   close(s);
}
