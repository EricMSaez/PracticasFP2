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

void insertar(tListaJuegos& lista_juegos, const tJuego& juego) {
	if (lista_juegos.capacidad = 0) {
		redimensionar(lista_juegos);
	}
	lista_juegos.lista[lista_juegos.cont] = new tJuego;
	*lista_juegos.lista[lista_juegos.cont] = juego;
	lista_juegos.capacidad--;
	lista_juegos.cont++;
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

void eliminar(tListaJuegos& lista_juegos, const int& pos) {
	int contador=pos;
	delete lista_juegos.lista[pos];
	while (contador < lista_juegos.cont) {
		lista_juegos.lista[contador] = lista_juegos.lista[contador + 1];
		contador++;
	}
	lista_juegos.cont--;
	lista_juegos.capacidad++;
}

void redimensionar(tListaJuegos& lista_juegos) {
	int capacidadAntigua;	//Crea variable para almacenar la antigua capacidad total de la lista
	tJuego** aux;	//Creacion de puntero a array auxiliar de punteros a tJuego 

	capacidadAntigua = lista_juegos.cont;

	aux = new tJuego*[2 * capacidadAntigua]; //Crea array dinamico de punteros auxiliar

	for (int i = 0;i < capacidadAntigua;i++) { //Guarda en array dinamico de punteros auxiliar los punteros a los juegos guardados
		aux[i] = lista_juegos.lista[i];
	}

	delete[] lista_juegos.lista; //Destruye el array dinamico de punteros antiguo

	lista_juegos.lista = aux; //Se apunta el puntero de la lista al nuevo array dinamico de punteros
	lista_juegos.cont = capacidadAntigua * 2;
	lista_juegos.capacidad = capacidadAntigua;
}

