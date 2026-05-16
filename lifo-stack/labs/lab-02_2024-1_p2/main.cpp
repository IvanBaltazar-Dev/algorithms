#include <cmath>

#include "Funciones.h"

int main() {

    Lista lista{};
    construir(lista);

    cargarLista(lista,"datos.txt");
    imprimir(lista);

    Pila pila{};
    construir(pila);

    solucion(lista,pila);

    imprimir(pila);
    destruir(pila);

    return 0;
}
