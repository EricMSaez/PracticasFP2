#include "listaPosiciones.h"

void inicializar_listaPosiciones(tListaPosiciones& lista_pos) {
	lista_pos.cont = 0;
}

void insertar_final(tListaPosiciones& lista_pos, int x, int y) {
	lista_pos.lista[lista_pos.cont].posx = x;
	lista_pos.lista[lista_pos.cont].posy = y;
	lista_pos.cont++;
}

int longitud(tListaPosiciones lista_pos) {
	int longitud;
	longitud = lista_pos.cont;
	return longitud;
}

int dame_posX(tListaPosiciones lista_pos, int i) {
	int posX;
	posX = lista_pos.lista[i].posx;
	return posX;
}

int dame_posY(tListaPosiciones lista_pos, int i) {
	int posY;
	posY = lista_pos.lista[i].posy;
	return posY;
}




