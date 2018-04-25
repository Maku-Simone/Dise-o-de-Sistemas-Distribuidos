#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include "gfx.h"

int puerto = 7200;

void pintaCuadro(int);
void pintaArana(int, int);
void pintaRuta(int);


void pintaArana(int x, int y)
  {
    printf("\n(%d, %d)",x,y);
    for(int t = 0; t < 2; t++)
      {
        int c1 = 10, c2 = 20;
        for(int i = 0; i < 2; i++)
          {
            gfx_line(x, y, x + c1, y + c1);
            gfx_line(x, y, x + c1, y + c2);
            gfx_line(x, y, x + c1, y - c2);
            gfx_line(x, y, x + c1, y - c1);

            gfx_line(x, y, x - c1, y + c1);
            gfx_line(x, y, x - c1, y + c2);
            gfx_line(x, y, x - c1, y - c2);
            gfx_line(x, y, x - c1, y - c1);
            gfx_flush();
            usleep(2500); //24 por segundo
          }
      }
  }

void pintaCuadro(int lados)
  {
    printf("\nPintando cuadro de %dx%d\n",lados, lados);
    gfx_color(0,200,100);
    for(int t = 0; t < 2; t++)
      {
        gfx_clear();
        gfx_line(0, 0, 0, lados);
        gfx_line(0, lados, lados, lados);
        gfx_line(lados, lados,  lados, 0);
        gfx_line(lados, 0, 0, 0);
        gfx_flush();
        usleep(2500); //24 por segundo
      }
  }

void pintaRuta(int pasos)
  {

  }

int main(void)
{
  //******************** Mis variables :3
   char msg[] = "";
   char msg2[] = "Calculando";
   int s, res, clilen, sizeCuadro = 0, i = 0, posicionesContador = 0, aranaContador = 0, x = 0, y = 0;
   int coordSpider[2][1000][4]; //[x,y][posiciones][arañas]
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
   printf("\n¿Cuanto medirá el cuadro? :3\n");
   scanf("%d", &sizeCuadro);
   gfx_open(900, 900, "Arañas :3");
   while(1) {
      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
          recvfrom(s, (char *)&msg, 20*sizeof(char), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
          //printf("\n[ --- %s --- ]\n",msg);
          if(strcmp(msg, "Muffet") == 0)
            {
              int x, y;
              if(aranaContador > 4)
                {
                  aranaContador = 0;
                }
              printf("\nConectando con araña %d\n", i);
              sendto(s, (int *)&i, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
          //    printf("\nPosicion inicial asignada\n");
              sendto(s, (int *)&sizeCuadro, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
            //  printf("\nCuadro asignado\n");
              recvfrom(s, (int *)&x, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
              recvfrom(s, (int *)&y, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
            //  printf("\nPosiciones recibidas\n");
              coordSpider[0][posicionesContador][aranaContador] = x;
              coordSpider[1][posicionesContador][aranaContador] = y;
              /*  Posiciones x, y  */
              aranaContador++;
              i++;
            }
            /*Este if es por cada intento de conexion de una araña, si no se trata de una conexion
              entonces se proceden con calculos*/
              if(i > 3) //4 arañas conectadas
                {
                //    printf("\n%s\n", msg);
              //      printf("\nTodos conectados - Iniciando cálculos\n");
                    pintaCuadro(sizeCuadro);
                    for(int i = 0; i < 4; i++)
                      {
                        pintaArana(coordSpider[0][posicionesContador][i] ,
                                   coordSpider[1][posicionesContador][i]);
                      }
                  //  printf("\nArañas desplegadas\n");
                  /*  static char m2[] = "ponte a trabajar";
                    sendto(s, (char *)&m2, 20*sizeof(char), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
*/

                    int subContador = 1;
                    for(int j = 0; j < 4; j++)
                      {
                      //  printf("\n(%d, %d) -> (%d, %d)",                          coordSpider[0][posicionesContador][subContador-1],coordSpider[1][posicionesContador][subContador-1],                        coordSpider[0][posicionesContador][subContador],coordSpider[1][posicionesContador][subContador]);
                        if(subContador > 3)
                          {
                            subContador = 0;
                          }
                        //printf("\nEnviando posiciones de victima\n");
                        //sendto(s, (char *)&msg2, sizeof(msg2) * sizeof(char), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
                        //envio de que ya va a iniciar calculos
                        sendto(s, (int *)&coordSpider[0][posicionesContador][subContador], sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
                        sendto(s, (int *)&coordSpider[1][posicionesContador][subContador], sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
                        //envio posición de araña victima
                        //printf("\nVictima enviada\n");
                        recvfrom(s, (int *)&x, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
                        recvfrom(s, (int *)&y, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);

                        //printf("\nPosiciones de seguimiento recibidas \n");
                        coordSpider[0][posicionesContador + 1][subContador] = x;
                        coordSpider[1][posicionesContador + 1][subContador] = y;
                        printf("\nAraña %d (%d, %d)\n", subContador, coordSpider[0][posicionesContador + 1][subContador], coordSpider[1][posicionesContador + 1][subContador]);
                        //Recibo nuevas posiciones
                        subContador++;
                      }
                   posicionesContador++;
                   for(int i = 0; i < 4; i++)
                     {
                       //gfx_clear();
                       pintaArana(coordSpider[0][posicionesContador][i] ,
                                  coordSpider[1][posicionesContador][i]);
                     }
                   //printf("\nArañas desplegadas\n");
                }
              else
                {
                  continue;
                }//if i > 2

   }
}
