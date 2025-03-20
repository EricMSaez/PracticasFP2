#include "listaUndo.h"
#include "tablero.h"

void inicializar(tListaUndo& lista_undo) {
	lista_undo.cont = 0;
}

void insertar_final(tListaUndo& lista_undo, tListaPosiciones& lista_pos, tTablero tablero) {
	if (lista_undo.cont == MAX_UNDO) {		//Desplaza todas las listas de posiciones en caso de que este llena la lista undo
		for (int i = 0; i < MAX_UNDO; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		}
		lista_undo.lista[0] = lista_pos;
		lista_undo.cont++;
	}
	else {
		lista_undo.lista[lista_undo.cont] = lista_pos;
		lista_undo.cont++;
	}
	inicializar_listaPosiciones(lista_pos);
}

tListaPosiciones ultimos_movimientos(tListaUndo lista_undo) {

	tListaPosiciones ultimaPosicion;
	int final = lista_undo.cont;
	ultimaPosicion = lista_undo.lista[final - 1];

	return ultimaPosicion;
}
