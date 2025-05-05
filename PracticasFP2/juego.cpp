#include "juego.h"


void inicializar(tJuego& juego) { //Inicializa el juego a 0
	juego.num_jugadas = 0;
	juego.mina_explotada = false;
	juego.num_minas = 0;
	juego.num_descubiertas = 0;
	inicializar(juego.tableroJuego); //Llamada a funcion inicializar de tablero.h
}

void inicializar_juego(tJuego& juego, const int& nfils, const int& ncols) { //Inicializa el juego con el numero de filas y columnas seleccionado
	inicializar(juego); //Llamada a inicializar juego a 0
	inicializar_tablero(juego.tableroJuego, nfils, ncols); //Llamada a inicializar de tablero.h con el numero de filas y columnas seleccionado
};

int dame_num_jugadas(const tJuego& juego) { //Devuelve el numero de jugadas realizadas
	int num_jugadas = juego.num_jugadas;
	return num_jugadas;
}

int dame_num_filas(const tJuego& juego) { //Devuelve el numero de filas que tiene el tablero
	int num_filas = dame_num_filas(juego.tableroJuego);
	return num_filas;
}

int dame_num_columnas(const tJuego& juego) { //Devuelve el numero de columnas que tiene el tablero
	int num_columnas = dame_num_columnas(juego.tableroJuego);
	return num_columnas;
}

int dame_num_minas(const tJuego& juego) { //Devuelve el numero de minas que tiene el tablero
	int num_minas = juego.num_minas;
	return num_minas;
}

bool contiene_mina(const tJuego& juego, const int& fila, const int& columna) { //Devuelve si la celda de la posicion seleccionada tiene mina
	return es_mina(dame_celda(juego.tableroJuego, fila, columna)); //Llamada a es_mina de celda.h
}

bool es_visible(const tJuego& juego, const int& fila, const int& columna) { //Devuelve si la celda de la posicion seleccionada es visible
	return es_visible(dame_celda(juego.tableroJuego, fila, columna)); //Llamada a es_visible de celda.h
}

bool esta_marcada(const tJuego& juego, const int& fila, const int& columna) { //Devuelve si la celda de la posicion seleccionada esta marcada
	return esta_marcada(dame_celda(juego.tableroJuego, fila, columna)); //Llamada a esta_marcada de celda.h 
}

bool esta_vacia(const tJuego& juego, const int& fila, const int& columna) { //Devuelve si la celda de la posicion seleccionada esta vacia
	return esta_vacia(dame_celda(juego.tableroJuego, fila, columna)); //Llamada a esta_vacia de celda.h
}

bool contiene_numero(const tJuego& juego, const int& fila, const int& columna) { //Devuelve si la celda de la posicion seleccionada tiene numero
	return contiene_numero(dame_celda(juego.tableroJuego, fila, columna)); //Llamada a contiene_numero de celda.h
}

int dame_numero(const tJuego& juego, const int& fila, const int& columna) { //Devuelve el numero de la celda de la posicion seleccionada
	return (dame_numero(dame_celda(juego.tableroJuego, fila, columna))); // dame_numero de celda.h
}

bool esta_completo(const tJuego& juego) {
	bool estaCompleto = false;
	int numCeldasJugadas = juego.num_descubiertas + dame_num_minas(juego);
	int numCeldasTablero = dame_num_columnas(juego) * dame_num_filas(juego);
	if (numCeldasJugadas == numCeldasTablero) estaCompleto = true;
	return estaCompleto;
}

bool mina_explotada(const tJuego& juego) {
	return juego.mina_explotada;
}

bool esta_terminado(const tJuego& juego) {
	bool esta_terminado = false;
	int num_celdas = dame_num_filas(juego) * dame_num_columnas(juego) - dame_num_minas(juego); //Guarda en num_celdas el numero de celdas SIN minas
	if (num_celdas == juego.num_descubiertas) esta_terminado = true;
	return esta_terminado;
}

void poner_mina(tJuego& juego, const int& fila, const int& columna) {
	tCelda celda = dame_celda(juego.tableroJuego, fila, columna);

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si (fila x columna) es una posicion valida

		if (!es_mina(celda)) { // Comprueba si en la posicion (fila x columna) hay mina 

			poner_mina(celda); //Pone mina en la celda de la posicion (fila x columna)
			juego.num_minas++;

			for (int i = fila-1;i <= fila + 1;i++) {		// Bucle que recorre las ocho celdas adyacentes a la seleccionada 
				for (int j = columna - 1; j <= columna + 1;j++) {

					if (i != fila || j != columna) { //Comprueba que la celda seleccionada por el bucle no sea la celda donde se ha colocado la mina

						if (es_valida(juego.tableroJuego, i, j)) { // Comprueba si la posicion seleccionada por el bucle es valida

							tCelda celdaAdyacente = dame_celda(juego.tableroJuego, i, j); //Guarda la celda adyacente en la variable celdaAdyacente

							if (contiene_numero(celdaAdyacente)) { //Comprueba si la celda adyacente tiene numero, en tal caso lo aumenta 1
								celdaAdyacente.numero++; 
							}
							else if (!es_mina(celdaAdyacente)) { // Comprueba si celda adyacente no hay mina
								poner_numero(celdaAdyacente, 1); // En ese caso, cambia el estado de la celda a NUMERO y asigna el valor 1
							}
							poner_celda(juego.tableroJuego, i, j, celdaAdyacente);
						}
					}
				}
			}
		}
	}
	poner_celda(juego.tableroJuego,fila,columna,celda);
}

