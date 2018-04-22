#include <string>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
#include <iostream>
int main()
  {
    int n;
    string line;
    cin >> n;
    getline(cin, line);
    cout << "n: " << n << " linea: " << line;
  }
