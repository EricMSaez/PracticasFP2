#include "allHeaders.h"
using namespace std;

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	int fila, columna;
	

	inicializar(juego);


	if (cargar_juego(juego)) {
		mostrar_cabecera();
		mostrar_juego_consola(juego.tableroJuego);
		pedir_pos(fila, columna); //Pide la posicion al jugador y la guarda
		inicializar_listaPosiciones(listaPos);
		while (fila != -1 && columna != -1) { //Si fila = -1 y columna = -1, el juego termina

			if (fila == -2 && columna == -2) { //Si fila = -2 y columna = -2, se marca la celda que indique el jugador  
				marcar_celda(juego);
			}

			else if (fila == -3 && columna == -3) { //Si fila = -3 y columna = -3, se realiza "undo"

			}
			else {
				juega(juego, fila, columna, listaPos);
				mostrar_juego_consola(juego.tableroJuego);
			}
			pedir_pos(fila, columna);
		}
		mostrar_resultado(juego);

	}
	else cout << "Error. No se ha podido cargar el archivo";

}

void marcar_celda(tJuego& juego) {
	int fila, columna;
	cout << "MARCAR/DESMARCAR mina:" << endl;
	pedir_pos(fila, columna);
	marcar_desmarcar(juego, fila, columna);
	mostrar_juego_consola(juego.tableroJuego);
}

void inicio_juego(tJuego& juego, tListaPosiciones& listaPos) {
	inicializar_listaPosiciones(listaPos);
	if (!cargar_juego(juego)) {
		cout << "Error de lectura de archivo."
	}
}

void juega(tJuego& juego, tListaPosiciones listaPos) {
	int fila, columna;
	if (!esta_terminado(juego)) {

		mostrar_cabecera();
		mostrar_juego_consola(juego.tableroJuego);
		pedir_pos(fila, columna);
		juega(juego, fila, columna, listaPos);
	}

}