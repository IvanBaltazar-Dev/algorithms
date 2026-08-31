#include "Funciones.h"

int main() {
    int matrix[N][2]={
        {80, -4}, {90, -2}, {10, 1}, {20, -3}, {30, 6}, {40, -8}, {50, 5}, {60, 2}, {70, -1}};

    int result = resolverRotacion(matrix, 0, N-1);

    cout << "Posicion inicial original: "<< result << endl;

    int minIndex = -1;
    int maxIndex = -1;

    int resultAcumulacion = resuelveAcumulacion(matrix, 0, N-1, minIndex, maxIndex);

    cout << "Maxima acumulacion de riesgo en un intervalo continuo: " << resultAcumulacion << endl;
    cout << "Desde ";
    for (int i = minIndex; i <= maxIndex; i++) {
        cout << matrix[transformacionIndice(i,result,N)][1] << " ";
    }
    cout << endl;
    return 0;
}
