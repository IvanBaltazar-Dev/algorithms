//
// Created by Administrador on 20/06/2026.
//

#include "Funciones.h"

int resolverRotacion(int matrix[8][2], int inicioFila, int finFila) {
    if (inicioFila > finFila) return -1;
    if (inicioFila == finFila) return inicioFila;

    int mitad = inicioFila + (finFila - inicioFila)/2;

    if (matrix[mitad][0] > matrix[finFila][0]) { //ASCENDENTE, esta a la DERECHA
        return resolverRotacion(matrix, mitad+1, finFila);
    }else {
        return resolverRotacion(matrix, inicioFila, mitad);
    }
}

int transformacionIndice(int indice,int posInicio, int total) {
    return ((indice+posInicio) % total);
}

int resuelveAcumulacion(int matrix[N][2], int inicioFila, int finFila, int &minIndex,int &maxIndex) {
    if (inicioFila == finFila){
        minIndex = inicioFila;
        maxIndex = finFila;
        return matrix[transformacionIndice(inicioFila,2,N)][1];
    }
    int mitad = inicioFila + (finFila-inicioFila)/2;

    int inicioIzquierda,finIzquierda;
    int inicioDerecha,finDerecha;
    int inicioCruzado = mitad;
    int finCruzado = mitad+1;

    int maxIzquierda = resuelveAcumulacion(matrix,inicioFila,mitad,inicioIzquierda,finIzquierda);
    int maxDerecha = resuelveAcumulacion(matrix,mitad+1,finFila,inicioDerecha,finDerecha);
    int maxCruzado = sumaCruzada(matrix,inicioFila,mitad,finFila,inicioCruzado,finCruzado);

    int resultFinal = mayorTres(maxIzquierda,maxDerecha,maxCruzado);

    if (resultFinal == maxIzquierda) {
        minIndex = inicioIzquierda;
        maxIndex = finIzquierda;
    }
    if (resultFinal == maxDerecha) {
        minIndex = inicioDerecha;
        maxIndex = finDerecha;
    }
    if (resultFinal == maxCruzado) {
        minIndex = inicioCruzado;
        maxIndex = finCruzado;
    }

    return resultFinal;

}

int sumaCruzada(int matrix[N][2], int inicioFila,int mitad,int finFila,int &inicioCruzado,int &finCruzado) {
    int suma = 0;
    int mejorIzq = matrix[transformacionIndice(mitad,2,N)][1];
    for (int i = mitad; i >= inicioFila; i--) {
        suma += matrix[transformacionIndice(i,2,N)][1];
        if (suma > mejorIzq) {
            inicioCruzado = i;
            mejorIzq = suma;
        }
    }
    suma = 0;
    int mejorDerecha = matrix[transformacionIndice(mitad+1,2,N)][1];
    for (int i = mitad+1; i <= finFila; i++) {
        suma += matrix[transformacionIndice(i,2,N)][1];
        if (suma > mejorDerecha) {
            finCruzado = i;
            mejorDerecha = suma;
        }
    }

    return mejorIzq + mejorDerecha;
}
int mayor(int a, int b) {
    if (a > b) return a;
    return b;
}
int mayorTres(int a,int b,int c) {
    return mayor(mayor(a,b),c);
}