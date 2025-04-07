#include "celda.h"

void inicializar(tCelda& Celda) { //Inicializa el estado de una celda a su posicion inicial
	Celda.visible = false;
	Celda.estado = VACIA;
	Celda.numero = 0;
	Celda.marcada = false;
}

tEstado dame_estado(const tCelda& Celda) { //Devuelve el estado de una celda
	tEstado estadoCelda;
	estadoCelda = Celda.estado;
	return estadoCelda;
}

int dame_numero(const tCelda& Celda) { //Devuelve el numero de una celda
	int numeroCelda;
	numeroCelda = Celda.numero;
	return numeroCelda;
}

bool es_visible(const tCelda& Celda) {	//Devuelve si una celda es visible o no
	bool visibilidadCelda;
	visibilidadCelda = Celda.visible;
	return visibilidadCelda;

}

bool es_mina(const tCelda& Celda) { //Devuelve si una celda es mina o no
	bool esMina=false;
	if (Celda.estado == MINA) esMina = true;
	return esMina;
}

bool esta_vacia(const tCelda& Celda) { //Devuelve si una celda esta vacia o no 
	bool estaVacia = false;
	if (Celda.estado == VACIA) estaVacia = true;
	return estaVacia;
}

bool contiene_numero(const tCelda& Celda) { //Devuelve si una celda tiene numero o no
	bool contieneNumero = false;
	if (Celda.estado == NUMERO) contieneNumero = true;
	return contieneNumero;
}

bool esta_marcada(const tCelda& Celda) { //Devuelve si una celda esta marcada o no
	bool estaMarcada = false;
	if (Celda.marcada) estaMarcada = true;
	return estaMarcada;
}

void descubrir_celda(tCelda& Celda) { //Cambia una celda a visible 
	Celda.visible = true;
}

void ocultar_celda(tCelda& Celda) { //Cambia una celda a no visible
	Celda.visible = false;
}

void poner_mina(tCelda& Celda) { //Cambia una celda a con mina
	Celda.estado = MINA;
}

void marcar_celda(tCelda& Celda) { //Cambia una celda a marcada
	Celda.marcada = true;
}

void desmarcar_celda(tCelda& Celda) { //Cambia una celda a no marcada
	Celda.marcada = false;
}

void poner_numero(tCelda& Celda, const int& num) { //Asigna a una celda el estado numero y le asigna el numero introducido
	Celda.numero = num;
	Celda.estado = NUMERO;
}