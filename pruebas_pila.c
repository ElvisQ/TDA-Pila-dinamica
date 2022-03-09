#include "pila.h"
#include "testing.h"
#include <stdio.h>
#include <stdlib.h>
#define TAM_VOLUMEN 10000

static void prueba_con_elemento_nulo(void) {
    pila_t *pila = pila_crear();
    printf("******APILAMIENTO DE ELEMENTO NULO******\n");
    print_test("Apilar el elemento NULL a pila", pila_apilar(pila, NULL));
    print_test("El tope es NULL", pila_ver_tope(pila) == NULL);
    print_test("La pila esta vacia false", !pila_esta_vacia(pila));
    print_test("Se puede desapilar el elemento NULL", pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}

static void prueba_pila_vacia(void) {
    printf("******PILAS VACIAS******\n");
    pila_t *pila = pila_crear();
    print_test("La Pila esta vacia true", pila_esta_vacia(pila));
    print_test("El tope de la pila vacia es NULL",pila_ver_tope(pila) == NULL);
    print_test("Desapilar el elemento a una pila vacia es NULL",pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}

static void prueba_pila_con_enteros(void) {
    printf("******APILAMIENTO DE ELEMENTOS DE FORMA MANUAL******\n");
    pila_t *pila = pila_crear();
    int valores[] = {3,5,8,13};
    int i = 0;
    print_test("Apilar el elemento 3 a pila",pila_apilar(pila, &valores[i]));
    print_test("Ahora el tope es 3",pila_ver_tope(pila) == &valores[i]);
    i++;
    print_test("Apilar el elemento 5 a pila",pila_apilar(pila, &valores[i]));
    print_test("El tope es 5", pila_ver_tope(pila) == &valores[i]);
    i++;
    print_test("Apilar el elemento 8 a pila",pila_apilar(pila, &valores[i]));
    print_test("El tope es 8", pila_ver_tope(pila) == &valores[i]);
    i++;
    print_test("Apilar el elemento 13 a pila",pila_apilar(pila, &valores[i]));
    print_test("El tope es 13",pila_ver_tope(pila) == &valores[i]);
    
    printf("******DESAPILAMIENTO DE ELEMENTOS******\n");

    print_test("Desapilar elemento 13 de la pila",pila_desapilar(pila) == &valores[i]);
    i--;
    print_test("Ahora el tope es 8", pila_ver_tope(pila) == &valores[i]);
    print_test("Desapilar elemento 8 de la pila",pila_desapilar(pila) == &valores[i]);
    i--;
    print_test("Ahora el tope es 5",pila_ver_tope(pila) == &valores[i]);
    print_test("Desapilar elemento 5 de la pila",pila_desapilar(pila) == &valores[i]);
    i--;
    print_test("Ahora el tope es 3",pila_ver_tope(pila) == &valores[i]);
    print_test("Desapilar elemento 3 de la pila",pila_desapilar(pila) == &valores[i]);

    print_test("La Pila esta vacia true", pila_esta_vacia(pila));
    print_test("El tope de la pila vacia es NULL",pila_ver_tope(pila) == NULL);
    print_test("Desapilar el elemento a una pila vacia es NULL",pila_desapilar(pila) == NULL);
    pila_destruir(pila);
}  

static void pruebas_con_caracteres(void){
    printf("******PRUEBA CON CARACTERES******\n");
    pila_t *pila= pila_crear();
    char caracteres[5]={'a','b','c','d'};
    int j;
    bool num_apilado_ok = true;
    bool tope_ok = true;
    printf("******APILAR CARACTERES******\n");
    for (j = 0; j < 4; j++) {
        num_apilado_ok &= pila_apilar(pila, &caracteres[j]);
        tope_ok &= (pila_ver_tope(pila) == &caracteres[j]);
    }
    print_test("Se lograron apilar todos los elementos", num_apilado_ok);
    print_test("Todos los topes coinciden", tope_ok);
    
    printf("******DESAPILAR CARACTERES******");
    bool desapilado_ok = true;
    while (!pila_esta_vacia(pila)) {
        tope_ok &= (pila_ver_tope(pila) == &caracteres[j-1]);
        desapilado_ok &= (pila_desapilar(pila) == &caracteres[j-1]);
        j--;
    }
    print_test("Se lograron desapilar todos los elementos", desapilado_ok);
    print_test("Todos los topes conciden", tope_ok);
    print_test("La pila esta vacia", pila_esta_vacia(pila));
    pila_destruir(pila);
}

static void prueba_de_volumen(){
    printf("*******PRUEBA DE VOLUMEN*******\n");

    int* arreglo_din = malloc(TAM_VOLUMEN * sizeof(int));
    for (int i = 0; i < TAM_VOLUMEN; i++) {
        arreglo_din[i] =  i;
    }
    pila_t *pila = pila_crear();
    bool num_apilado_ok = true;
    bool tope_ok = true;
    printf("APILAR VOLUMEN\n");
    print_test("La pila fue creada true", pila != NULL);
    print_test("La pila esta vacia true", pila_esta_vacia(pila));
    int i;
    for (i = 0; i < TAM_VOLUMEN; i++) {
        num_apilado_ok &= pila_apilar(pila,&arreglo_din[i]);
        tope_ok &= (pila_ver_tope(pila) == &arreglo_din[i]);
    }

    print_test("Se lograron apilar todos los numeros", num_apilado_ok);
    print_test("Todos los topes coincidieron", tope_ok);
    print_test("El tope es el numero 10000", pila_ver_tope(pila));
    printf("DESAPILAR VOLUMEN\n");
    bool desapilado_ok= true;
    while (!pila_esta_vacia(pila)) {
        tope_ok &= (pila_ver_tope(pila) == &arreglo_din[i-1]);
        desapilado_ok &= (pila_desapilar(pila) == &arreglo_din[i-1]);
		i --;
	}
    print_test("Se lograron desapilar todos los elementos", desapilado_ok);
    print_test("Todos los topes conciden", tope_ok);
    print_test("La pila esta vacia", pila_esta_vacia(pila));
    free(arreglo_din);
    pila_destruir(pila);
}

void pruebas_pila_estudiante() {
    prueba_pila_vacia();
    prueba_con_elemento_nulo();
    prueba_pila_con_enteros();
    pruebas_con_caracteres();
    prueba_de_volumen();
}
/*
 * Función main() que llama a la función de pruebas.
 */

#ifndef CORRECTOR  // Para que no dé conflicto con el main() del corrector.

int main(void) {
    pruebas_pila_estudiante();
    return failure_count() > 0;  // Indica si falló alguna prueba.
}

#endif
