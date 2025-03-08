#include "allHeaders.h"

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	cargar_juego(juego);
	inicializar_listaPosiciones(listaPos);
	mostrar_juego_consola(juego.tableroJuego);
	juega(juego, 0, 3, listaPos);
	cout << endl;
	mostrar_juego_consola(juego.tableroJuego);
}