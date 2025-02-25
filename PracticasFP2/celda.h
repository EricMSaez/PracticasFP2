#ifndef celda.h
#define celda.h

#include <iostream>
using namespace std;

typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
	bool visible;
	tEstado estado;
	int numero;
	bool marcada;
} tCelda;

#endif