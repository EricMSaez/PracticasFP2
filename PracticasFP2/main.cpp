// Eric Madubuogu Saez, Violeta Garcia Fernandez


#include "allHeaders.h"
#include "main.h"

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
	short int fila, columna;
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

		else if (fila == -3 && columna == -3) { //Caso 2: Introducido (-3,-3). Se realiza un undo de la ultima jugada 
			undoJugada(juego, listaUndo);
		}

		else if (fila == -2 && columna == -2) { //Caso 3: Introducido (-2,-2). Se marca/desmarca una celda
			marcarDesmarcar(juego); //Llama a marcarDesmarcar de main.h
		}

		else if (es_valida(juego.tableroJuego, fila, columna)) { //Caso 4: La celda seleccionada es un numero valido //Comprueba si la celda seleccionada es valida
				juega(juego, fila, columna, listaPos); //En ese caso, llama a juega de juego.h con la celda seleccionada
				insertar_final(listaUndo, listaPos); //Inserta la listaPosiciones en la listaUndo
			}
			else cout << "Posicion no valida." << endl; //En caso de no ser valida. Imprime un mensaje de error
	}
	terminar_juego(juego); //Cuando se detecte una de las condiciones de finalizacion del juego, llama a terminar_juego de main.h
}




void terminar_juego(tJuego juego) { //Muestra el tablero final y el resultado de la partida
	mostrar_juego_consola(juego.tableroJuego); //Llamada a mostrar_juego_consola de inputOutput.h
	mostrar_resultado(juego); //Llamada a mostrar_resultado de inputOutput.h

}

void marcarDesmarcar(tJuego& juego) {	//Pide posicion de una celda y la marca/desmarca 
	short int fila, columna;
	cout << "MARCAR/DESMARCAR mina:" << endl; 
	pedir_pos(fila, columna); //Llamada a funcion pedir_pos de main.h
	marcar_desmarcar(juego, fila, columna); //Llamada a marcar_desmarcar de juego.h 
}

void undoJugada(tJuego& juego, tListaUndo& listaUndo) { //Deshace los movimientos almacenados en la ultima lista de posiciones
	tListaPosiciones listaPos;
	listaPos = ultimos_movimientos(listaUndo); //Llama a ultimos_movimientos de listaUndo.h
	listaUndo.cont--;
	
	for (int i = 0; i < listaPos.cont; i++) {  //Recorre todas las jugadas de la lista de posiciones
		int x = dame_posX(listaPos, i); //Llama a dame_posx de listaPosiciones.h para guardar la coordenada x en su variable
		int y = dame_posY(listaPos, i); //Llama a dame_posy de listaPosiciones.h para guardar la coordenada y en su variable
		ocultar(juego, x, y);
	}
}

int esNumero(string entrada) { //Comprueba si el string introducido tiene valores permitidos
	bool esNum = true;
	int contador=1;
	short int resultado;
	int longitud = entrada.length();  //Guarda la longitud del string introducido en la variable longitud
	if (entrada[0] != '-' && !isdigit(entrada[0])) { //Comprueba si el char 0 no es ni un numero ni "-"
		esNum = false; //En ese caso, cambia la variable esNum a false
	}

	if (longitud == 1 && entrada[0]=='-') esNum = false;

	else { 
		while (esNum && contador < longitud) { //Si el char 0 es valido, comprueba que el resto de char sean numeros
			if (!isdigit(entrada[contador])) esNum = false; //Si un char no es un numero, cambia la variable esNum a false
			contador++; //Aumenta el contador de chars comprobados
		}
	}
	if (!esNum) { 
		resultado = -5; //Si el string introducido no es valido, asigna a la variable resultado -5 (numero que indica que ha entrado resultado no valido)
	}
	else {
		resultado = stoi(entrada); //Si el string introducido es valido, asigna a la variable resultado su valor en un int
	}
	return resultado; //Devuelve resultado como variable de saldia
}
