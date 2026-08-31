//
// Created by Administrador on 19/06/2026.
//

#include "Funciones.h"

void resuelveLetras(char arr[M][N], int filas, int columnas) {
    resuelveColumnas(arr, 0, filas-1, columnas);
};

void resuelveColumnas(char arr[M][N], int inicioFila,int finFila, int columnas) {
    if (inicioFila == finFila) {
        buscaLetra(arr, inicioFila, 0, columnas-1);
        return;
    }
    int mitad = inicioFila + (finFila - inicioFila)/2;

    resuelveColumnas(arr, inicioFila, mitad, columnas);
    resuelveColumnas(arr, mitad+1, finFila, columnas);
}

void buscaLetra(char arr[M][N], int fila,int inicioColumna, int finColumna) {
    if (inicioColumna > finColumna) {
        return;
    }
    if (inicioColumna == finColumna) {
        if (arr[fila][inicioColumna] != '\0') {
            cout<<"La fila "<<fila+1<<" tiene un "<<arr[fila][inicioColumna]<<" adicional."<<endl;
            return;
        }
        return;
    }
    int mitad = inicioColumna + (finColumna - inicioColumna)/2;
    if (mitad % 2 == 1) {
        mitad--;
    }
    if (arr[fila][mitad] == arr[fila][mitad+1]) { //indices pares DERECHA
        return buscaLetra(arr, fila, mitad+2, finColumna);
    }else {
        return buscaLetra(arr, fila, inicioColumna, mitad);
    }
}

void resuelveAsientos(int matrix[M][P], int filas, int columnas) {
    resuelveColumnas(matrix, 0, filas-1, columnas);
}

void resuelveColumnas(int matrix[M][P], int inicioFila, int finFila, int columnas) {
    if (inicioFila == finFila) {
        int result = resuelvePico(matrix, inicioFila, 0, columnas-1);
        cout<< "En la fila " << inicioFila+1;
        cout<< ", el pasajero del asiento del asiento "<<result+1;
        cout<<" tiene el bocadito mas caro que sus 2 vecinos "<<endl;
        return;
    }
    int mitad = inicioFila + (finFila - inicioFila)/2;
    resuelveColumnas(matrix, inicioFila, mitad, columnas);
    resuelveColumnas(matrix, mitad+1, finFila, columnas );
};

int resuelvePico(int matrix[M][P],int fila,int inicioColumna,int finColumna) {
    if (inicioColumna == finColumna) {
        return inicioColumna;
    }
    int mitad = inicioColumna + (finColumna - inicioColumna)/2;

    if (matrix[fila][mitad] < matrix[fila][mitad+1]) { //Ascedente DERECHA
        return resuelvePico(matrix, fila, mitad+1, finColumna);
    }else { //Estamos en el pico o a la izquierda
        return resuelvePico(matrix, fila, inicioColumna, mitad);
    }
}
