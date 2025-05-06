#include "listaPosiciones.h"

void inicializar(tListaPosiciones& lista_pos) { //Inicializa la lista de posiciones

	lista_pos.lista = new tPosicion[MAX_LISTA];
	lista_pos.capacidad = MAX_LISTA;
	lista_pos.cont = 0;
}

void insertar_final(tListaPosiciones& lista_pos, const int& x, const int& y) { //Inserta la ultima jugada en la lista de posiciones

	if (lista_pos.capacidad = 0) { //Comprueba que la lista de posiciones no este llena
		redimensionamiento(lista_pos);
	}

	lista_pos.lista[lista_pos.cont].posx = x; //Guarda coord. x
	lista_pos.lista[lista_pos.cont].posy = y; //Guarda coord. y
	lista_pos.cont++; //Aumenta contador de la lista de posiciones
}

int longitud(const tListaPosiciones& lista_pos) { //Devuelve el numero de elementos de una lista de posiciones
	int longitud;
	longitud = lista_pos.cont;
	return longitud;
}

int dame_posX(const tListaPosiciones& lista_pos, const int& i) { //Devuelve la coordenada x de un elemento seleccionado de la lista de posiciones
	int posX;
	posX = lista_pos.lista[i].posx; 
	return posX;
}

int dame_posY(const tListaPosiciones& lista_pos, const int& i) { //Devuelve la coordenada x de un elemento seleccionado de la lista de posiciones
	int posY;
	posY = lista_pos.lista[i].posy;
	return posY;
}

void destruye(tListaPosiciones& lista_pos) {
	
	if (lista_pos.lista != NULL) {
		delete[] lista_pos.lista;
		lista_pos.lista = NULL;
	}
}

void redimensionamiento(tListaPosiciones& lista_pos) {
	
	tPosicion* nueva;
	int capacidadAntigua = lista_pos.cont;
	nueva = new tPosicion [2 * capacidadAntigua];

	for (int i = 0; i < capacidadAntigua; i++) {
		nueva[i] = lista_pos.lista[i];
		
	}	  

	delete [] lista_pos.lista;

	lista_pos.capacidad = capacidadAntigua;
	lista_pos.cont = 2 * capacidadAntigua;
	lista_pos.lista = nueva;


}