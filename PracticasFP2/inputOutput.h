#pragma once


#include "colors.h"
#include "tablero.h"
#include "juego.h"
#include <fstream>

const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.

using namespace std;


void mostrar_juego_consola(tTablero tablero);

bool cargar_juego(tJuego& juego);