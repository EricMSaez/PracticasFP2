#ifndef listaPosiciones_h //Proteccion de inclusiones duplicadas
#define listaPosiciones_h


#include <iostream>
using namespace std;


//Constantes
 
const int MAX_LISTA = 500;	//Tamaño de la lista de posiciones


//Declaracion de tipos

typedef struct {
	int posx;
	int posy;
} tPosicion;

typedef struct {
	tPosicion lista[MAX_LISTA];
	int cont;
} tListaPosiciones;


//Declaracion de las funciones

void inicializar(tListaPosiciones& lista_pos);

int longitud(tListaPosiciones lista_pos);

int dame_posX(tListaPosiciones lista_pos, int i);

int dame_posY(tListaPosiciones lista_pos, int i);

void insertar_final(tListaPosiciones& lista_pos, int x, int y);

#endif