void marcar_desmarcar(tJuego& juego, const int& fila, const int& columna) {

	tCelda celda = dame_celda(juego.tableroJuego, fila, columna);

	if (es_valida(juego.tableroJuego, fila, columna)) {  // Comprueba si la posicion (fila x columna) es valida

		if (esta_marcada(celda)) { // Comprueba si la celda de la posicion (fila x columna) esta marcada

			desmarcar_celda(juego.tableroJuego.datos[fila][columna]); // En ese caso, la desmarca
		}
		else marcar_celda(juego.tableroJuego.datos[fila][columna]); // En caso contrario, la marca
	}
}

void ocultar(tJuego& juego, const int& fila, const int& columna)	 {

	tCelda celda = dame_celda(juego.tableroJuego, fila, columna);

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si la posicion (fila x columna) es valida

		if (es_visible(celda)) { //Comprueba si la celda en la posicion (fila x columna) esta oculta

			ocultar_celda(juego.tableroJuego.datos[fila][columna]); //En ese caso, la oculta
		}
	}
}

void juega(tJuego& juego, const int& fila, const int& columna, tListaPosiciones& lista_pos) {
	tCelda celda = dame_celda(juego.tableroJuego, fila, columna);; //Guarda la celda en la variable celda;

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si la posicion (fila x columna) es valida

		if (!es_visible(celda)) {	//Comprueba si la celda en la posicion (fila x columna) no es visible

			if (!esta_marcada(celda)) {	//Comprueba si la celda en la posicion (fila x columna) no esta marcada

				descubrir_celda(juego.tableroJuego.datos[fila][columna]);	//Descubre la celda en la posicion (fila x columna)
				
				juego.num_descubiertas++;  //Aumenta el numero de celdas descubiertas
				insertar_final(lista_pos, fila, columna);	//Añade (fila x columna) a la lista de posiciones

				if (!es_mina(celda) && !contiene_numero(celda)) {	//Compruba si la celda no es una mina y no tiene numero

					for (short int i = fila - 1; i <= fila + 1; i++) {	//Recorre las celdas adyacentes

						for (short int j = columna - 1; j <= columna + 1; j++) {

							if (i != fila || j != columna) {	//Comprueba que la celda seleccionada por el bucle no es la que se quiere descubrir
								if (es_valida(juego.tableroJuego, i, j) && !es_visible(dame_celda(juego.tableroJuego, i, j))) {
									if (!contiene_mina(juego, i, j)) { //Comprueba que la celda anterior no tenga mina
										juega(juego, i, j, lista_pos);
									}
								}
							}
						}
					}
				}
				else if (es_mina(celda)) juego.mina_explotada = true; //Si la celda seleccionada es una mina, cambia el estado del juego a mina_explotada = true 
			}
		}
	}
}

int calcula_nivel(const tJuego& juego) {
	int nivelJuego;
	int dimJuego = dame_num_filas(juego) * dame_num_columnas(juego); //Calcula las dimensiones del tablero
	nivelJuego = dimJuego / dame_num_minas(juego);	//Lo divide entre el num de minas
	return nivelJuego;	//Devuelve el nivel de dificultad del juego
}

tJuego crear_juego(const int& num_fils, const int& num_cols, const int& num_minas) {
	tJuego juego;
	inicializar_juego(juego, num_fils, num_cols);	//Creamos un juego con el num_fils y num_cols dado
	int fila, columna;
	int i = 0;

	srand(time(NULL)); //Inicializa la semilla una vez para las posiciones aleatorias 

	while (i < num_minas && i<num_fils*num_cols) {

		//Obtenemos una posicion aleatoria con dame_pos_random
		fila = dame_pos_random(num_fils);
		columna = dame_pos_random(num_cols);

		if (!contiene_mina(juego, fila, columna)) {	//Si esa celda no contiene mina, se pone en el tablero 			
			poner_mina(juego, fila, columna);
			i++;
		} 
	}

	return juego;
}

int dame_pos_random(const int& num_max) {
	int num_random;
	num_random = rand() % (num_max-1); //Devuelve un numero entre el 0 y el num_max-1
	return num_random;
}
