#include "tablero.h"
#include "celda.h"

void inicializar(tTablero& tablero) {
	tablero.nFils = 0;
	tablero.nCols = 0;
}

void inicializar_tablero (tTablero& tablero, int nfils, int ncols) {
	tablero.nFils = nfils;
	tablero.nCols = ncols;

	for (int i = 0; i < nfils; i++) {
		for (int j = 0; j < ncols; j++) {
			inicializar(tablero.datos[i][j]); // Inicializar del modulo celda
		}
	}
}

int num_filas(tTablero tab) {
	int numFilas = tab.nFils;
	return numFilas;
}

int num_columnas(tTablero tab) {
	int numColumnas = tab.nCols;
	return numColumnas;
}

tCelda dame_celda(tTablero tablero, int fila, int columna) {
	tCelda celda = tablero.datos[fila][columna];
	return celda;
}

bool es_valida(tTablero tablero, int fila, int columna) {
	bool posValida = true;
	if (fila > tablero.nFils-1 || columna > tablero.nCols-1) posValida = false;
	if (fila < 0 || columna < 0) posValida = false;
	return posValida;
}

void poner_celda(tTablero& tablero, int fila, int columna, tCelda& celda) {
	tablero.datos[fila][columna] = celda;
}