#include "Operaciones.h"
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if(argc != 4)
	{
		printf("Usage ./operaciones <#operacion> <i> <j>\n");
		exit(0);
	}
	float result;

	struct NUM numeros = {atoi(argv[2]), atoi(argv[3])};

	switch(atoi(argv[1]))
	{
		case 1:
			result = suma(numeros);
			break;
		case 2:
			result = producto(numeros);
			break;
		case 3:
				result = cociente(numeros);
				break;
		default:
				printf("1: Suma 2: Producto 3: Cociente\n");
				exit(1);
		}

		printf("%f\n", result);

	return 0;
}
//holi :3 lel :v c:
//saludos alondra :3
//hi :D
//Saludos a todos :p
