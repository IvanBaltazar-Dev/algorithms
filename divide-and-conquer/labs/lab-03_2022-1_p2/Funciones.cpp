//
// Created by Administrador on 19/06/2026.
//

#include "Funciones.h"

int resuelvePotencia(int matrix[M][N], int fila, int columnas,int &colImpacto) {
    return resuelvePotenciaColumna(matrix, 0, fila-1, columnas, colImpacto);
}

int resuelvePotenciaColumna(int matrix[M][N], int inicioFila,int finFila, int columnas,int &colImpacto) {
    if (inicioFila == finFila) {
        //ESTO HACE PARA CADA FILA
        colImpacto = buscarPicoColumna(matrix, inicioFila, 0, columnas-1);
        if (colImpacto != -1) return matrix[inicioFila][colImpacto];
        return -1;
    }
    int mitad = inicioFila + (finFila-inicioFila)/2;

    int colIzq = -1;
    int colDer = -1;

    int potIzq = resuelvePotenciaColumna(matrix, inicioFila, mitad, columnas, colIzq);
    int potDer = resuelvePotenciaColumna(matrix, mitad+1, finFila, columnas, colDer);

    if (potIzq >= potDer) {
        colImpacto = colIzq;
        return potIzq;
    }else {
        colImpacto = colDer;
        return potDer;
    }
}

int buscarPicoColumna(int matrix[M][N],int inicioFila,int inicio,int fin) {
    if (inicio == fin){
        if (inicio > 0) return inicio;
        return -1;
    }

    int mitad = inicio + (fin-inicio)/2;

    if (matrix[inicioFila][mitad] < matrix[inicioFila][mitad+1]) { //Ascendiente derecha
        return buscarPicoColumna(matrix, inicioFila, mitad+1, fin);
    }else { //Desciende estamos ahí esta a la izquierda
        return buscarPicoColumna(matrix, inicioFila, inicio, mitad);
    }
}

int resuelveFila(int matrix[M][N], int inicioFila, int finFila,int colImpacto) {
    if (inicioFila == finFila) {
        if (matrix[inicioFila][colImpacto] != -1) return inicioFila;
        return -1;
    }
    int mitad = inicioFila + (finFila-inicioFila)/2;

    if (matrix[mitad][colImpacto] < matrix[mitad+1][colImpacto]) { // Ascedente busca DERECHA
        return resuelveFila(matrix, mitad+1, finFila, colImpacto);
    }else { //Estas en el pico o busca IZQUIERDA
        return resuelveFila(matrix, inicioFila, mitad, colImpacto);
    }
}

void imprimirMatriz(int matrix[M][N],int inicioFila, int finFila, int columnas) {
    if (inicioFila == finFila) {
        imprimeFila(matrix, inicioFila, 0, columnas-1);
        cout << endl;
        return;
    }
    int mitad = inicioFila + (finFila - inicioFila)/2;
    imprimirMatriz(matrix, inicioFila, mitad, columnas);
    imprimirMatriz(matrix, mitad+1, finFila, columnas);

}

void imprimeFila(int matrix[M][N],int inicioFila, int inicioColumna, int finColumna) {
    if (inicioColumna == finColumna) {
        cout << matrix[inicioFila][inicioColumna] << ' ';
        return;
    }
    int mitad = inicioColumna + (finColumna-inicioColumna)/2;
    imprimeFila(matrix, inicioFila, inicioColumna, mitad);
    imprimeFila(matrix, inicioFila, mitad+1, finColumna);
}