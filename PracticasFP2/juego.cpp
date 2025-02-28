#include "juego.h"
#include "tablero.h"
#include "celda.h"

void inicializar(tJuego juego) {
	juego.num_jugadas = 0;
	juego.mina_explotada = false;
	juego.num_minas = 0;
	juego.num_descubiertas = 0;
	inicializar(juego.tableroJuego);
}

void inicializar_juego(tJuego juego, int nfils, int ncols) {
	inicializar(juego);
	inicializar_tablero(juego.tableroJuego, nfils, ncols);
};

int dame_num_jugadas(tJuego juego) {
	int num_jugadas = juego.num_jugadas;
	return num_jugadas;
}

int dame_num_filas(tJuego juego) {
	int num_filas = juego.tableroJuego.nFils;
	return num_filas;
}

int dame_num_columnas(tJuego juego) {
	int num_columnas = juego.tableroJuego.nCols;
	return num_columnas;
}

int dame_num_minas(tJuego juego) {
	int num_minas = juego.num_minas;
	return num_minas;
}

bool contiene_mina(tJuego juego, int fila, int columna) {
	return es_mina(juego.tableroJuego.datos[fila][columna]);
}

bool es_visible(tJuego juego, int fila, int columna) {
	return es_visible(juego.tableroJuego.datos[fila][columna]);
}

bool esta_marcada(tJuego juego, int fila, int columna) {
	return esta_marcada(juego.tableroJuego.datos[fila][columna]);
}

bool esta_vacia(tJuego juego, int fila, int columna) {
	return esta_vacia(juego.tableroJuego.datos[fila][columna]);
}

bool contiene_numero(tJuego juego, int fila, int columna) {
	return contiene_numero(juego.tableroJuego.datos[fila][columna]);
}

int dame_numero(tJuego juego, int fila, int columna) {

}
