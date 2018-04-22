#include <iostream>
using namespace std;

int main( )
 {
    int opc, num1, num2;
    float num3, div;
    cout << "Dividamos numeritos -3-\n" << "1. Entero entre entero\n" << "2. Entero entre flotante\n";
    cin >> opc;
    if(opc != 1 && opc != 2)
	{
		cout << "Mal >:l";
		return 0;
	}
    cout << "Mete numero 1\n";
    cin >> num1;
    cout << "Mete num 2 \n";
    if(opc == 1)
	{
	  cin >> num2;
	  if(num2 == 0)
		{
			cout << "Como se te ocurre dividir entre cero >:c\n";
		}
	  else
		{
			div = num1/num2;
			cout << "La division de " << num1 << "/" << num2 <<" es de " << div <<"\n";
		}
	}
    else
	{
	  cin >> num3;
	  if(num3 == 0.0)
		{
			cout << "Como se te ocurre dividir entre cero >:c\n";
		}
	  else
		{
			div = num1/num3;
			cout << "La division de " << num1 << "/" << num3 <<" es de " << div << "\n";
		}
	}
   return 0;
}
