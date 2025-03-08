#include "celda.h"

void inicializar(tCelda& Celda) {
	Celda.visible = false;
	Celda.estado = VACIA;
	Celda.numero = 0;
	Celda.marcada = false;
}

tEstado dame_estado(tCelda Celda) {
	tEstado estadoCelda;
	estadoCelda = Celda.estado;
	return estadoCelda;
}

int dame_numero(tCelda Celda) {
	int numeroCelda;
	numeroCelda = Celda.numero;
	return numeroCelda;
}

bool es_visible(tCelda Celda) {
	bool visibilidadCelda;
	visibilidadCelda = Celda.visible;
	return visibilidadCelda;

}

bool es_mina(tCelda Celda) {
	bool esMina=false;
	if (Celda.estado == MINA) esMina = true;
	return esMina;
}

bool esta_vacia(tCelda Celda) {
	bool estaVacia = false;
	if (Celda.estado == VACIA) estaVacia = true;
	return estaVacia;
}

bool contiene_numero(tCelda Celda) {
	bool contieneNumero = false;
	if (Celda.estado == NUMERO) contieneNumero = true;
	return contieneNumero;
}

bool esta_marcada(tCelda Celda) {
	bool estaMarcada = false;
	if (Celda.marcada) estaMarcada = true;
	return estaMarcada;
}

void descubrir_celda(tCelda& Celda) {
	Celda.visible = true;
}

void ocultar_celda(tCelda& Celda) {
	Celda.visible = false;
}

void poner_mina(tCelda& Celda) {
	Celda.estado = MINA;
}

void marcar_celda(tCelda& Celda) {
	Celda.marcada = true;
}

void desmarcar_celda(tCelda& Celda) {
	Celda.marcada = false;
}

void poner_numero(tCelda& Celda, int num) {
	Celda.numero = num;
	Celda.estado = NUMERO;
}