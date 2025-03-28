#include "juego.h"
#include "tablero.h"
#include "celda.h"
#include "listaPosiciones.h"

void inicializar(tJuego& juego) { //Inicializa el juego a 0
	juego.num_jugadas = 0;
	juego.mina_explotada = false;
	juego.num_minas = 0;
	juego.num_descubiertas = 0;
	inicializar(juego.tableroJuego); //Llamada a funcion inicializar de tablero.h
}

void inicializar_juego(tJuego& juego, int nfils, int ncols) { //Inicializa el juego con el numero de filas y columnas seleccionado
	inicializar(juego); //Llamada a inicializar juego a 0
	inicializar_tablero(juego.tableroJuego, nfils, ncols); //Llamada a inicializar de tablero.h con el numero de filas y columnas seleccionado
};

int dame_num_jugadas(tJuego juego) { //Devuelve el numero de jugadas realizadas
	int num_jugadas = juego.num_jugadas;
	return num_jugadas;
}

int dame_num_filas(tJuego juego) { //Devuelve el numero de filas que tiene el tablero
	int num_filas = juego.tableroJuego.nFils;
	return num_filas;
}

int dame_num_columnas(tJuego juego) { //Devuelve el numero de columnas que tiene el tablero
	int num_columnas = juego.tableroJuego.nCols;
	return num_columnas;
}

int dame_num_minas(tJuego juego) { //Devuelve el numero de minas que tiene el tablero
	int num_minas = juego.num_minas;
	return num_minas;
}

bool contiene_mina(tJuego juego, int fila, int columna) { //Devuelve si la celda de la posicion seleccionada tiene mina
	return es_mina(juego.tableroJuego.datos[fila][columna]); //Llamada a es_mina de celda.h
}

bool es_visible(tJuego juego, int fila, int columna) { //Devuelve si la celda de la posicion seleccionada es visible
	return es_visible(juego.tableroJuego.datos[fila][columna]); //Llamada a es_visible de celda.h
}

bool esta_marcada(tJuego juego, int fila, int columna) { //Devuelve si la celda de la posicion seleccionada esta marcada
	return esta_marcada(juego.tableroJuego.datos[fila][columna]); //Llamada a esta_marcada de celda.h 
}

bool esta_vacia(tJuego juego, int fila, int columna) { //Devuelve si la celda de la posicion seleccionada esta vacia
	return esta_vacia(juego.tableroJuego.datos[fila][columna]); //Llamada a esta_vacia de celda.h
}

bool contiene_numero(tJuego juego, int fila, int columna) { //Devuelve si la celda de la posicion seleccionada tiene numero
	return contiene_numero(juego.tableroJuego.datos[fila][columna]); //Llamada a contiene_numero de celda.h
}

int dame_numero(tJuego juego, int fila, int columna) { //Devuelve el numero de la celda de la posicion seleccionada
	return (juego.tableroJuego.datos[fila][columna].numero); // dame_numero de celda.h
}

bool esta_completo(tJuego juego) {
	bool estaCompleto = false; 
	int numCeldasJugadas = juego.num_descubiertas + juego.num_minas; //Almacena el numero de celdas ya jugadas
	int numCeldasTablero = juego.tableroJuego.nCols * juego.tableroJuego.nFils; //Almacena el numero de celdas totales en el tablero
	if (numCeldasJugadas == numCeldasTablero) estaCompleto = true; //Cambia estaCompleto a true si el numero de celdas jugadas es igual al de celdas totales
	return estaCompleto;
}

bool mina_explotada(tJuego juego) { //Devuelve si ha explotado una mina o no en el juego
	return juego.mina_explotada;
}

