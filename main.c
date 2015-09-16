#include "cola.h"
#include "testing.h"
#include <stdio.h>

/* ******************************************************************
 *                        PROGRAMA PRINCIPAL
 * *****************************************************************/

int main(void) {
    /* Ejecuta todas las pruebas unitarias. */
    printf("~~~ PRUEBAS ALUMNO ~~~\n");
    pruebas_cola_vacia();
	pruebas_cola_con_elementos();
	pruebas_cola_volumen();
	pruebas_cola_de_pilas();

    return failure_count() > 0;
}
