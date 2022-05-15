# TDA-Pila-dinamica

El trabajo realizado es el de una implementación de pila dinámica (es decir que pueda crecer o reducirse según la cantidad de elementos) que contenga punteros genéricos (void*).

En el archivo pila.h  están definidas las primitivas , con su correspondiente documentación. Todas las primitivas tienen que funcionar en tiempo constante.

Hay que escribir el archivo pila.c, con la implementación de la estructura de la pila y de cada una de las primitivas incluidas en el encabezado. Además de las primitivas, pueden tener funciones auxiliares, de uso interno, que no hace falta que estén declaradas dentro de pila.h. En pila.h se encuentran únicamente las primitivas que el usuario de la pila tiene que conocer.

En el archivo pila.c ya se les sugiere la siguiente estructura para la pila:

struct pila {
    void** datos;
    size_t cantidad;  // Cantidad de elementos almacenados.
    size_t capacidad;  // Capacidad del arreglo 'datos'.
};

El archivo pruebas_pila.c, contine las pruebas unitarias para verificar que la pila funciona correctamente, y que al ejecutarlo puede verificarse que todo funciona bien y no se pierde memoria. El archivo pruebas_pila.c debe contener una función llamada pruebas_pila_estudiante() que ejecute todas las pruebas. Se permite (y recomienda) usar funciones auxiliares.

Las pruebas verifican que:

°Se pueda crear y destruir correctamente la estructura.

°Se puedan apilar elementos, que al desapilarlos se mantenga el invariante de pila.

°Prueba de volumen: Se pueden apilar muchos elementos (1000, 10000 elementos, o el volumen que corresponda): hacer crecer la pila hasta un valor sabido mucho mayor que el tamaño inicial, y desapilar elementos hasta que esté vacía, comprobando que siempre cumpla el invariante. Recordar no apilar siempre el mismo puntero, validar que se cumpla siempre que el tope de la pila sea el correcto paso a paso, y que el nuevo tope después de cada desapilar también sea el correcto.

°El apilamiento del elemento NULL es válido.

°Condición de borde: comprobar que al desapilar hasta que está vacía hace que la pila se comporte como recién creada.

°Condición de borde: las acciones de desapilar y ver_tope en una pila recién creada son inválidas.

°Condición de borde: la acción de esta_vacía en una pila recién creada es verdadero.

°Condición de borde: las acciones de desapilar y ver_tope en una pila a la que se le apiló y desapiló hasta estar vacía son inválidas.


Para compilar y verificar las pruebas:

Compilar todo el código:

 gcc -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror -o pruebas *.c
Verificar que no pierden memoria:

 valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./pruebas
