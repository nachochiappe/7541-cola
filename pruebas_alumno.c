#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include "pila.h"

#define MAX_VOLUMEN 1000

/* Función auxiliar para destruir los datos de una pila */

void destruir_dato(void* dato) {
	pila_destruir((pila_t*)dato);
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_cola_alumno() {
	// Prueba crear cola
	cola_t* cola;
	print_test("Prueba crear cola", (cola = cola_crear()));
	
	// Prueba ver primero cola vacía
	print_test("Prueba ver primero cola vacia", (cola_ver_primero(cola) == NULL));
	
	// Prueba cola está vacía después de crearla
	print_test("Prueba cola esta vacia despues de crearla", (cola_esta_vacia(cola) == true));

	// Prueba encolar un elemento
	int a = 1;
	int* p_a = &a;
	print_test("Prueba encolar un elemento", (cola_encolar(cola, p_a) == true));
	
	// Prueba encolar elementos
	// Genero elementos a encolar
	int b = 2, c = 3, d = 4, e = 5;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	// Encolo todos los elementos
	cola_encolar(cola, p_b);
	cola_encolar(cola, p_c);
	cola_encolar(cola, p_d);
	cola_encolar(cola, p_e);
	print_test("Prueba encolar elementos", (cola_ver_primero(cola) == p_a));

	// Prueba desencolar un elemento
	print_test("Prueba desencolar un elemento", (cola_desencolar(cola) == p_a));
	
	// Prueba ver primero cola con elementos
	print_test("Prueba ver primero cola con elementos", (cola_ver_primero(cola) == p_b));
	
	// Prueba desencolar todos los elementos
	void* elemento;
	elemento = cola_desencolar(cola);
	elemento = cola_desencolar(cola);
	elemento = cola_desencolar(cola);
	elemento = cola_desencolar(cola);
	print_test("Prueba desencolar todos los elementos", (elemento == p_e));

	// Prueba cola está vacía después de desencolar todos
	print_test("Prueba cola esta vacia despues de desencolar todos", (cola_esta_vacia(cola) == true));

	// Prueba desencolar cola vacía
	print_test("Prueba desencolar cola vacia", (cola_desencolar(cola) == NULL));

	// Prueba destruir cola
	cola_destruir(cola, NULL);

	// Prueba destruir cola de pilas
	// Genero pila
	pila_t* pila = pila_crear();
	pila_t* pila2 = pila_crear();
	// Apilo todos los elementos
	pila_apilar(pila, p_a);
	pila_apilar(pila, p_b);
	pila_apilar(pila, p_c);
	pila_apilar(pila2, p_d);
	pila_apilar(pila2, p_e);
	// Genero cola nueva
	cola_t* cola2 = cola_crear();
	// Encolo las pilas
	cola_encolar(cola2, pila);
	cola_encolar(cola2, pila2);
	//Destruyo la cola de pilas
	cola_destruir(cola2, (*destruir_dato));
}