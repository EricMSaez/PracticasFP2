#include "inputOutput.h"
#include "tablero.h"
#include "juego.h"
#include <iomanip>

#include <iostream>

using namespace std;


const char CHAR_MINA = '*';  // Mina


void mostrar_separador(tTablero tablero);
void mostrar_celda(tTablero tablero, int f, int c);
void color_numero(int numero);

void mostrar_cabecera() {
    cout << "Buscaminas" << endl << "----------" << endl;
}

void pedir_pos(int& fila, int& columna) {
    cout << "Introduce la fila y la columna: ";
    cin >> fila >> columna;
}

void mostrar_resultado(tJuego juego) {
    
    if (mina_explotada(juego)) {
        cout << "Has perdido.";
    }else if (esta_completo(juego)) {
        cout << "Has ganado."; 
    }
}

istream& operator>> (istream& in, tJuego& juego) {

    //ifstream in;
    int nfils, ncols, nMinas, xMina, yMina;

    in >> nfils >> ncols >> nMinas;

    inicializar_juego(juego, nfils, ncols);
    juego.num_minas = nMinas;

    for (int i = 0; i < nMinas; i++) {
        in >> xMina >> yMina;
        poner_mina(juego, xMina, yMina);
    }

    return in;
}

bool cargar_juego(tJuego& juego) {
    bool archivoAbierto = false;
    string nombre;
    cout << "Escribe el nombre del archivo: ";
    cin >> nombre;
    ifstream archivo;

    archivo.open(nombre);
    if (archivo.is_open()) {
        archivoAbierto = true;

        archivo >> juego;
        archivo.close();
    }

    return archivoAbierto;
}

void color_numero(int numero) {
    switch (numero) {
    case 1: cout << BLUE; break;
    case 2: cout << GREEN; break;
    case 3: cout << RED; break;
    case 4: cout << DBLUE; break;
    case 5: cout << DGREEN; break;
    case 6: cout << DRED; break;
    default:
        break;
    }
}


void mostrar_separador(tTablero tablero) {

    int NCOLS = tablero.nCols;
    int NFILS = tablero.nFils;

    cout << "\t -+";
    for (int col = 0; col < NCOLS; ++col) {
        cout << setw(N_HUECOS + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}

void mostrar_celda(tTablero tablero, int fila, int columna) {
    if (!tablero.datos[fila][columna].visible && !tablero.datos[fila][columna].marcada) {
        cout << BG_GRAY << GRAY << N_HUECOS << setfill(' ') << ' ' << RESET;
    }
    else {
        cout << BG_BLACK << BLACK;
        if (!tablero.datos[fila][columna].marcada) {
            if (tablero.datos[fila][columna].estado == MINA) {
                cout << RED << setw(N_HUECOS) << setfill(' ') << CHAR_MINA << RESET;
            }
            else {
                if (tablero.datos[fila][columna].estado == VACIA) {
                    cout << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                }
                else {
                    if (tablero.datos[fila][columna].estado == NUMERO) {
                        int numero = tablero.datos[fila][columna].numero;
                        color_numero(numero);
                        cout << setw(N_HUECOS) << setfill(' ') << numero << RESET;
                    }
                    else {
                        cout << BG_RED << RED << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                    }
                }
            }
        }
        else {
            cout << BG_ORANGE << ORANGE << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
        }
    }
}


void mostrar_juego_consola(tTablero tablero) {

    int NCOLS = tablero.nCols;
    int NFILS = tablero.nFils;
    
    // mostrar el número de jugadas del juego
    
    // mostrar cabecera
    cout << "\t  |";
    for (int col = 0; col < NCOLS; col++) {
        cout << LBLUE << setw(N_HUECOS) << col << RESET << '|';
    }
    cout << endl;

    // mostrar separador
    mostrar_separador(tablero);

    // mostrar tablero
    for (int f = 0; f < NFILS; f++) {
        // mostrar numero de fila
        cout << "\t" << LBLUE << setw(2) << f << RESET << '|';
        // mostrar la fila
        for (int c = 0; c < NCOLS; c++) {
            mostrar_celda(tablero, f, c);
            cout << '|';
        }
        cout << endl;

        mostrar_separador(tablero);
    }
    cout << endl;
}


