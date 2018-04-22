#include "Archivo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <vector>
#include <thread>
#include <mutex>
#include <set>
#include <iterator>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;




set<string> palabras;
map <string, int> mapPalabras;
vector<pair<string, int> > palabrasTotal;
vector<string> archivosALeer;
mutex m;
bool acento(vector<pair<string, int> > v, int i)
  {
    int mayus;
    for(int j = 0; j < v[i].first.size(); j++)
      {
        mayus = toupper((v[i].first)[j]);
        if(mayus < 'A' || mayus > 'Z')
          {
            return true;
          }
      }
    return false;
  }

bool ord(pair<string, int>  v1, pair<string, int> v2 )
  {
    if(v1.second > v2.second)
      {
        return true;
      }
    return false;
  }

bool esSeparador(string carac)
  {
    string separadores[25] = {"(", ")", "[", "]", ".", ",", " ", "—", "~", "!", "¡", "¿", "?", "\n", "\"", ":", ";", "-"};
    for(int i = 0; i < 25; i++)
      {
        if(carac.compare(separadores[i]) == 0)
          {
            return true;
          }
      }
      return false;
  }

void meteArchivos(string path)
  {
    int veces = 0;
    for(int i = 0; i < archivosALeer.size(); i++)
      {
        if(path.compare(archivosALeer[i]) == 0)// encontró una coincidencia
          {
            veces++;
          }
      }
    if(veces <= 0) //no existe en el vector
        {
          archivosALeer.push_back(path);
        }
  }

void metePalabra(string aux)
  {
    //cout << "\nLlego [" << aux << "]";
    m.lock();

    if(aux.size() >= 1)
      {
        int veces = 0;
        if(!isalpha(aux[0]))
          {
            aux.erase(0);
          }
          cout << aux[aux.size()];
        if(!isalpha(aux[aux.size()]))
          {
            aux.erase(aux.size());
          }
          palabras.insert(aux);
          mapPalabras[aux] += 1;
      }

    m.unlock();

  }

void verTop500()
  {
    //Variables
    const char separador = ' ';
    const int ancho = 6;
    int anchoP = 12;

    cout << "\n Palabras existentes: \n----------------------------------------------------------------------------------------------------------------------------------\n";
    vector <pair<string, int> > vect;
    set <string > :: iterator itr;
    map <string, int> :: iterator mapaItr;

    for (mapaItr = mapPalabras.begin(); mapaItr != mapPalabras.end(); ++mapaItr)
      {
        if((mapaItr->first).size() < 1)
          {
            continue;
          }
         vect.push_back(make_pair(mapaItr->first,mapaItr->second));
      }
    sort(vect.begin(), vect.end(), ord);
    for (int i = 0; i < 100; i++)
      {
          for(int n = 0; n < 5; n++)
            {
              const int m = n * 100;
              int ext = 0;
              if(acento(vect, i+m))
                {
                  ext = 1;
                }
              anchoP += ext;
              if(m == 0)
                {
                  cout << "\n# ";
                }
              else
                  {
                    cout << "#";
                  }

              cout << left << setw(ancho) << setfill(separador) << (i+m+1);
              cout << left << setw(anchoP) << setfill(separador) << vect[i+m].first;
              cout << left << setw(ancho) << setfill(separador) << vect[i+m].second;
              cout << " | ";
              if(ext > 0)
                {
                  anchoP--;
                }
            }
      }

    cout << "\n----------------------------------------------------------------------------------------------------------------------------------\n"  ;
    cout << "\n **Total de palabras " << palabras.size();
  }

