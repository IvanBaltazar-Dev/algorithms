#include "Funciones.h"

int main() {

    int matrizReceptor[N][M] = {
        {0,   0,  0,  0, 0,   0,  0},
        {10,  0, 20, 30, 0,  20, 40},
        {0,   0,  0,  0, 0, 100,  0},
        {0,   0,  0,  0, 0,  80,  0},
        {50, 10,  5, 10, 0, 100,  4},
        {100, 0,  0,  0, 0,   0,  0},
        {0,   0,  0,  0, 0,   0,  0}
    };

    solucion(matrizReceptor,N,M);

    return 0;
}
