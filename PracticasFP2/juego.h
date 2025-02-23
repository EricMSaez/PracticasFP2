#include <iostream>
#include "tablero.h" //Incluimos el header "tablero.h" para poder usar tTablero
using namespace std;

typedef struct {
	tTablero tablero;
	int num_jugadas;
	bool mina_explotada;
	int num_minas;
	int num_descubiertas;
} tJuego;