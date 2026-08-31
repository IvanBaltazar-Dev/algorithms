#include "Funciones.h"

int main() {
    char matrix_c[M][N]={
        {'O', 'O', 'C', 'C', 'A', 'A', 'E', 'E', 'R', 'R', 'R'},
        {'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', 'B', 'B', '\0'},
        {'R', 'R', 'E', 'E', 'C', 'C', 'F', 'F', 'A', 'A', '\0'},
        {'E', 'E', 'F', 'F', 'A', 'A', 'A', 'B', 'B', 'R', 'R'},
        {'C', 'C', 'C', 'A', 'A', 'R', 'R', 'O', 'O', 'E', 'E'},
        {'O', 'O', 'C', 'C', 'A', 'A', 'R', 'R', 'E', 'E', '\0'},
        {'A', 'A', 'F', 'F', 'R', 'R', 'E', 'E', 'O', 'O', '\0'},
        {'E', 'E', 'A', 'A', 'O', 'O', 'B', 'B', 'F', 'F', '\0'}
    };

    resuelveLetras(matrix_c, M, N);

    int matrix[M][P]={
        {1, 2, 3, 2, 1},
        {2, 3, 2, 2, 1},
        {1, 2, 2, 5, 3},
        {2, 5, 3, 3, 1},
        {2, 2, 3, 2, 1},
        {1, 2, 3, 2, 1},
        {3, 5, 2, 1, 1},
        {2, 3, 2, 1, 1}
    };

    resuelveAsientos(matrix, M, P);


    return 0;
}



