#ifndef inputOutput_h //Proteccion de inclusiones duplicadas
#define inputOutput_h

#include "colors.h"
#include <fstream>

const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.

typedef enum { NUMERO, VACIA, MINA } Estado;

typedef struct {
    Estado estado;
    int numero;
    bool marcada;
    bool descubierta;
} tCelda;

const int NFILS = 3;
const int NCOLS = 2;
typedef tCelda Matriz[NFILS][NCOLS];


using namespace std;

//Definición de funciones
void mostrar_juego_consola(const Matriz juego);
void mostrar_cabecera();
void pedir_pos(int fila, int columna);

istream& operator>> (istream& in, tJuego& juego);

bool cargar_juego(const Matriz juego);

#endif