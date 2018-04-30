#include "gfx.h"
#include <unistd.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
int t;
  gfx_open(800, 600, "Sensual Fourier ");
  gfx_color(0,200,100);
  gfx_clear();
  for(t = 0; t < 800; t++)
  {
    gfx_point(t,sin(t));
    gfx_flush();
    usleep(41666); //24 por segundo
  }
return 0;
}
