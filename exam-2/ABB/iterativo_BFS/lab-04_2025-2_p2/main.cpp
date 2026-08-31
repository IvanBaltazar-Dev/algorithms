#include "Funciones.h"

int main() {
    ArbolBinarioBusqueda arbol{};
    construir(arbol);

    int arr[]= {3, 5, 7, 2, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);

    Cola cola{};
    construir(cola);
    for(int i = 0; i < size; i++) {
        insertarMiniHeap(arbol,cola,arr[i]);
    }

    imprimirPorNivel(arbol);

    return 0;
}
