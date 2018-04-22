#include "gfx.h"
//#include "Asteroide.h"
#include <unistd.h>
using namespace std;
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
/************************************************************************************************/
class Asteroide
  {
  private:
    double x;
    double y;
    double rMin;
    double rMax;
    double velx;
    double vely;
    double velocidad;
    double lados;
    vector<pair<int,int> > vectPuntos;
 public:
   Asteroide(int, int, int, int, int, int, int, int);
   void calcular(int, int, int, int, int);  //x, y, min, max, l
   vector<pair<int, int> > getVectCoords();
   void graficar(vector<Asteroide>);
   int valida(int);   //getData();
   vector<Asteroide> movimiento(vector<Asteroide>);
   double getSpeed();
   void setVector(vector<pair<int, int> >);
   void setCoordMov(int, int);
   double getVX();
   double getVY();
   pair<int, int> rotxy(double, double, int);
   double getx();
   double gety();
   pair<int, int> setCentro(int, int);
   pair<int, int> getForma(int);

 };
 /***********************************************************************************************/
Asteroide::Asteroide(int px, int py, int min, int max, int vel, int lad, int vx, int vy):x(px), y(py), rMin(min), rMax(max), velocidad(vel), lados(lad), velx(vx), vely(vy)
 	{}

void Asteroide::calcular(int x, int y, int min, int max, int lado)
 	{
    int punto[lado][2];
    pair<int,int> parCoord[lado];
    Asteroide astt(1,1,1,1,1,1,1,1);
    int anguloTotal = 360, angulo = 1;
    anguloTotal /= lado; //para sacar cada pedacito del angulo


    if(lado == 8)
      {
        punto[0][0] = x + max*(1.8);
        punto[0][1] = y + max*(2.1);

        punto[1][0] = x + max*(3);
        punto[1][1] = y;

        punto[2][0] = x + max*(2.1);
        punto[2][1] = y - max*(1.7);

        punto[3][0] = x + 0.1*max;
        punto[3][1] = y - max*(2.6);

        punto[4][0] = x - max*(1.7);
        punto[4][1] = y - max*(1.9);

        punto[5][0] = x - max*(2.8);
        punto[5][1] = y + 0.3*max;

        punto[6][0] = x - max*(2.2);
        punto[6][1] = y + max*(1.8);

        punto[7][0] = x + 0.3*max;
        punto[7][1] = y + max*(2.6);
      }
    if(lado == 9)
      {
        punto[0][0] = x + 0.3*max;
        punto[0][1] = y + 1.5*max;

        punto[1][0] = x + max;
        punto[1][1] = y + 0.7*max;

        punto[2][0] = x + 1.2*max;
        punto[2][1] = y - 0.3*max;

        punto[3][0] = x +0.1*max ;
        punto[3][1] = y - 1.3*max ;

        punto[4][0] = x - 0.3*max ;
        punto[4][1] = y - 1.6*max ;

        punto[5][0] = x - max;
        punto[5][1] = y - max ;

        punto[6][0] = x - max ;
        punto[6][1] = y ;

        punto[7][0] = x - 0.7*max;
        punto[7][1] = y + 0.7*max;

        punto[8][0] = x - 0.2*max ;
        punto[8][1] = y + max;
      }
    if(lado == 10)
      {
        punto[0][0] = x;
        punto[0][1] = y + 1.2 * max;

        punto[1][0] = x + 0.5*max;
        punto[1][1] = y + max;

        punto[2][0] = x + 1.1*max;
        punto[2][1] = y + 0.5*max;

        punto[3][0] = x + 0.8*max;
        punto[3][1] = y;

        punto[4][0] = x + 0.8*max ;
        punto[4][1] = y - 0.6*max;

        punto[5][0] = x + 0.3*max;
        punto[5][1] = y - 1.2*max ;

        punto[6][0] = x - 0.3*max ;
        punto[6][1] = y - max;

        punto[7][0] = x - 0.9*max ;
        punto[7][1] = y - 0.2*max ;

        punto[8][0] = x - 1.1*max;
        punto[8][1] = y + 0.5*max;

        punto[9][0] = x - 0.1*max ;
        punto[9][1] = y + max;
      }
    if(lado == 11)
      {
        punto[0][0] = x + 0.2*max;
        punto[0][1] = y + 0.6*max;

        punto[1][0] = x + 0.4*max;
        punto[1][1] = y + 0.4*max;

        punto[2][0] = x + 0.8*max;
        punto[2][1] = y + 0.3*max;

        punto[3][0] = x + 0.9*max;
        punto[3][1] = y - 0.1*max;

        punto[4][0] = x + 0.6*max ;
        punto[4][1] = y - 0.4*max;

        punto[5][0] = x + 0.2*max;
        punto[5][1] = y - 0.5*max ;

        punto[6][0] = x - 0.4*max ;
        punto[6][1] = y - 0.2*max;

        punto[7][0] = x - 0.6*max ;
        punto[7][1] = y - 0.3*max ;

        punto[8][0] = x - 0.9*max;
        punto[8][1] = y + 0.2*max;

        punto[9][0] = x - 0.5*max ;
        punto[9][1] = y + 0.5*max;

        punto[10][0] = x - 0.1*max;
        punto[10][1] = y + 0.8*max;
      }
 			/*for(int i = 0; i < lado; i++)
 				{
 					int tempX = 0, tempY = 0;
          angulo = anguloTotal * i;
        //  cout << "angulo: " << angulo;//
          if(angulo % 90 == 0)
            {
              angulo += 1;
            }
 					tempX = (rand() % (max));
          if(tempX < min)
            {
              tempY = astt.valida(round(abs((min)*tan(angulo*(1)))));
            }
          else
            {
              tempY = astt.valida(round(abs((tempX)*tan(angulo*(1)))));
            }
          if(angulo >= 0 && angulo <= 90)
            {
              punto[i][0] = x + tempX;
              punto[i][1] = y + tempY;
              //cout << "tempy = " << tan(angulo);
            }
          if(angulo >= 91 && angulo <= 180)
            {
              punto[i][0] = x - tempX;
              punto[i][1] = y + tempY;
            }
          if(angulo >= 181 && angulo <= 270)
            {
              punto[i][0] = x - tempX;
              punto[i][1] = y - tempY;
            }
          if(angulo >= 271 && angulo <= 360)
            {
              punto[i][0] = x + tempX;
              punto[i][1] = y - tempY;
            }
            //cout << "\nx " << x << " y " << y << " tempx " << tempX << " tempy " << tempY << " angulo " << angulo << "\n";//
 				}*/

 			for(int j = 0; j < lado; j++)
 					{
            parCoord[j].first = punto[j][0];
            parCoord[j].second = punto[j][1];
            vectPuntos.push_back(parCoord[j]);
 					}

 	}

