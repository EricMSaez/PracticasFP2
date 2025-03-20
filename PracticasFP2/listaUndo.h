#ifndef listaUndo_h //Proteccion de inclusiones duplicadas
#define listaUndo_h

#include <iostream>
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
#include "tablero.h"	//Incluimos el header "tablero.h" para poder usar tTablero
using namespace std;

const int MAX_UNDO = 10;

typedef struct {
	tListaPosiciones lista[MAX_UNDO];
	int cont;
} tListaUndo;

void inicializar(tListaUndo& lista_undo);
void insertar_final(tListaUndo& lista_undo, tListaPosiciones& lista_pos, tTablero tablero);
tListaPosiciones ultimos_movimientos(tListaUndo lista_undo);
#endif

