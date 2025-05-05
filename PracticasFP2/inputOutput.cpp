#include "inputOutput.h"
#include "inputOutput.h"

void mostrar_cabecera() {
    cout << "Buscaminas" << endl << "----------" << endl;
}

void pedir_pos(short int& fila,short int& columna) { //Pide la posicion al usuario
    string filaS, columnaS;
    cout << "Introduce la fila y la columna: ";
    cin >> filaS >> columnaS;

    //Llama a esNumero de main.h
    fila = esNumero(filaS);
    columna = esNumero(columnaS);   
}

void mostrar_resultado(const tJuego& juego) { //Muestra el resultado final del juego
    
    if (mina_explotada(juego)) { //Llama a mina_explotada de juego.h 
        cout << "Has perdido.";
    }
    else if (esta_completo(juego)) { //Llama a esta_completo de juego.h
        cout << "Has ganado.";
    }
    else cout << "Has salido del juego."; //Indica si has decidido salir del juego (-1 -1)
}

istream& operator>> (istream& in, tJuego& juego) { //Carga los datos del fichero en el juego

    int nfils, ncols, nMinas, xMina, yMina;

    in >> nfils >> ncols >> nMinas;
    inicializar_juego(juego, nfils, ncols); //Llama a inicializar juego de juego.h
    juego.num_minas = nMinas;

    //Pone las minas en el tablero
    for (int i = 0; i < nMinas; i++) {
        in >> xMina >> yMina;
        poner_mina(juego, xMina, yMina); //Llama a poner_mina de juego.h 
    }
    return in;
}

bool cargar_juego(tJuego& juego) { //Cargar el juego con un archivo dado por el usuario
    bool archivoAbierto = false;
    string nombre;
    mostrar_cabecera();
    cout << "Escribe el nombre del archivo: ";
    cin >> nombre;
    ifstream archivo;

    archivo.open(nombre);
    if (archivo.is_open()) {
        archivoAbierto = true;

        archivo >> juego;   //Sobrecarga del operador ">>" para cargar los datos del fichero en juego
        archivo.close();
    }

    return archivoAbierto;
}

void color_numero(const int& numero) {
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


void mostrar_separador(const tTablero& tablero) {

    int NCOLS = dame_num_columnas(tablero);  
    int NFILS = dame_num_filas(tablero);

    cout << "\t -+";
    for (int col = 0; col < NCOLS; ++col) {
        cout << setw(N_HUECOS + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}

void mostrar_celda(const tTablero& tablero, const int& fila, const int& columna) {
    tCelda celda = dame_celda(tablero, fila, columna);
    if (!es_visible(celda)&& !esta_marcada(celda)) {
        cout << BG_GRAY << GRAY << N_HUECOS << setfill(' ') << ' ' << RESET;
    }
    else {
        cout << BG_BLACK << BLACK;
        if (!esta_marcada(celda)) {
            if (es_mina(celda)) {
                cout << RED << setw(N_HUECOS) << setfill(' ') << CHAR_MINA << RESET;
            }
            else {
                if (esta_vacia(celda)) {
                    cout << setw(N_HUECOS) << setfill(' ') << ' ' << RESET;
                }
                else {
                    if (contiene_numero(celda)) {     
                        int numero = dame_numero(celda);
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


void mostrar_juego_consola(const tTablero& tablero) {

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

bool cargar_juegos(tListaJuegos& lista_juegos) {
    bool cargaArchivo = false;
    string nombre;
    cout << "Nombre del fichero de juegos: ";
    cin >> nombre;
    ifstream archivo;
    archivo.open(nombre);
    int numeroJuegos;

    if (archivo.is_open()) {
        cargaArchivo = true;
        archivo >> numeroJuegos;
        for (int i = 0; i < numeroJuegos; i++) {
            tJuego juego;
            archivo >> juego;
            insertar(lista_juegos, juego);
        }
        
        archivo.close();
    }
    return cargaArchivo;
}

ofstream& operator<< (ofstream& in, const tJuego& juego) { //Guarda los datos del juego en el fichero

    int nfils = dame_num_filas(juego);
    int ncols = dame_num_columnas(juego);
    int nMinas = dame_num_minas(juego);
    int contMinas = 0;

    in << nfils << " " << ncols << endl;
    in << nMinas << endl;

    //Busca en el tablero las celdas que son mina
    while (contMinas != nMinas) {

       for (int i = 0; i < nfils; i++) {   
           for (int j = 0; j < ncols; j++) {

               if (es_mina(dame_celda(juego.tableroJuego, i, j))) { //Si es mina, guarda la posición en el fichero
                   in << i << " " << j << endl;
                   contMinas++;
               }
           }
       }
    }
    
    return in;
}

bool guarda_juegos(tListaJuegos& lista_juegos) {
    
    bool guardaArchivo = false;
    string nombre;
    cout << "Escribe el nombre del archivo: ";
    cin >> nombre;
    ofstream archivo;
    archivo.open(nombre);

    int numeroJuegos = lista_juegos.cont;

    if (archivo.is_open()) {
        guardaArchivo = true;
        archivo << numeroJuegos << endl;

        for (int i = 0; i < numeroJuegos; i++) {
           archivo << lista_juegos.lista[i];  //Sobrecargamos el operador "<<"
        }
        
    }
    archivo.close();

    return guardaArchivo;
}

void mostrar_lista_juegos(tListaJuegos& lista_juegos) {
    bool inter = true;
    int cont = lista_juegos.cont;
    int i = 0;
    while ((i < cont - 1) && inter) {
        inter = false;
        for (int j = cont - 1;j > i;j--) {
            if (lista_juegos.lista[j] < lista_juegos.lista[j - 1]) {
                tJuego tmp;
                tmp = *lista_juegos.lista[j];
                lista_juegos.lista[j] = lista_juegos.lista[j - 1];
                *lista_juegos.lista[j - 1] = tmp;
                inter = true;
            }
        }
        if (inter) {
            i++;
        }
    }
    cout << "Mostrando lista de juegos por orden de dificultad..." << endl;
    for (int a = 0;a < cont;a++) {
        cout << "Juego " << a << ":" << endl;
        cout << "   Dimension: " << dame_num_filas(*lista_juegos.lista[a]) << " x " << dame_num_columnas(*lista_juegos.lista[a]) << endl;
        cout << "   Minas: " << dame_num_minas(*lista_juegos.lista[a]) << endl;
    }
}

bool& operator> (tJuego juego1, tJuego juego2) {
    bool esMenor;
    int difJuego1;
    int difJuego2;
    
    difJuego1 = cargar_juego(juego1);
    difJuego2 = cargar_juego(juego2);

    if (difJuego1 < difJuego2) {
        esMenor = true;
    }
    else {
        esMenor = false;
    }
    return esMenor;
}
