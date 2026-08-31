#include "Funciones.h"


int main() {
    ArbolBinarioBusqueda ABB;
    construir(ABB);

    int arr[]={9,4,1,6,14,11,16,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    cargarDatos(ABB, arr, size);


    imprimirPorNiveles(ABB);
    return 0;
}