vector<pair<int, int> > Asteroide::getVectCoords()
  {
      return vectPuntos;
  }

void Asteroide::graficar(vector<Asteroide> vectAstGraf)
  {
      int totalAsteroides;
      vector<pair<int, int> > vectCoordMain; //declaro mi arreglo de pares
      totalAsteroides = vectAstGraf.size(); //saco el tamaño del arreglo de pares
      gfx_flush();

      for(int i = 0; i < totalAsteroides; i++)
        {
          int totalCoordenadas;
          vectCoordMain = vectAstGraf[i].getVectCoords(); //obtengo el vector de pares(coordenadas) de cada uno de los n asteroides
          totalCoordenadas = vectCoordMain.size();
          Asteroide as(1, 1, 1, 1, 1, 1, 1, 1);
          for(int j = 0; j < totalCoordenadas; j++) //aqui graficaré cada coordenada de cada asteroide :3
            {

              if(j == totalCoordenadas - 1)
                {
                    gfx_line(vectCoordMain[j].first, vectCoordMain[j].second,vectCoordMain[0].first, vectCoordMain[0].second);
                }
              else
                {
                  gfx_line(vectCoordMain[j].first, vectCoordMain[j].second,vectCoordMain[j+1].first, vectCoordMain[j+1].second);
                }
            }
        }
    }

int Asteroide::valida(int num)
  {
    if(num > 30 || num < 1)
      {
        return 10;
      }
    else
      {
        return num;
      }
  }

double Asteroide::getx()
  {
    return x;
  }

double Asteroide::gety()
  {
    return y;
  }

void Asteroide::setVector(vector<pair<int, int> > nuevo)
  {
    for(int i = 0; i < nuevo.size(); i++)
      {
        vectPuntos[i].first = nuevo[i].first;


        vectPuntos[i].second = nuevo[i].second;
      }
  }

vector<Asteroide> Asteroide::movimiento(vector<Asteroide> vectMovAst)
  {
    int totalAsteroides;
    vector<pair<int, int> > vectCoordMain; //declaro mi arreglo de pares
    totalAsteroides = vectMovAst.size(); //saco el tamaño del arreglo de pares
    Asteroide as(1, 1, 1, 1, 1, 1, 1, 1);
    for(int i = 0; i < totalAsteroides; i++)
      {
        int totalCoordenadas;
        int velocAsteroide;
        vectCoordMain = vectMovAst[i].getVectCoords(); //obtengo el vector de pares(coordenadas) de cada uno de los n asteroides
        totalCoordenadas = vectCoordMain.size();
        velocAsteroide = vectMovAst[i].getSpeed();
        pair<int, int> rot;
        pair<int, int> trans;
        int rotAngle;
        if(rand() % 2 == 0)
          {
            rotAngle = -rand()% velocAsteroide + 1;
          }
        else
          {
            rotAngle = rand()% velocAsteroide + 1;
          }
        int veces = 0;
        for(int j = 0; j < totalCoordenadas; j++) //aqui graficaré cada coordenada de cada asteroide :3
          {
            int x = vectCoordMain[j].first - vectMovAst[i].getx();
            int y = vectCoordMain[j].second - vectMovAst[i].gety();
            rot = rotxy(x, y, rotAngle);
            vectCoordMain[j].first = rot.first + vectMovAst[i].getx() + vectMovAst[i].getVX();// + vectMovAst[i].getx();
            vectCoordMain[j].second = rot.second +vectMovAst[i].gety() +  vectMovAst[i].getVY();//+  + vectMovAst[i].gety();
          }
          pair<int, int> nuevoC = vectMovAst[i].setCentro(vectMovAst[i].getVX(),vectMovAst[i].getVY());
          for(int j = 0; j < totalCoordenadas; j++) //aqui graficaré cada coordenada de cada asteroide :3
            {
              vectCoordMain[j].first += nuevoC.first;// + vectMovAst[i].getx();
              vectCoordMain[j].second += nuevoC.second;//+  + vectMovAst[i].gety();
            }
          vectMovAst[i].setVector(vectCoordMain);
      }
      as.graficar(vectMovAst);
      return vectMovAst;
  }

