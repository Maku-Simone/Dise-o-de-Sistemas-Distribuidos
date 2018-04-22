#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct NUM{
	float i;
	float j;
};

double suma(struct NUM numeros);
double producto(struct NUM numeros);
float cociente(struct NUM numeros);

double suma(struct NUM numeros)
{
	return numeros.i+numeros.j;
}

double producto(struct NUM numeros)
{
	return numeros.i*numeros.j;
}

float cociente(struct NUM numeros)
{
	return numeros.i/numeros.j;
}
