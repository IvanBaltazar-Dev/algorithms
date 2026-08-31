//
// Created by Administrador on 19/06/2026.
//

#include "Funciones.h"
int resuelveMatrix(int matrix[N][N], int filas, int columnas,int &colMax, int &filMax) {
    return resuelve_columna(matrix, 0, filas-1,columnas,colMax,filMax);
}

int resuelve_columna(int matrix[N][N], int inicioFila, int finFila,int columnas, int &colMax, int &filaMax) {
    if (inicioFila == finFila) {
        filaMax = inicioFila;
        return resuelvePico(matrix, inicioFila, 0, columnas-1,colMax);
    }
    int mitad = inicioFila + (finFila - inicioFila)/2;

    int colMaxIzq = -1;
    int colMaxDer = -1;
    int filMaxIzq = -1;
    int filMaxDer = -1;

    int maxIzq = resuelve_columna(matrix,inicioFila,mitad,columnas,colMaxIzq,filMaxIzq);
    int maxDer = resuelve_columna(matrix,mitad+1,finFila,columnas,colMaxDer,filMaxDer);

    if (maxIzq > maxDer) {
        colMax = colMaxIzq;
        filaMax = filMaxIzq;
        return maxIzq;
    }else {
        colMax = colMaxDer;
        filaMax = filMaxDer;
        return maxDer;
    }
}

int resuelvePico(int matrix[N][N],int fila,int inicioColumna,int finColumna, int &colMax) {
    if (inicioColumna == finColumna) {
        if (matrix[fila][inicioColumna] != 0) {
            colMax = inicioColumna;
            // cout<<"Fila: "<<fila<<" pico es "<<matrix[fila][inicioColumna]<<endl;
            return matrix[fila][inicioColumna];
        }
        return -1;
    }
    int mitad = inicioColumna + (finColumna - inicioColumna)/2;
    if (matrix[fila][mitad] == 0) {
        if (matrix[fila][0]==0) {
            return resuelvePico(matrix,fila,mitad+1,finColumna,colMax);
        }else {
            return resuelvePico(matrix,fila,inicioColumna,mitad-1,colMax);
        }
    }
    if (matrix[fila][mitad] < matrix[fila][mitad+1]) {//ASCENDIENTE DERECHA
        return resuelvePico(matrix,fila,mitad+1,finColumna,colMax);
    }else { //ESTAMOS EN PICO O IZQUIERDA
        return resuelvePico(matrix,fila,inicioColumna,mitad,colMax);
    }
}

int resuelveMayorEstrato(int matrix[N][N], int inicioFila, int finFila, int columnas) {
    if (inicioFila == finFila) {
        return conteoEstrato(matrix,inicioFila,0,columnas-1);
    }
    int mitad = inicioFila + (finFila-inicioFila)/2;


    int maxIzq = resuelveMayorEstrato(matrix,inicioFila,mitad,columnas);
    int maxDer = resuelveMayorEstrato(matrix,mitad+1,finFila,columnas);

    if (maxIzq > maxDer) {
        return maxIzq;
    }else {
        return maxDer;
    }
}

int conteoEstrato(int matrix[N][N],int fila,int inicioColumna,int finColumna) {
    if (inicioColumna == finColumna) {
        if (matrix[fila][inicioColumna] != 0) {
            return 1;
        }
        return 0;
    }
    int mitad = inicioColumna + (finColumna - inicioColumna)/2;

    int izq = conteoEstrato(matrix,fila,inicioColumna,mitad);
    int der = conteoEstrato(matrix,fila,mitad+1,finColumna);

    return izq + der;
}

void imprimeEstratosMaximos(int matrix[N][N],int inicioFila,int finFila,int columnas,int mayorEstrato) {
    if (inicioFila == finFila) {
        if ( int estratoActual = conteoEstrato(matrix,inicioFila,0,columnas-1) == mayorEstrato) {
            cout<<inicioFila+1<<", ";
        }
        return;
    }
    int mitad = inicioFila + (finFila-inicioFila)/2;

    imprimeEstratosMaximos(matrix,inicioFila,mitad,columnas,mayorEstrato);
    imprimeEstratosMaximos(matrix,mitad+1,finFila,columnas,mayorEstrato);
}