double Asteroide::getSpeed()
  {
    return velocidad;
  }

void Asteroide::setCoordMov(int x, int y)
  {
      x += x;
      y += y;
    }

double Asteroide::getVX()
  {
        return velx;
      }

double Asteroide::getVY()
  {
        return vely;
      }

pair<int, int> Asteroide::rotxy(double x, double y, int angle)
  {
    pair<int, int> rotado;
    rotado.first = round((x*cos(angle) - y*sin(angle)));
    rotado.second = round((y*cos(angle) + x*sin(angle)));
    return rotado;
  }

pair<int, int> Asteroide::setCentro(int nx, int ny)
  {
    pair<int, int> nuevoCentro;
    if(x + nx >= 1200) // x se pasa
      {
          x = 0;
          y += ny;
          nuevoCentro.first = -1200;
          nuevoCentro.second = 0;
      }
    else
      {
        if(y + ny >= 700) //y se pasa
          {
            y = 0;
            x += nx;
            nuevoCentro.first = 0;
            nuevoCentro.second = -700;
          }
        else
          {
            if((x + nx >= 1200) && (y + ny >= 700)) //los dos se pasan
              {
                x = 0;
                y = 0;
                nuevoCentro.first = -1200;
                nuevoCentro.second = -700;
              }
            else
              {
                if(x + nx < 0) //se mete x
                  {
                    x = 1200;
                    y += ny;
                    nuevoCentro.first = x;
                    nuevoCentro.second = 0;
                  }
                else
                  {
                    if(y + ny < 0) //y se mete
                      {
                        y = 700;
                        x += nx;
                        nuevoCentro.first = 0;
                        nuevoCentro.second = y;
                      }
                    else
                      {
                        if((x + nx <= 0) && (y + ny <= 0)) //ambos metidos
                          {
                            x = 1200;
                            y = 700;
                            nuevoCentro.first = x;
                            nuevoCentro.second = y;
                          }
                        else
                          {
                            x += nx;
                            y += ny;
                            nuevoCentro.first = 0;
                            nuevoCentro.second = 0;
                          }
                      }
                  } //y se mete
              }// x se mete
          }
      }//else principal
      return nuevoCentro;
  }
/************************************************************************************************/


int main()
  {
    int numAsteroides;
    cout << "Cuantos asteroides quieres?\n";
    cin >> numAsteroides;
    vector<Asteroide> vectAst;
    gfx_open(1200, 700, "Asteroides sensuales :3");
    gfx_color(0,200,100);
    srand(time(NULL));
    //gfx_clear();
    for(int i = 0; i < numAsteroides; i++)
      {
        double velx, vely;
        velx = rand() % 3 - 1;
        vely = rand() % 3 - 1;
        int x = rand() % 1200; //30 - 900
        int y = rand() % 750; //30 - 700
        double rMax = (rand() % 20 + 5) * 1.000; // 5 - 25
        double rMin =  (rand() % 5 + 5) * 1.000; // 15 - 20
        int lados = (rand() % 3 + 8);
        double velocidad = (50/rMax);
        //cout << "\n rmax" << rMax << " rmin " << rMin << " rMax/Rmin " << rMax/rMin << " rmin/Rmax " << rMin/rMax;//
        velx *= velocidad;
        vely *= velocidad;
        Asteroide ast(x, y, rMin, rMax, velocidad, lados, velx, vely);
        ast.calcular(x, y, rMin, rMax, lados);
        vectAst.push_back(ast);
      //  gfx_flush();
      }
      Asteroide aster(1, 1, 1, 1, 1, 1, 1, 1);
      aster.graficar(vectAst);
      for(; ;)
        {
          gfx_clear();
          vectAst = aster.movimiento(vectAst);
          gfx_flush();
          usleep(100000);
        }
      gfx_wait();
      return 1;
  }
