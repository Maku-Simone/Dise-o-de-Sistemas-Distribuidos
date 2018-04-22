#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>

int puerto = 7200;

int main(void)
{
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;

   s = socket(AF_INET, SOCK_DGRAM, 0);

   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;

   //printf("Variable puerto antes de htons: %x\n", puerto);

   server_addr.sin_port = htons(puerto);

   //printf("Variable puerto despues de htons: %x\n", server_addr.sin_port);

   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while(1) {
      recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      printf("\nIP: ");
      unsigned char dir[4];
      memcpy(dir, &msg_to_client_addr.sin_addr.s_addr, 4);
      for(int i = 0; i < 4; i++)
       {
         printf("%d", dir[i]);
         if(i < 3)
           {
             printf(":");
           }
       }

      printf(" - Puerto: %hu", msg_to_client_addr.sin_port);
      res = num[0] + num[1];
   
      //envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente
      sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}
