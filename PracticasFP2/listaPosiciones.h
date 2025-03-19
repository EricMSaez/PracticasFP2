#ifndef listaPosiciones_h //Proteccion de inclusiones duplicadas
#define listaPosiciones_h

#include <iostream>
using namespace std;

//Definicion de tipos

const int MAX_LISTA = 100; //Variable temporal ¡!

typedef struct {
	int posx;
	int posy;
} tPosicion;
typedef struct {
	tPosicion lista[MAX_LISTA];
	int cont;
} tListaPosiciones;

//Definicion de las funciones
void inicializar_listaPosiciones(tListaPosiciones& lista_pos);

int longitud(tListaPosiciones lista_pos);

int dame_posX(tListaPosiciones lista_pos, int i);

int dame_posY(tListaPosiciones lista_pos, int i);

void insertar_final(tListaPosiciones& lista_pos, int x, int y);

#endif