#ifndef juego_h //Proteccion de inclusiones duplicadas
#define juego_h

#include "celda.h" //Incluimos el header "celda.h"
#include "tablero.h" //Incluimos el header "tablero.h" para poder usar tTablero
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
#include <iostream>
using namespace std;


//Declaracion de tipos 

typedef struct {
	tTablero tableroJuego;
	int num_jugadas;
	bool mina_explotada;
	int num_minas;
	int num_descubiertas;
} tJuego;	


//Declaracion de funciones

void inicializar(tJuego& juego); //Crea un juego vacio, con el tablero vacio

void inicializar_juego(tJuego& juego, const int& nfils, const int& ncols); //Crea un juego con el tablero inizializado y celdas vacías

int dame_num_jugadas(const tJuego& juego);

int dame_num_filas(const tJuego& juego);

int dame_num_columnas(const tJuego& juego);

int dame_num_minas(const tJuego& juego);

bool contiene_mina(const tJuego& juego, const int& fila, const int& columna);

bool es_visible(const tJuego& juego, const int& fila, const int& columna);

bool esta_marcada(const tJuego& juego, const int& fila, const int& columna);

bool esta_vacia(const tJuego& juego, const int& fila, const int& columna);

bool contiene_numero(const tJuego& juego, const int& fila, const int& columna);

int dame_numero(const tJuego& juego, const int& fila, const int& columna);

bool esta_completo(const tJuego& juego);

bool mina_explotada(const tJuego& juego);

void poner_mina(tJuego& juego, const int& fila, const int& columna);

void marcar_desmarcar(tJuego& juego, const int& fila, const int& columna);

void ocultar(tJuego& juego, const int& fila, const int& columna);

void juega(tJuego& juego, const int& fila,const int& columna, tListaPosiciones& lista_pos);

#endif

