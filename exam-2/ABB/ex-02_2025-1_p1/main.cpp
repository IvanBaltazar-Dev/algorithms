#include "Funciones.h"

int main() {
    int arr[]={-5,1,5,8,12,16,19,22,66};
    int size = sizeof(arr)/sizeof(arr[0]);

    ArbolBinarioBusqueda ABB;
    construir(ABB);


    construirABB(ABB.raiz,arr,0,size-1);

    recorrerPreOrden(ABB);

    return 0;
}
