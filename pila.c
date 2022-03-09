#include "pila.h"
#include <stdlib.h>
#define CAPACIDAD_INICIAL_PILA 10
#define REDIMENSION_LLENO 2
#define REDIMENSION_REDUCCION 4

/* Definición del struct pila proporcionado por la cátedra.
 */
struct pila {
    void **datos;
    size_t cantidad;   // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

/* *****************************************************************
 *                    PRIMITIVAS DE LA PILA
 * *****************************************************************/

// ...

pila_t *pila_crear(void) {
    pila_t *pila = malloc(sizeof(pila_t));
    if (pila == NULL) return NULL;
    pila->datos = malloc((CAPACIDAD_INICIAL_PILA) * sizeof(void*));
    if (pila->datos == NULL) {
        free(pila);
        return NULL;
    }
    pila->capacidad = CAPACIDAD_INICIAL_PILA;
    pila->cantidad = 0;
    return pila; 
}

bool redimensionar(pila_t *pila, size_t nuevo_tam){
    void** nuevos_datos = realloc(pila->datos, (nuevo_tam * sizeof(void*)));
    if (nuevos_datos == NULL) {
        return NULL;
    }   
    pila->datos = nuevos_datos;
    pila->capacidad = nuevo_tam;
    return true;
}

void pila_destruir(pila_t *pila) {
    free(pila->datos);
    free(pila);
}

bool pila_esta_vacia(const pila_t *pila) {
    if (pila->cantidad == 0) {
        return true;
    }
    return false;
}

bool pila_apilar(pila_t *pila, void* valor) {
    if (pila->cantidad == pila->capacidad) {
        if (!redimensionar(pila, (REDIMENSION_LLENO * pila->capacidad))) {
            return false;
        }
    }
    pila->datos[pila->cantidad] = valor;
    pila->cantidad ++;
    return true;
}

void *pila_ver_tope(const pila_t *pila) {
    if (pila_esta_vacia(pila)) {
        return NULL;
    }
    return pila->datos[pila->cantidad - 1];
}

void *pila_desapilar(pila_t *pila) {
    if (pila_esta_vacia(pila)) {
        return NULL;
	}
    if (pila->cantidad == (pila->capacidad)/REDIMENSION_REDUCCION) {
        if(!redimensionar(pila, ((pila->capacidad) / REDIMENSION_REDUCCION))) {
            return NULL;
        }   
    }
    void* tope = pila->datos[pila->cantidad - 1];
    pila->cantidad --;
    return tope;
}