void verBottom500()
  {
      //Variables
      const char separador = ' ';
      const int ancho = 7;
      int anchoP = 18;
      int anchoN = 3;

      cout << "\n Palabras existentes: \n----------------------------------------------------------------------------------------------------------------------------------\n";
      vector <pair<string, int> > vect;
      set <string > :: iterator itr;
      map <string, int> :: iterator mapaItr;

      for (mapaItr = mapPalabras.begin(); mapaItr != mapPalabras.end(); ++mapaItr)
        {
          if((mapaItr->first).size() < 1)
            {
              continue;
            }
           vect.push_back(make_pair(mapaItr->first,mapaItr->second));
        }
      sort(vect.begin(), vect.end(), ord);
      for (int i = vect.size()-502; i < vect.size()-1; i++)
        {
            for(int n = 0; n < 5; n++)
              {
                const int m = n * 100;
                int ext = 0;
                if(acento(vect, i+m))
                  {
                    ext = 1;
                  }
                anchoP += ext;
                if(m == 0)
                  {
                    cout << "\n# ";
                  }
                else
                    {
                      cout << "#";
                    }

                cout << left << setw(ancho) << setfill(separador) << (i+m+1);
                cout << left << setw(anchoP) << setfill(separador) << vect[i+m].first;
                cout << left << setw(anchoN) << setfill(separador) << vect[i+m].second;
                cout << " | ";
                if(ext > 0)
                  {
                    anchoP--;
                  }
              }
        }

      cout << "\n----------------------------------------------------------------------------------------------------------------------------------\n"  ;
      cout << "\n **Total de palabras " << palabras.size();
    }

void addPalabras(string nombreArchivo)
  {
    //cout << "\n\nLlego el archivo: " << nombreArchivo;
    Archivo arch(nombreArchivo);
    const int numeroBytes = arch.obtieneNum_bytes();
    const int BYTES_LEER =  1000000;
    string auxPalabra = "";
    char* texto;


    arch.lee(BYTES_LEER);

    for(int i = 0; i < BYTES_LEER; i++)
      {
        string caracter(1, (arch.get_contenido())[i]);
        //cout << "[" << caracter << "]";
        if(caracter.empty())
          {
            metePalabra(auxPalabra);
            break;
          }
        if(esSeparador(caracter) || caracter.size() < 1)
          {
            metePalabra(auxPalabra);
            auxPalabra = "";
          }
        else
            {
              auxPalabra += caracter;
            }
      }
  }

int main(int argc, char *argv[])
  {

    //Variables
    DIR *dir, *opendir(const char *name);
    struct dirent *dit, *readdir(DIR *dir);
    int numeroHilos = 0;
    int top;
    cout << "\n¿Cuantos hilos quieres usar? Mínimo 1, máximo 8\n";
    cin >> numeroHilos;
    if(numeroHilos > 8 || numeroHilos < 1)
      {
        cout << "\nNúmero de hilos inválido, te pondré los que yo quiera.";
        numeroHilos = rand() % 7 + 1;
        cout << "\nUsaré " << numeroHilos << " y te jodes\n";
      }
    if((dir = opendir(argv[1])) == NULL)
      {
        perror("opendir");
        return 0;
      }
    //cout << "Directorio abierto";
    while((dit = readdir(dir))  != NULL)
      {
        if(!strcmp(".", dit->d_name) || !strcmp("..", dit->d_name))
          {
            continue;
          }
        else
          {
            string path = "";
            string direc(argv[1]);
            string file(dit->d_name);
            path = direc + "/" + file;
            meteArchivos(path);
          }
      }
    /*  for(int j = 0; j < archivosALeer.size(); j++)
        {
          cout << "\n [" << archivosALeer[j] <<  "]";
        }
      cout << "\n **Total de archivos " << archivosALeer.size();*/
      int contados = 0;
      int hilosUsados = 0, archivos = archivosALeer.size();

      while(archivos > 0)
        {
          hilosUsados = 0;
          thread hilo[numeroHilos];
          for(int j = 0; j < numeroHilos; j++)
            {
                  if(contados == archivosALeer.size())
                    {
                      //cout << "\n break";
                        break;
                    }
                  else
                    {
                      cout << "\nHIlo " << j << " leyendo archivo " << contados << " : " << archivosALeer[contados];
                      hilo[j] = thread(addPalabras, archivosALeer[contados]);
                      contados++;
                      hilosUsados++;
                      archivos--;
                    }
            }
            for(int j = 0; j < hilosUsados; j++)
              {
                hilo[j].join();
              }
        }
      //cout << "\nReaddir encontró un total de " << i << " archivos";
      cout << "\n\n¿Que quieres ver?:\n1.- Top 500\n2.-Bottom 500\n";
      cin >> top;
      if(top == 1)
        {
          verTop500();
        }
      else
        {
          if(top == 2)
              {
                verBottom500();
              }
          else
              {
                cout << "\n¿Me hiciste leer "<< archivosALeer.size() <<" archivos solo para esto?...\n Te odio";
                exit(0);
              }
        }
  }
