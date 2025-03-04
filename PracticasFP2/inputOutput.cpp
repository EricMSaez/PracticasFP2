#include "InputOutput.h"
#include "juego.h" //Incluimos el header "juego.h" para poder usar tJuego

#include <iomanip>
#include <iostream>

using namespace std;

const char CHAR_MINA = '*';  // Mina


void mostrar_cabecera() {
    cout << "Buscaminas" << endl << "----------";
}
void pedir_pos(int fila, int columna) {
    cin >> fila >> columna;
}
istream& operator>> (istream& in, tJuego& juego) {
    
    //ifstream in;
    int nfils, ncols, nMinas, xMina, yMina;

    in >> nfils >> ncols;
    in >> nMinas;

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


//Para que se vea bonito:

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

void mostrar_separador(const Matriz juego) {
    cout << "\t -+";
    for (int col = 0; col < NCOLS; ++col) {
        cout << setw(N_HUECOS + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}

void mostrar_celda(const Matriz juego, int fila, int columna) {
    if (!juego[fila][columna].visible && !juego[fila][columna].marcada) {
        cout << BG_GRAY << GRAY << N_HUECOS << setfill(' ') << ' ' << RESET;
    }
    else {
        cout << BG_BLACK << BLACK;
        if (!juego[fila][columna].marcada) {
            if (juego[fila][columna].estado == MINA) {
                cout << RED << setw(N_HUECOS) << setfill(' ') << CHAR_MINA << RESET;
            }
            else {
                if (juego[fila][columna].estado == VACIA) {
                    cout << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                }
                else {
                    if (juego[fila][columna].estado == NUMERO) {
                        int numero = juego[fila][columna].numero;
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

void mostrar_juego_consola(const Matriz juego) {

    // mostrar el numero de jugadas del juego

    // mostrar cabecera
    cout << "\t  |";
    for (int col = 0; col < NCOLS; col++) {
        cout << LBLUE << setw(N_HUECOS) << col << RESET << '|';
    }
    cout << endl;

    // mostrar separador
    mostrar_separador(juego);

    // mostrar tablero
    for (int f = 0; f < NFILS; f++) {
        // mostrar numero de fila
        cout << "\t" << LBLUE << setw(2) << f << RESET << '|';
        // mostrar la fila
        for (int c = 0; c < NCOLS; c++) {
            mostrar_celda(juego, f, c);
            cout << '|';
        }
        cout << endl;

        mostrar_separador(juego);
    }
    cout << endl;
}

