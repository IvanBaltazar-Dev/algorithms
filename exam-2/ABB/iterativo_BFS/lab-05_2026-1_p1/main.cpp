#include "Funciones.h"

int main() {

    ArbolBinarioBusqueda ABB{};
    construir(ABB);

    int arr[]={9, 4, 14, 1, 6, 11, 16, 19};
    int size = sizeof(arr)/sizeof(int);
    cargarDatos(ABB,arr,size);

    recorrerPreOrden(ABB); cout << endl;

    zigZagOrder(ABB);

    return 0;
}
