#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;
int global = 0;
void funcion(int valor)
  {
      printf("Hilo %ld Valor recibido: %d\n", this_thread::get_id(),  valor);
      sleep(2);
  }
  void aumenta(int n)
    {
      for(int i = 0; i < n; i++)
      {
        global++;
      }
      sleep(1);
    }
  void reduce(int n)
    {
      for(int i = 0; i < n; i++)
        {
          global--;
        }
      sleep(1);
    }
int main()
  {
      int n = 500000;
      thread th1(aumenta, n), th2(reduce, n);
      cout << "Proceso principal espera que los hilos terminen\n";
      th1.join();
      th2.join();
      printf("\n Global %d", global);
      cout << " El hilo principal termina\n";
      exit(0);
  }
