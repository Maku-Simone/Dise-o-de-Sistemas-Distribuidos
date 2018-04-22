#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
  {
    char* cadenota;
    int apariciones = 0, palabras = 0; //10M
    char letra;
     scanf("%d",&palabras);
    srand(time(NULL));
    cadenota = malloc(palabras * sizeof(char));
    for(int i = 0; i < palabras; i++)
      {
        for(int j = 0; j < 3; j++)
          {
            letra = 'A' + (rand() % 26);
            strcat(cadenota,letra + "");
          }
          strcat(cadenota," ");
      }
    /*for(int i = 0; i < cadenota.size(); i++)
        {
          cout << cadenota[i];
        }*/
    int posAnt = 0;
    char *pos;
      for(int i = 0; i < sizeof(cadenota); i+=4)
        {
          char* sub;
          sub = malloc(4 * sizeof(char));
          for(int j = 0; j < 4; j++)
            {
              strcpy(sub, cadenota[i+j]);
            }
          pos = strstr(sub,"IPN");
          if(pos)
            {
              apariciones ++;
            }
        }
        printf("\nApariciones ", apariciones);;
  }
