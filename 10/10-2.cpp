#include <iostream>
#include <unistd.h>
#include <thread>
using namespace std;
int global = 0;
void funcion(int valor)
  {
      printf("Hilo %u Valor recibido: %d\n", this_thread::get_id(),  valor);
      sleep(2);
  }
  void aumenta()
    {
      global++;
      sleep(1);
    }
  void reduce()
    {
      global--;
      sleep(1);
    }
int main()
  {
      thread th1(aumenta), th2(reduce);
      cout << "Proceso principal espera que los hilos terminen\n";
      th1.join();
      th2.join();
      printf("\n Global %d", global);
      cout << "El hilo principal termina\n";
      exit(0);
  }
