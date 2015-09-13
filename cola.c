#include "cola.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct nodo {
	void* valor;
	struct nodo* ref;
} nodo_t;

/* Definición del struct cola proporcionado por la cátedra. */

struct cola {
	nodo_t* primero;
	nodo_t* ultimo;
	int tamano;
};

/* Función auxiliar para crear un nuevo nodo */

nodo_t* nodo_crear(void* valor){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (nodo == NULL) {
		return NULL;
	}
	nodo->valor = valor;
	nodo_t* ref = NULL;
	nodo->ref = ref;
	return nodo;
}

/* *****************************************************************
 *                    PRIMITIVAS DE LA COLA
 * *****************************************************************/

cola_t* cola_crear(void) {
	cola_t* cola = malloc(sizeof(cola_t));
	if (cola == NULL) {
		return NULL;
	}
	nodo_t* nodo_1 = NULL;
	nodo_t* nodo_2 = NULL;
	cola->primero = nodo_1;
	cola->ultimo = nodo_2;
	cola->tamano = 0;
	return cola;
}

void cola_destruir(cola_t *cola, void destruir_dato(void*)) {
	if (cola == NULL) {
		return;
	}
	if (cola->primero == NULL){
		free(cola);
		return;
	}
	void* elemento;
	int i;
	for (i=0; i < cola->tamano; i++){
		elemento = cola_desencolar(cola);
		if (destruir_dato != NULL){
			destruir_dato(elemento);	
		}
	}
	free(cola);
}

bool cola_esta_vacia(const cola_t *cola) {
	if (cola->tamano > 0) {
		return false;
	}
	return true;
}

bool cola_encolar(cola_t *cola, void* valor) {
	if (cola == NULL) {
		return false;
	}
	nodo_t* nuevo_nodo = nodo_crear(valor);
	if (cola->tamano == 0){
		cola->primero = nuevo_nodo;
		cola->ultimo = nuevo_nodo;
	} else {
		(cola->ultimo)->ref = nuevo_nodo;
		cola->ultimo = nuevo_nodo; 
	}
	cola->tamano += 1;
	return true;
}

void* cola_ver_primero(const cola_t *cola) {
	if (cola_esta_vacia(cola)) {
		return NULL;
	}
    void* primero = (cola->primero)->valor;
    return primero;
}

void* cola_desencolar(cola_t *cola) {
	if (cola_esta_vacia(cola)) {
		return NULL;
	}
    nodo_t* nodo_aux = NULL;
    void* elemento = (cola->primero)->valor;
    nodo_aux = cola->primero;
	cola->primero = (cola->primero)->ref;
    free(nodo_aux);
	cola->tamano -= 1;
    return elemento;
}

