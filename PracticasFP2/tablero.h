#ifndef tablero_h //Proteccion de inclusiones duplicadas
#define tablero_h


#include "celda.h" //Incluimos el header "celda.h" para poder usar tCelda
#include <iostream>
using namespace std;

//Constantes temporales, ya se vera luego lo que hay que poner ahi
const int MAX_FILS = 10;
const int MAX_COLS = 10;

typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;

#endif