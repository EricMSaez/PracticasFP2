#include "allHeaders.h"
using namespace std;

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	tListaUndo listaUndo;
	inicio_juego(juego,listaPos,listaUndo);
}


void inicio_juego(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) {
	inicializar_listaPosiciones(listaPos);
	inicializar(listaUndo);
	if (!cargar_juego(juego)) {
		cout << "Error de lectura de archivo.";
	}
	else juega(juego, listaPos, listaUndo);
}

void juega(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) {
	int fila, columna;
	if (esta_completo(juego) || mina_explotada(juego)) {
		terminar_juego(juego);
	}
	else {
		mostrar_cabecera();
		mostrar_juego_consola(juego.tableroJuego);
		pedir_pos(fila, columna);
		if (fila == -1 && columna == -1) terminar_juego(juego);
		else if (fila == -2 && columna == -2) {
			marcarDesmarcar(juego);
			juega(juego, listaPos, listaUndo);
		}
		else if (fila == -3 && columna == -3); //undoJugada(juego, listaPos);
		else {
			juega(juego, fila, columna, listaPos);
			juega(juego, listaPos, listaUndo);
		}
	}
}

void terminar_juego(tJuego juego) {
	mostrar_juego_consola(juego.tableroJuego);
	mostrar_resultado(juego);

}

void marcarDesmarcar(tJuego& juego) {
	int fila, columna;
	cout << "MARCAR/DESMARCAR mina:" << endl;
	pedir_pos(fila, columna);
	marcar_desmarcar(juego, fila, columna);
}

void undoJugada(tJuego& juego, tListaPosiciones listaPos) {
	//Completar
}
