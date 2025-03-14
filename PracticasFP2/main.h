#ifndef main_h //Proteccion de inclusiones duplicadas
#define main_h

#include <iostream>
using namespace std;

//cuerpo de la cabecera

void marcar_celda(tJuego& juego);

void inicio_juego(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo);

void juega(tJuego& juego, tListaPosiciones& listaPos, tListaUndo& listaUndo);

void marcarDesmarcar(tJuego& juego, tListaPosiciones listaPos);

void terminar_juego(tJuego juego);

#endif
