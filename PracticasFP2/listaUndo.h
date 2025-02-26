#ifndef listaUndo_h //Proteccion de inclusiones duplicadas
#define listaUndo_h

#include <iostream>
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
const int MAX_UNDO = 10;

typedef struct {
	tListaPosiciones lista[MAX_UNDO];
	int cont;
} tListaUndo;

#endif
