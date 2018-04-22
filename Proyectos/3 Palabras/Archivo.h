#ifndef ARCHIVO_H_
#define ARCHIVO_H_
#include <iostream>
#include <fcntl.h>
using namespace std;

class Archivo
{
private: 
	string nombreArchivo;
	int fd;
	char *contenido;
	size_t num_bytes;
public:
	Archivo(string filename);
	Archivo(string filename, int banderas, mode_t modo);
	size_t lee(size_t nbytes);
	size_t escribe(void *buffer, size_t nbytes);
	size_t obtieneNum_bytes();
	char *get_contenido();
	~Archivo();
};

#endif