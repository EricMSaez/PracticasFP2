#include "allHeaders.h"

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	cargar_juego(juego);
	mostrar_juego_consola(juego.tableroJuego);
	poner_mina(juego.tableroJuego.datos[1][1]);
	mostrar_juego_consola(juego.tableroJuego);

}