#include "listaJuegos.h"

void inicializar(tListaJuegos& lista_juegos) {
	
}

void destruye(tListaJuegos& tlista_juegos);

void insertar(const tListaJuegos& lista_juegos, const tJuego& juego);

int numero_juegos(const tListaJuegos& lista_juegos);

bool es_vacia(const tListaJuegos& lista_juegos);

tJuego dame_juego(const tListaJuegos& lista_juegos, const int& pos);

void eliminar(const tListaJuegos& lista_juegos, const int& pos);