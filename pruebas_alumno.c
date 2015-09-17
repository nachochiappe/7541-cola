#include "cola.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include "pila.h"

#define MAX_VOLUMEN 50000

/* Función auxiliar para destruir los datos de una pila */

void pila_destruir_wrapper(void* pila) {
	pila_destruir((pila_t*) pila);
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_cola_vacia() {
	printf("\nINICIO DE PRUEBAS CON COLA VACIA\n");
	
	/* Declaro las variables a utilizar*/
	cola_t* cola = cola_crear();
	
	/* Inicio de pruebas */
	print_test("Prueba crear cola", cola != NULL);
	print_test("Prueba cola esta vacia despues de crearla", cola_esta_vacia(cola));
	print_test("Prueba ver primero cola vacia", !cola_ver_primero(cola));
	print_test("Prueba desencolar cola vacia", !cola_desencolar(cola));
	
	/* Destruyo la cola */
	cola_destruir(cola, NULL);
	print_test("La cola fue destruida", true);
}

void pruebas_cola_con_elementos() {
	printf("\nINICIO DE PRUEBAS CON COLA CON ELEMENTOS\n");
	
	/* Declaro las variables a utilizar*/
	cola_t* cola = cola_crear();
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	
	/* Inicio de pruebas */
	print_test("Prueba encolar &a", cola_encolar(cola, p_a));
	print_test("Prueba encolar &b", cola_encolar(cola, p_b));
	print_test("Prueba encolar &c", cola_encolar(cola, p_c));
	print_test("Prueba encolar &d", cola_encolar(cola, p_d));
	print_test("Prueba encolar &e", cola_encolar(cola, p_e));
	print_test("Prueba ver primero igual a &a", cola_ver_primero(cola) == p_a);
	print_test("Prueba cola NO esta vacia despues de encolar", !cola_esta_vacia(cola));
	print_test("Prueba desencolar igual a &a", cola_desencolar(cola) == p_a);
	print_test("Prueba desencolar igual a &b", cola_desencolar(cola) == p_b);
	print_test("Prueba desencolar igual a &c", cola_desencolar(cola) == p_c);
	print_test("Prueba desencolar igual a &d", cola_desencolar(cola) == p_d);
	print_test("Prueba desencolar igual a &e", cola_desencolar(cola) == p_e);
	print_test("Prueba cola esta vacia despues de desencolar todos", cola_esta_vacia(cola));
	
	/* Destruyo la cola */
	cola_destruir(cola, NULL);
	print_test("La cola fue destruida", true);
}

void pruebas_cola_volumen() {
	printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");
	
	/* Declaro las variables a utilizar*/
	cola_t* cola = cola_crear();
	int a = 1;
	int* p_a = &a;
	
	/* Inicio de pruebas */
	for (int i = 1; i <= MAX_VOLUMEN; i++) {
		cola_encolar(cola, p_a);
	}
	print_test("Prueba cola NO esta vacia despues de encolar", !cola_esta_vacia(cola));
	
	for (int i = 1; i <= MAX_VOLUMEN; i++) {
		cola_desencolar(cola);
	}
	print_test("Prueba cola esta vacia despues de desencolar todos", cola_esta_vacia(cola));
	
	/* Destruyo la cola */
	cola_destruir(cola, NULL);
	print_test("La cola fue destruida", true);
}

void pruebas_cola_de_pilas() {
	printf("\nINICIO DE PRUEBAS CON COLA DE PILAS\n");
	
	/* Declaro las variables a utilizar*/
	cola_t* cola = cola_crear();
	pila_t* pila = pila_crear();
	pila_t* pila2 = pila_crear();
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	
	/* Inicio de pruebas */
	// Apilo todos los elementos
	pila_apilar(pila, p_a);
	pila_apilar(pila, p_b);
	pila_apilar(pila, p_c);
	pila_apilar(pila2, p_d);
	pila_apilar(pila2, p_e);
	
	// Encolo las pilas
	print_test("Prueba encolar pila 1", cola_encolar(cola, pila));
	print_test("Prueba encolar pila 2", cola_encolar(cola, pila2));
	
	/* Destruyo la cola */
	cola_destruir(cola, pila_destruir_wrapper);
	print_test("La cola fue destruida", true);
}

void pruebas_cola_alumno() {
	pruebas_cola_vacia();
	pruebas_cola_con_elementos();
	pruebas_cola_volumen();
	pruebas_cola_de_pilas();
}
