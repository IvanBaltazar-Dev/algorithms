#include "Funciones.h"

int main() {



    int matrix[M][N]={{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 1, 2, 2},
{0, 0, 0, 0, 1, 2, 3},
{0, 0, 0, 0, 1, 2, 2},
{0, 0, 0, 0, 1, 1, 1},
{0, 0, 0, 0, 0, 0, 0}};



    int colImpacto;

    int potenciaMax = resuelvePotencia(matrix, M, N, colImpacto);
    int filaImpacto = resuelveFila(matrix, 0, M-1, colImpacto);

    imprimirMatriz(matrix, 0, M-1, N);

    cout << endl;
    cout << "Potencia maxima: " << potenciaMax << endl;
    cout << "Columna del impacto: " << colImpacto << endl;
    cout << "Fila del impacto: " << filaImpacto << endl;


    return 0;
}


