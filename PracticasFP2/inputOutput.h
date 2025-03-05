#ifndef inputOutput_h //Proteccion de inclusiones duplicadas
#define inputOutput_h

#include "colors.h"
#include "juego.h"
#include "celda.h"
#include <fstream>
using namespace std;

const int N_HUECOS = 2; // huecos a dejar en el formato de las celdas.
/*
typedef enum { NUMERO, VACIA, MINA } Estado;

typedef struct {
    Estado estado;
    int numero;
    bool marcada;
    bool descubierta;
} tCelda;
*/
const int NFILS = 10;
const int NCOLS = 10;
typedef tCelda Matriz[NFILS][NCOLS];


//Definición de funciones
void mostrar_juego_consola(Matriz juego);
void mostrar_cabecera();
void pedir_pos(int fila, int columna);

void mostrar_separador(Matriz juego);
void mostrar_celda(Matriz juego, int f, int c);
void color_numero(int numero);

istream& operator>> (istream& in, tJuego& juego);
bool cargar_juego(tJuego& juego);


#endif