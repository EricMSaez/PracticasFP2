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
	tPosicion* lista;
	int cont;
	int capacidad;
} tListaPosiciones;


//Declaracion de las funciones

void inicializar(tListaPosiciones& lista_pos);

int longitud(const tListaPosiciones& lista_pos);

int dame_posX(const tListaPosiciones& lista_pos, const int& i);

int dame_posY(const tListaPosiciones& lista_pos, const int& i);

void insertar_final(tListaPosiciones& lista_pos, const int& x, const int& y);

void destruye(tListaPosiciones& lista_pos);

#endif