#ifndef celda_h //Proteccion de inclusiones duplicadas
#define celda_h

#include <iostream>
using namespace std;


// Declaracion de tipos

typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
	bool visible;
	tEstado estado;
	int numero;
	bool marcada;
} tCelda;



// Declaración de las funciones

void inicializar(tCelda& Celda);

tEstado dame_estado(tCelda Celda);

int dame_numero(tCelda Celda);

bool es_visible(tCelda Celda);

bool es_mina(tCelda Celda);

bool esta_vacia(tCelda Celda);

bool contiene_numero(tCelda Celda);

bool esta_marcada(tCelda Celda);

void descubrir_celda(tCelda& Celda);

void ocultar_celda(tCelda& Celda);

void poner_mina(tCelda& Celda);

void marcar_celda(tCelda& Celda);

void desmarcar_celda(tCelda& celda);

void poner_numero(tCelda& Celda, int num);


#endif