void poner_mina(tJuego& juego, int fila, int columna) {
	tCelda celda = dame_celda(juego.tableroJuego, fila, columna);  // Guarda la celda de la posicion (fila x columna) en la variable celda
	tCelda celdaAdyacente;

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si (fila x columna) es una posicion valida

		if (!es_mina(celda)) { // Comprueba si en la posicion (fila x columna) hay mina 

			poner_mina(juego.tableroJuego.datos[fila][columna]); //Pone mina en la celda de la posicion (fila x columna)

			for (int i = fila-1;i <= fila + 1;i++) {		// Bucle que recorre las ocho celdas adyacentes a la seleccionada 
				for (int j = columna - 1; j <= columna + 1;j++) {

					if (i != fila || j != columna) { //Comprueba que la celda seleccionada por el bucle no sea la celda donde se ha colocado la mina

						if (es_valida(juego.tableroJuego, i, j)) { // Comprueba si la posicion seleccionada por el bucle es valida

							celdaAdyacente = dame_celda(juego.tableroJuego, i, j); //Guarda la celda adyacente en la variable celdaAdyacente

							if (contiene_numero(celdaAdyacente)) { //Comprueba si la celda adyacente tiene numero, en tal caso lo aumenta 1
								juego.tableroJuego.datos[i][j].numero++; 
							}
							else if (!es_mina(celdaAdyacente)) { // Comprueba si celda adyacente no hay mina
								poner_numero(juego.tableroJuego.datos[i][j], 1); // En ese caso, cambia el estado de la celda a NUMERO y asigna el valor 1
							}
						}
					}
				}
			}
		}
	}
}

void marcar_desmarcar(tJuego& juego, int fila, int columna) {

	if (es_valida(juego.tableroJuego, fila, columna)) {  // Comprueba si la posicion (fila x columna) es valida

		if (esta_marcada(juego.tableroJuego.datos[fila][columna])) { // Comprueba si la celda de la posicion (fila x columna) esta marcada

			desmarcar_celda(juego.tableroJuego.datos[fila][columna]); // En ese caso, la desmarca
		}
		else marcar_celda(juego.tableroJuego.datos[fila][columna]); // En caso contrario, la marca
	}
}

void ocultar(tJuego& juego, int fila, int columna)	 {

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si la posicion (fila x columna) es valida

		if (es_visible(juego.tableroJuego.datos[fila][columna])) { //Comprueba si la celda en la posicion (fila x columna) esta oculta

			ocultar_celda(juego.tableroJuego.datos[fila][columna]); //En ese caso, la oculta
		}
	}
}

void juega(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos) {
	tCelda celda = juego.tableroJuego.datos[fila][columna]; //Guarda la celda en la variable celda;

	if (es_valida(juego.tableroJuego, fila, columna)) { // Comprueba si la posicion (fila x columna) es valida

		if (!es_visible(celda)) {	//Comprueba si la celda en la posicion (fila x columna) no es visible

			if (!esta_marcada(celda)) {	//Comprueba si la celda en la posicion (fila x columna) no esta marcada

				descubrir_celda(juego.tableroJuego.datos[fila][columna]);	//Descubre la celda en la posicion (fila x columna)
				juego.num_descubiertas++;  //Aumenta el numero de celdas descubiertas
				insertar_final(lista_pos, fila, columna);	//A�ade (fila x columna) a la lista de posiciones

				if (!es_mina(celda) && !contiene_numero(celda)) {	//Compruba si la celda no es una mina y no tiene numero

					for (int i = fila - 1; i <= fila + 1; i++) {	//Recorre las celdas adyacentes

						for (int j = columna - 1; j <= columna + 1; j++) {

							if (i != fila || j != columna) {	//Comprueba que la celda seleccionada por el bucle no es la que se quiere descubrir

								if (!contiene_mina(juego, i, j)) { //Comprueba que la celda anterior no tenga mina
									//juega(juego, i, j, lista_pos);
									descubrir_celda(juego.tableroJuego.datos[fila][columna]);	//Descubre la celda adyacente
								}
							}
						}
					}
				}
				else if (es_mina(celda)) juego.mina_explotada = true;
			}
		}
	}
}
