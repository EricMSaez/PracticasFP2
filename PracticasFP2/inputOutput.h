#ifndef inputOutput_h  //Proteccion de inclusiones duplicadas
#define inputOutput_h


#include "colors.h"
#include "tablero.h" //Incluimos el header "tablero.h" para poder usar tTablero
#include "juego.h"	 //Incluimos el header "juego.h" para poder usar tJuego
#include "main.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;


//Constantes

const int N_HUECOS = 2; // Huecos a dejar en el formato de las celdas.
const char CHAR_MINA = '*';  // Mina


//Declaracion de las funciones

void mostrar_cabecera();

void pedir_pos(short int& fila,short int& columna);

void mostrar_resultado(tJuego juego);

bool cargar_juego(tJuego& juego);

void color_numero(int numero);

void mostrar_separador(tTablero tablero);

void mostrar_celda(tTablero tablero, int f, int c);

void mostrar_juego_consola(tTablero tablero);
#endif