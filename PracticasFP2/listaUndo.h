#ifndef listaUndo_h //Proteccion de inclusiones duplicadas
#define listaUndo_h

#include "tablero.h"
#include "listaPosiciones.h" //Incluimos el header "listaPosiciones.h" para poder usar tListaPosiciones
#include <iostream>
using namespace std;


//Constantes

const int MAX_UNDO = 10; //Numero de veces seguidas que la funcion "undo" se puede utilizar


//Declaracion de tipos

typedef struct {
	tListaPosiciones* lista[MAX_UNDO];
	int cont;
} tListaUndo;


//Declaración de las funciones

void inicializar(tListaUndo& lista_undo);

void insertar_final(tListaUndo& lista_undo, tListaPosiciones& lista_pos);

tListaPosiciones ultimos_movimientos(tListaUndo lista_undo);

void destruye(tListaUndo& lista_undo);

void eliminar_ultimo(tListaUndo& lista_undo);

#endif

