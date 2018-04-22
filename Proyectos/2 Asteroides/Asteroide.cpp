#include "Asteroide.h"
#include "gfx.h"
#include <unistd.h>
using namespace std;
#include <time.h>
#include <stdlib.h>

Asteroide::Asteroide(int px, int py, int min, int max, int vel, int lad):x(px), y(py), rMin(min), rMax(max), velocidad(vel), lados(lad)
	{}
		
void Asteroide::dibujar(int x, int y, int min, int max, int lado)
	{
		int izq, der;
		int punto[lado][2];  //lados, xy
		if(rand()%2 == 1)
			{
				izq = lado/2;
			}
		else
			{
				der = lado/2;
				izq = lado - der;
			}  //con este if decido qué lado tendrá más vertices si es impar

			for(int i = 0; i < izq; i++)
				{
					int tempX, tempY;
					tempX = (rand() % max + min);
					tempY = (rand() % max + min);
					if(i < izq)
						{
							punto[i][0] = x - tempX;
							punto[i][1] = y - tempY;
						}
					else
						{
							punto[i][0] = x + tempX;
							punto[i][1] = y + tempY;
						} //este if es para sumar o restar sobre el origen para poner los puntos de un lado a otro
				}

			for(int j = 0; j < lado; j++)
					{
						if(j == lado - 1)
							{
								gfx_line(punto[j][0], punto[j][1],punto[0][0], punto[0][1]);
							}
						else
							{
								gfx_line(punto[j][0], punto[j][1],punto[j+1][0], punto[j+1][1]);
							}
					}

	}
