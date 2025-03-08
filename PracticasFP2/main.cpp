#include "allHeaders.h"

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	cargar_juego(juego);
	mostrar_juego_consola(juego.tableroJuego);
}