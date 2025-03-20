#include "allHeaders.h"
using namespace std;

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	tListaUndo listaUndo;
	inicio_juego(juego, listaPos, listaUndo);
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
		cout << "Llevas " << dame_num_jugadas(juego) << " jugadas." << endl << endl;
		pedir_pos(fila, columna);
		if (fila == -1 && columna == -1) terminar_juego(juego);
		else if (fila == -2 && columna == -2) {
			marcarDesmarcar(juego);
			juega(juego, listaPos, listaUndo);
		}
		else if (fila == -3 && columna == -3) {
			undoJugada(juego, listaUndo);
			juega(juego, listaPos, listaUndo);
		}
		else if (es_valida(juego.tableroJuego, fila, columna)) {
			juega(juego, fila, columna, listaPos);
			juego.num_jugadas++;	//Aumenta el contador de jugadas
			insertar_final(listaUndo, listaPos);
			juega(juego, listaPos, listaUndo);
		}
		else {
			cout << endl << "Posicion no valida." << endl;
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

void undoJugada(tJuego& juego, tListaUndo& listaUndo) {
	tListaPosiciones listaPos;
	listaPos = ultimos_movimientos(listaUndo);
	listaUndo.cont--;
	
	for (int i = 0; i < listaPos.cont; i++) {
		int x = dame_posX(listaPos, i);
		int y = dame_posY(listaPos, i);
		ocultar(juego, x, y);
	}
}
