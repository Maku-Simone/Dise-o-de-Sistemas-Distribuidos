#include <iostream>
#include <unistd.h>
#include <thread>
#include <atomic>
using namespace std;

  void aumenta(int n, atomic<int>& local)
    {
      for(int i = 0; i < n; i++)
      {
        local++;
      }
      sleep(1);
    }
  void reduce(int n, atomic<int>& local)
    {
      for(int i = 0; i < n; i++)
        {
          local--;
        }
      sleep(1);
    }
int main()
  {
      int n = 500000;
      atomic<int> local(0);
      thread th1(aumenta, n, ref(local)), th2(reduce, n, ref(local));
      cout << "Proceso principal espera que los hilos terminen\n";
      th1.join();
      th2.join();
      cout << "\n Local " << local;
      cout << " El hilo principal termina\n";
      exit(0);
  }
