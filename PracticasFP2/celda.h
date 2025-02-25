#ifndef celda_h
#define celda_h

#include <iostream>
using namespace std;

typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
	bool visible;
	tEstado estado;
	int numero;
	bool marcada;
} tCelda;

void inicializar(tCelda Celda);

tEstado dame_estado(tCelda Celda);

int dame_numero(tCelda Celda);

#endif