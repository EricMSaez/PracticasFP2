#include <iostream>
using namespace std;

const int MAX_LISTA = 10; //Variable temporal ¡!

typedef struct {
	int posx;
	int posy;
} tPosicion;
typedef struct {
	tPosicion lista[MAX_LISTA];
	int cont;
} tListaPosiciones;