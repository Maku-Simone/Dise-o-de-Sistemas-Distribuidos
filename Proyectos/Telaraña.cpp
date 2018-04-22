#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include "gfx.h"
#include <vector>
int puerto = 7200;

void pintaCuadro(int lados)
  {
    gfx_clear();
    gfx_open(900, 900, "Arañas :3");
    gfx_color(0,200,100);
    gfx_line(0, 0, 0, lados);
    gfx_line(0, lados, lados, lados);
    gfx_line(lados, lados,  lados, 0);
    gfx_line(lados, 0, 0, 0);
  }

int main(void)
{
  //******************** Mis variables :3
   char msg[] = "";
   int s, res, clilen, sizeCuadro = 0, i = 0;
   vector <pair <int, int> > posicioneAranas[4];
  //*************************************
   //---------------------------------------------------------------
   // COSAS DEL SERVER
   struct sockaddr_in server_addr, msg_to_client_addr;

   s = socket(AF_INET, SOCK_DGRAM, 0);

   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);

   //-------------------------------------------------------------------
   // TERMINAN COSAS DEL SERVER
   printf("\nCuanto medira el cuadro? :3\n");
   scanf("%d", &sizeCuadro);
   while(1) {
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
          recvfrom(s, (char *)&msg, 10*sizeof(char), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
          if(strcmp(msg, "Muffet") == 0)
            {
              sendto(s, (int *)&i, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
              sendto(s, (int *)&sizeCuadro, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
              i++;
            }
            /*Este if es por cada intento de conexion de una arana, si no se trata de una conexion
              entonces se proceden con calculos*/
          else
            {
              pintaCuadro(sizeCuadro);
            }

   }
}
