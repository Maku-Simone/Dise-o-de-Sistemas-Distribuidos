#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <math.h>


int puerto = 7200;

typedef struct CoordsStruct{
  int x;
  int y;
  int xCalc;
  int yCalc;
  int x2;
  int y2;
  double velocidad;
  double m;
  double distancia;
};

int main(int argc, char *argv[])
{
  struct sockaddr_in msg_to_server_addr, client_addr;
  int s, res = 0, cuadro = 0;
  struct CoordsStruct spider[4] = {0,0,0,0,0,0,0.0,0.0,0.0};

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
  char msg[] = "Muffet", msg2[] = "6u6";

  /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
  client_addr.sin_port = htons(9000);
  bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));

  for(int i = 0; i < 4; i++)
    {
        printf("\nSoy la arana %d, ¿Cual será mi velocidad (v)? :3 {v | v [0, 10]}\n", i);
        fflush(stdin);
        scanf("%lf", &(spider[i].velocidad));
        if(spider[i].velocidad > 10.0)
         {
           printf("\nLa araña ha ido tan rápido que no ha podido mantener su forma física \n");
           printf("\n*** La araña ahora está en el plano astral @3@ ***\n");
           exit(0);
         }
    }
  for(int i = 0; i < 4; i++)
    {
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
           spider[i].y = cuadro;
         break;
         case 2:
           spider[i].x = cuadro;
           spider[i].y = cuadro;
         break;
         case 3:
           spider[i].x = cuadro;
         break;
         default:
             ;
       }
       if(spider[i].x >= cuadro/2)
        {
          spider[i].x -= cuadro/2;
        }
      else
        {
          spider[i].x = (cuadro/2) - spider[i].x;
        }
      if(spider[i].y <= cuadro/2)
       {
         spider[i].y = (cuadro/2) - spider[i].y;
       }
       else
          {
            spider[i].y -= cuadro/2;
          }

       spider[i].xCalc = spider[i].x;
       spider[i].yCalc = spider[i].y;
       printf("\nSoy la araña %d, cuadro mide %d, mi posición es (%d, %d) y viajo a %lfpx/s\n",
        res, cuadro, spider[i].x, spider[i].y, spider[i].velocidad);
       sendto(s, (int *)&(spider[i].xCalc), sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
       sendto(s, (int *)&(spider[i].yCalc), sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
       printf("\n*** Posiciones enviadas ***\n");
    }
    printf("\nEntrando en ciclo\n");
    int i = 0;
    while(1)
      {
        if(i > 3)
          {
            i = 0;
          }
        printf("\nCalculando *3*\n");
        recvfrom(s, (int *)&(spider[i].x2), sizeof(int), 0, NULL, NULL);
        recvfrom(s, (int *)&(spider[i].y2), sizeof(int), 0, NULL, NULL);
        //recibi posicion de mi victima
        printf("\n(%d, %d) -> (%d, %d) victima\n",spider[i].x, spider[i].y, spider[i].x2, spider[i].y2);
        spider[i].m = (spider[i].y2*1.0 - spider[i].y*1.0)/(spider[i].x2*1.0 - spider[i].x*1.0);
        spider[i].xCalc = (spider[i].velocidad / (sqrt(1 + spider[i].m*spider[i].m)) ) + spider[i].x;
        spider[i].yCalc = (spider[i].velocidad / (sqrt(1 + (1/(spider[i].m*spider[i].m))  )) ) + spider[i].y;
        //Hag mis calculos
        printf("\nCalculando nueva posicion\n");
        sendto(s, (int *)&(spider[i].xCalc), sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
        sendto(s, (int *)&(spider[i].yCalc), sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
        //envio mi nueva posición
        printf("\nNueva posicion enviada\n");
        spider[i].x = spider[i].xCalc;
        spider[i].y = spider[i].yCalc;
        //me muevo a mi nueva posicions
        i++;
        sendto(s, (char *)&msg2, sizeof(msg2) * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
      }

  //cuando ya tenga 4 arañas conectadas deberia recibir algo aqui




//  sendto(s, (char *)&pos, sizeof(pos) * sizeof(char), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
/*
  while(1)
   {
     char mensaje[] = "";
     recvfrom(s, (char *)&mensaje, 20*sizeof(char), 0, NULL, NULL);
     printf("\n(%s)\n", mensaje);
     if(strcmp(mensaje, "Calculando") == 0)
       {


       }
   }

  close(s);*/
}
