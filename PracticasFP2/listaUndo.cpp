#include "listaUndo.h"

void inicializar(tListaUndo& lista_undo) { //Inicializa el contador de la lista undo a 0
	lista_undo.cont=0;
}

void insertar_final(tListaUndo& lista_undo, tListaPosiciones& lista_pos) { //Inserta la lista de posiciones de la ultima jugada en lista undo
	//Si lista_undo esta llena se desplazan todos los elementos, descartando el de la pos 0
	if (lista_undo.cont == MAX_UNDO) {
		for (int i = 0; i < MAX_UNDO - 1; i++) {
			lista_undo.lista[i] = lista_undo.lista[i + 1];
		}
		*lista_undo.lista[MAX_UNDO - 1] = lista_pos;
	}
	//De lo contrario se añade a la lista
	else { 
		lista_undo.lista[lista_undo.cont] = new tListaPosiciones;
		*lista_undo.lista[lista_undo.cont] = lista_pos;
		lista_undo.cont++;
	}

	//Como la lista de posiciones ya está guardada volvemos a inizializarla
	inicializar(lista_pos); //LLamada a inicializar de listaPosiciones.h
}

tListaPosiciones ultimos_movimientos(tListaUndo lista_undo) { //Devuelve el ultimo elemento de lista undo

	tListaPosiciones ultimaPosicion;
	int final = lista_undo.cont;
	ultimaPosicion = *lista_undo.lista[final - 1];

	return ultimaPosicion;
}

void destruye(tListaUndo& lista_undo) { //Elimina la lista undo 
	for (int i = 0; i < lista_undo.cont; i++) {
		delete lista_undo.lista[i];
	}
}

void eliminar_ultimo(tListaUndo& lista_undo) { //Elimina la ultima lista de posiciones de la lista undo
	delete lista_undo.lista[lista_undo.cont];
}