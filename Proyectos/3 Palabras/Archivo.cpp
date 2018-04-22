#include "Archivo.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Archivo::Archivo(string filename)
{
	nombreArchivo = filename;
	
	fd = open(nombreArchivo.c_str(), O_RDONLY);
	
	if(fd == -1)
  	{
       perror(nombreArchivo.c_str());
       exit(-1);
   	}

   	contenido = NULL;

}

Archivo::Archivo(string filename, int banderas, mode_t modo)
{
	nombreArchivo = filename;
	fd = open(nombreArchivo.c_str(), banderas, modo);

	if(fd == -1)
  	{
       perror(nombreArchivo.c_str());
       exit(-1);
   	}

   	contenido = NULL;

}

size_t Archivo::lee(size_t nbytes)
{
	contenido = (char*) realloc(contenido, nbytes);
	num_bytes = read(fd, contenido, nbytes);

	return num_bytes;
}

size_t Archivo::escribe(void *buffer, size_t nbytes)
{
	write(fd, buffer, nbytes);
}

size_t Archivo::obtieneNum_bytes()
{
	return num_bytes;
}

char *Archivo::get_contenido()
{
	return contenido;
}

Archivo::~Archivo(){
	close(fd);
}



