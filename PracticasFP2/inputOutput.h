#ifndef inputOutput_h  //Proteccion de inclusiones duplicadas
#define inputOutput_h


#include "colors.h"
#include "tablero.h" //Incluimos el header "tablero.h" para poder usar tTablero
#include "juego.h"	 //Incluimos el header "juego.h" para poder usar tJuego
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;


//Constantes
const int N_HUECOS = 2; // Huecos a dejar en el formato de las celdas.


//Declaracion de las funciones

void mostrar_cabecera();

void pedir_pos(int& fila, int& columna);

void mostrar_resultado(tJuego juego);

void mostrar_juego_consola(tTablero tablero);

bool cargar_juego(tJuego& juego);

#endif