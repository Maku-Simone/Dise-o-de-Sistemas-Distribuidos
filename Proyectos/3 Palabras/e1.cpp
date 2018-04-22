#include "Archivo.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

using namespace std;

char buffer[10000];

int main(int argc, char const *argv[])
{

	if(argc != 3) {
		cout << "Forma de uso: " << argv[0] << " archivo_origen archivo_destino\n";
      	exit(-1);
   	}

   	//Archivo de lectura
	Archivo origen(argv[1]);

	//Archivo de escritura
	Archivo destino(argv[2],O_WRONLY|O_TRUNC|O_CREAT, 0666);

	origen.lee(100);
	destino.escribe(origen.get_contenido(), origen.obtieneNum_bytes());




	

	return 0;
}

