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
   int s, num[2], res;
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   
   /*
   La función inet_addr recibe una cadena que representa una IP en formato IPv4 y la convierte
   en un valor entero para ser usado como una dirección de internet
   */
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
   


   msg_to_server_addr.sin_port = htons(puerto);
   
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(9000);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);

   unsigned char cad[4];

   memcpy(cad,&msg_to_server_addr.sin_addr.s_addr,4);
      printf("Direccion del servidor: ");
      for (int i = 0; i < 4; i++)
      {
         
         if(i<3)
            printf("%d.", cad[i]);
         else
            printf("%d\n", cad[i]);
      }


   printf("Puerto del cliente: %d\n", ntohs(msg_to_server_addr.sin_port));

   printf("2 + 5 = %d\n", res);
   close(s);
}

