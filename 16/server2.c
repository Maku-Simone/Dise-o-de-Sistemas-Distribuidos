#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include "gfx.h"
#include <stdlib.h>

int puerto = 6789;
char buffer[2048];

int main(void)
{
   int num[3];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;

   s = socket(AF_INET, SOCK_DGRAM, 0);

   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
  gfx_open(800, 600, "Sensual Fourier ");
  int R = 250, G = 0, B = 0;
  gfx_clear();
  gfx_color(180,0,250);
  gfx_line(0,300,800,300); //eje x
  gfx_line(400,0,400,600);// eje y
  gfx_color(R,G,B);

  int x = 0;
  char* dir1 = "";
   while(1)
   {
      memset(buffer, 0, sizeof(buffer));
      recvfrom(s, buffer, sizeof(buffer), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      dir1 = inet_ntoa(msg_to_client_addr.sin_addr);
      printf("%s\n", dir1);
      int val = atoi(buffer);
      printf("\n (%d, %d) ", x, (val/5));
      int val2 = val;
      if(val < 0)
        {
          val2 = 300+((-1) * val/5);
        }
      else
        {
          val2 = 300 - (val/5);
        }
      gfx_point(x,val2);
      gfx_flush();
  //    usleep(41666); //24 por segundo
      x++;
      if(x == 800)
        {
          x = 0;
        B += 60;
        G += 20;
          if(R > 240)
            {
              R -= 60;
            }
          gfx_color(R,G,B);
        }
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      //sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}
