#include "Funciones.h"
#define N 6
int main() {
    int arr[N]={5,3,4,2,1};

    Pila pila{};
    construir(pila);

    solucion(arr,N,pila);

    destruir(pila);

    return 0;
}