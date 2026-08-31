#include "Funciones.h"

int main() {
    int arr[]{1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    Cola cola{};
    construir(cola);
    cargarDatos(arr,size,cola);

    imprimir(cola);

    int k = 3;

    invertirColaN(cola, k);

    imprimir(cola);

    return 0;
}
