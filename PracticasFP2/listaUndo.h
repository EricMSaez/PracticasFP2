#ifndef listaUndo.h
#define listaUndo.h

#include <iostream>
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
const int MAX_UNDO = 10;

typedef struct {
	tListaPosiciones lista[MAX_UNDO];
	int cont;
} tListaUndo;

#endif
