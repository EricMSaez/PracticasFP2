#ifndef tablero_h //Proteccion de inclusiones duplicadas
#define tablero_h


#include "celda.h" //Incluimos el header "celda.h" para poder usar tCelda
#include <iostream>
using namespace std;


//Constantes

//Filas y columnas maximas que el tablero puede tener
const int MAX_FILS = 20;
const int MAX_COLS = 20;


//Declaracion de tipos

typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
} tTablero;


//Declaración de las funciones

void inicializar(tTablero& tablero); // Inicializar tablero sin celdas

void inicializar_tablero(tTablero& tablero, int nfils, int ncols); // Inicializar tablero con celdas vacías

int dame_num_columnas(tTablero tablero);

int dame_num_filas(tTablero tablero);

tCelda dame_celda(tTablero tablero, int fila, int columna);

bool es_valida(tTablero tablero, int fila, int columna);

void poner_celda(tTablero& tablero, int fila, int columna, tCelda& celda);

int dame_num_columnas(tTablero tablero);

int dame_num_filas(tTablero tablero);

#endif