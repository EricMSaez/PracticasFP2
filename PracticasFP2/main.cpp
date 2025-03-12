#include "allHeaders.h"
using namespace std;

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	tListaUndo listaUndo;
	int fila, columna;
	

	inicializar(juego);


	if (cargar_juego(juego)) {
		mostrar_cabecera();
		mostrar_juego_consola(juego.tableroJuego);
		pedir_pos(fila, columna); //Pide la posicion al jugador y la guarda
		inicializar_listaPosiciones(listaPos);
		while (!esta_terminado(juego)) { //Si fila = -1 y columna = -1, el juego termina
			juega()
		}
		mostrar_resultado(juego);

	}
	else cout << "Error. No se ha podido cargar el archivo";

}


void inicio_juego(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) {
	inicializar_listaPosiciones(listaPos);
	inicializar(listaUndo);
	if (!cargar_juego(juego)) {
		cout << "Error de lectura de archivo.";
	}
	else ()
}

void juega(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) {
	int fila, columna;
	mostrar_cabecera();
	mostrar_juego_consola(juego.tableroJuego);
	pedir_pos(fila, columna);
	if (fila == -1 && columna == -1); //Llamada  a terminar juego
	else if (fila == -2 && columna == -2) marcar_celda(juego);
	else if (fila == -3 && columna == -3) undoJugada(juego, listaPos);
	else juega(juego, fila, columna, listaPos);
}

void terminar_juego(juego);

void marcar_celda(tJuego& juego) {
	int fila, columna;
	cout << "MARCAR/DESMARCAR mina:" << endl;
	pedir_pos(fila, columna);
	marcar_desmarcar(juego, fila, columna);
}

void undoJugada(tJuego& juego, tListaPosiciones listaPos);
