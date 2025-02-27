#include "listaUndo.h"

void inicializar(tListaUndo lista_undo) {
	lista_undo.cont = 0;
}

void insertar_final(tListaUndo lista_undo, tListaPosiciones lista_pos) {

	if (lista_undo.cont == MAX_UNDO) {
		for (int i = 0; i < MAX_UNDO - 1; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		}
		lista_undo.lista[MAX_UNDO - 1] = lista_pos;
	}
	else lista_undo.lista[lista_undo.cont] = lista_pos;
}

tListaPosiciones ultimos_movimientos(tListaUndo lista_undo) {

	tListaPosiciones posicion;
	int final = lista_undo.cont;
	posicion = lista_undo.lista[final - 1];

	return posicion;
}