#include "allHeaders.h"
#include "main.h"
using namespace std;

int main() {
	cout << "Ole Ole" << endl;
	tJuego juego;
	tListaPosiciones listaPos;
	tListaUndo listaUndo;
	inicio_juego(juego, listaPos, listaUndo);
}


void inicio_juego(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) { //Inicializa el juego y carga el archivo de datos del tablero
	inicializar(listaPos); //Llamada a inicializar de listaPosiciones.h
	inicializar(listaUndo); //Llamada a inicializar de listaUndo.h

	if (!cargar_juego(juego)) { //Comprueba si se ha podido leer el fichero

		cout << "Error de lectura de archivo."; //En caso de que no se haya podido, imprime en pantalla un error de lectura
	}
	else juega(juego, listaPos, listaUndo); //En caso de haber leido el fichero y cargado sus valores, llama a juega de main.h
}

void juega(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo) { //Pide la columna a jugar, y detecta que accion se quiere llevar a cabo
	int fila, columna;
	fila = 0; //Inicializamos el valor de la variable fila a 0
	columna = 0; //Inicializamos el valor de la variable columna a 0
	//Comprueba que el juego no haya terminado y que no se haya introducido -1, -1
	while (!esta_completo(juego) && !mina_explotada(juego) && !(fila==-1 && columna == -1)) { //Llamadas a esta_completo y mina_explotada de juego.h
		
		//Llamada a funciones para mostrar en consola el juego
		mostrar_cabecera(); //Llamada a mostrar_cabecera de inputOutput.h
		mostrar_juego_consola(juego.tableroJuego); //Llamada a mostrar_juego_consola de inputOutput.h
		cout << "Llevas " << dame_num_jugadas(juego) << " jugadas." << endl << endl; //Llamada a dame_num_jugadas de juego.h

		pedir_pos(fila, columna);
		if (fila == -5 && columna == -5) { //Caso 1: Valor introducido no valido
			cout << "Posicion no valida." << endl;
		}

		if (fila == -3 && columna == -3) { //Caso 2: Introducido (-3,-3). Se realiza un undo de la ultima jugada 
			undoJugada(juego, listaUndo);
		}

		if (fila == -2 && columna == -2) { //Caso 3: Introducido (-2,-2). Se marca/desmarca una celda
			marcarDesmarcar(juego); //Llama a marcarDesmarcar de main.h
		}

		if (fila >= 0 && columna >= 0) { //Caso 4: La celda seleccionada es un numero valido
			if (es_valida(juego.tableroJuego, fila, columna)) { //Comprueba si la celda seleccionada es valida
				juega(juego, fila, columna, listaPos); //En ese caso, llama a juega de juego.h con la celda seleccionada
			}
			else cout << "Posicion no valida." << endl; //En caso de no ser valida. Imprime un mensaje de error
		}
	}
	terminar_juego(juego); //Cuando se detecte una de las condiciones de finalizacion del juego, llama a terminar_juego de main.h
}




void terminar_juego(tJuego juego) { //Muestra el tablero final y el resultado de la partida
	mostrar_juego_consola(juego.tableroJuego); //Llamada a mostrar_juego_consola de inputOutput.h
	mostrar_resultado(juego); //Llamada a mostrar_resultado de inputOutput.h

}

void marcarDesmarcar(tJuego& juego) {	//Pide posicion de una celda y la marca/desmarca 
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

int esNumero(string entrada) {
	bool esNum = true;
	int contador=1;
	int resultado;
	int longitud = entrada.length();
	if (entrada[0] != '-' && !isdigit(entrada[0])) esNum = false;
	else {
		while (esNum && contador < longitud) {
			if (!isdigit(entrada[contador])) esNum = false;
			contador++;
		}
	}

	if (!esNum) {
		resultado = -5;
	}
	else {
		resultado = stoi(entrada);
	}
	return resultado;
}
