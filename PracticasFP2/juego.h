#ifndef juego_h //Proteccion de inclusiones duplicadas
#define juego_h

#include <iostream>
#include "tablero.h" //Incluimos el header "tablero.h" para poder usar tTablero
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
using namespace std;

//Definicion de tipos 

typedef struct {
	tTablero tableroJuego;
	int num_jugadas;
	bool mina_explotada;
	int num_minas;
	int num_descubiertas;
} tJuego;

//Definicion de funciones

void inicializar(tJuego& juego);

void inicializar_juego(tJuego& juego, int nfils, int ncols);

int dame_num_jugadas(tJuego juego);

int dame_num_filas(tJuego juego);

int dame_num_columnas(tJuego juego);

int dame_num_minas(tJuego juego);

bool contiene_mina(tJuego juego, int fila, int columna);

bool es_visible(tJuego juego, int fila, int columna);

bool esta_marcada(tJuego, int fila, int columna);

bool esta_vacia(tJuego juego, int fila, int columna);

bool contiene_numero(tJuego juego, int fila, int columna);

int dame_numero(tJuego juego, int fila, int columna);

bool mina_explotada(tJuego juego);

bool esta_terminado(tJuego juego);

void poner_mina(tJuego& juego, int fila, int columna);

void marcar_desmarcar(tJuego& juego, int fila, int columna);

void ocultar(tJuego& juego, int fila, int columna);

void juega(tJuego& juego, int fila, int columna, tListaPosiciones lista_pos);

#endif

