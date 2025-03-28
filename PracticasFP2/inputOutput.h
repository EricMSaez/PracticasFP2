#pragma once


#include "colors.h"
#include "inputOutput.h"
#include "tablero.h"
#include "main.h"
#include <iomanip>
#include <fstream>
#include <iostream>

using namespace std;
const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.

using namespace std;

void mostrar_cabecera();
void pedir_pos(int& fila, int& columna);
void mostrar_resultado(tJuego juego);
void mostrar_juego_consola(tTablero tablero);
bool cargar_juego(tJuego& juego);
