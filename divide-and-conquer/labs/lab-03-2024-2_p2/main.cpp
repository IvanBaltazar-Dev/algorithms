#include "Funciones.h"

int main() {
    int matrix[N][N]={
        {0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };

    int colMax = -1;
    int filMax = -1;
    int result = resuelveMatrix(matrix, N, N,colMax,filMax);

    cout<<"La maxima pureza de las muestras es: "<< result;
    cout<<" (encontrado en la muestra "<<filMax+1<<", en el estrato "<<colMax+1<<")"<<endl;

    int mayorEstrato = resuelveMayorEstrato(matrix, 0,N-1, N);

    cout<<"Las muestras con mayor cantidad de niveles con minerales son: ";
    imprimeEstratosMaximos(matrix,0,N-1,N,mayorEstrato);
    cout<<"ambos con "<<mayorEstrato<<" estratos de minerales"<<endl;
}


