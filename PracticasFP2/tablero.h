#ifndef tablero_h
#define tablero_h

#include <iostream>
#include "celda.h" //Incluimos el header "celda.h" para poder usar tCelda
using namespace std;

//Constantes temporales, ya se vera luego lo que hay que poner ahi
const int MAX_FILS = 10;
const int MAX_COLS = 10;

typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;

#endif