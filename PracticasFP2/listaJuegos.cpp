#include "listaJuegos.h"

void inicializar(tListaJuegos& lista_juegos) {
	lista_juegos.lista = new tJuego*[MAX_JUEGOS];
	lista_juegos.capacidad = MAX_JUEGOS;
	lista_juegos.cont = 0;
	for (int i = 0;i < MAX_JUEGOS;i++) {
		lista_juegos.lista[i] = NULL;
	}
}

void destruye(tListaJuegos& lista_juegos) {
		while (lista_juegos.cont >= 0) {
		delete lista_juegos.lista[lista_juegos.cont];
		lista_juegos.cont--;
		lista_juegos.capacidad++;
	}

	delete [] lista_juegos.lista;
}

void insertar(tListaJuegos lista_juegos, const tJuego& juego) {
	if (lista_juegos.capacidad > 0) {
		lista_juegos.lista[lista_juegos.cont] = new tJuego;
		lista_juegos.lista[lista_juegos.cont]->mina_explotada = juego.mina_explotada;
		lista_juegos.lista[lista_juegos.cont]->num_descubiertas = juego.num_descubiertas;
		lista_juegos.lista[lista_juegos.cont]->num_jugadas = juego.num_jugadas;
		lista_juegos.lista[lista_juegos.cont]->num_minas = juego.num_minas;
		lista_juegos.lista[lista_juegos.cont]->tableroJuego = juego.tableroJuego;

		lista_juegos.capacidad--;
		lista_juegos.cont++;
	}
}

int numero_juegos(const tListaJuegos& lista_juegos) {
	int numero_juegos;
	numero_juegos = lista_juegos.cont;
	return numero_juegos;
}

bool es_vacia(const tListaJuegos& lista_juegos) {
	bool es_vacia = true;
	
	if (lista_juegos.cont > 0) {
		es_vacia = false;
	}
	return es_vacia;
}

tJuego dame_juego(const tListaJuegos& lista_juegos, const int& pos) {
	tJuego juego;
	juego = *lista_juegos.lista[pos];
	return juego;
}

void eliminar(tListaJuegos lista_juegos, const int& pos) {
	int contador=pos;
	while (contador < lista_juegos.cont) {
		lista_juegos.lista[contador] = lista_juegos.lista[contador + 1];
		contador++;
	}
	delete lista_juegos.lista[lista_juegos.cont];
}