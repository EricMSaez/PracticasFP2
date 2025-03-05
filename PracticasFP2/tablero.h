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

//Declaración de las funciones

void inicializar(tTablero& tablero);	// Inicializar tablero sin celdas

void inicializar_tablero(tTablero& tablero, int nfils, int ncols); // Inicializar tablero con celdas vacías

int num_filas(tTablero tab);

int num_columnas(tTablero tab);

tCelda dame_celda(tTablero tablero, int fila, int columna);

bool es_valida(tTablero tablero, int fila, int columna);

void poner_celda(tTablero& tablero, int fila, int columna, tCelda& celda);

#endif