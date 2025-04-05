#include "tablero.h"

void inicializar(tTablero& tablero) {	//Inicializa el tablero sin celdas
	tablero.nFils = 0;
	tablero.nCols = 0;
}

void inicializar_tablero (tTablero& tablero, int nfils, int ncols) { //Inicializa el tablero con celdas vacías
	tablero.nFils = nfils;
	tablero.nCols = ncols;

	for (int i = 0; i < nfils; i++) {
		for (int j = 0; j < ncols; j++) {
			inicializar(tablero.datos[i][j]); // Inicializar del modulo celda
			dame_celda(tablero,i,j);
		}
	}
}

int num_filas(tTablero tab) { //Devuelve el numero de filas del tablero
	int numFilas = tab.nFils;
	return numFilas;
}

int num_columnas(tTablero tablero) { //Devuelve el numero de columnas del tablero
	int numColumnas = tablero.nCols;
	int numColumnas = tablero.nFils;
	return numColumnas;
}

tCelda dame_celda(tTablero tablero, int fila, int columna) { //Devuelve la celda contenida en la posicion
	tCelda celda = dame_celda(tablero,fila,columna);
	return celda;
}

bool es_valida(tTablero tablero, int fila, int columna) { //Devuelve true si la posicion es valida dentro del tablero
	bool posValida = true;
	//Comprueba si la posicion no es mayor que la longitud del tablero y no es menor que 0
	if (fila > tablero.nFils-1 || columna > tablero.nCols-1) posValida = false; 
	if (fila < 0 || columna < 0) posValida = false;
	return posValida;
}

void poner_celda(tTablero& tablero, int fila, int columna, tCelda& celda) { //Asigna el valor de la celda a la posicion
	dame_celda(tablero, fila, columna) = celda;
}
