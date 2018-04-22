#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>


int puerto = 7200;

int main(void)
{
   int num[3], numeroPrimo; //num[inicio, final, numeroPrimo]
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;
   typedef int bool;
   #define true 1
   #define false 0
   bool prim = true;

   printf("\nMete el numero a calcular\n");
   scanf("%d", &numeroPrimo);
   printf("\nVeamos si %d es un numero primo...", numeroPrimo);

   s = socket(AF_INET, SOCK_DGRAM, 0);

   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   num[0] = numeroPrimo/2;
   num[1] = numeroPrimo;
   num[2] = numeroPrimo;
   sendto(s, (char *)num, 2 * sizeof(int), 0,  (struct sockaddr *)&msg_to_client_addr, clilen);
   for(int i = 0; i < numeroPrimo/2; i++)
    {
      if(numeroPrimo%i == 0)//divisible
        {
          prim = false;
        }
    }
   while(1) {
      recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
      if(res == 1 || prim == true)//primo
        {
          printf("\n%d es un numero primo c:", numeroPrimo);
          break;
        }
      //recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);

      printf("Client address: %s\n", inet_ntoa(msg_to_client_addr.sin_addr));
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
   }
   return 1;
}
