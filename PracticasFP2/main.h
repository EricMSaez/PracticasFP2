#ifndef main_h //Proteccion de inclusiones duplicadas
#define main_h


#include "juego.h"	//Incluimos el header "juego.h" para poder usar tJuego
#include "listaPosiciones.h"
#include "listaUndo.h"
#include <iostream>
#include <string>
using namespace std;


//Declaracion de las funciones

void marcarDesmarcar(tJuego& juego);

void inicio_juego(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo);

void juega(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo);

void terminar_juego(tJuego juego);

void undoJugada(tJuego& juego, tListaUndo& listaUndo);

int esNumero(string entrada);

#endif
